Components.utils.import("resource://debug/debug.jsm");
Components.utils.import("resource://gre/modules/XPCOMUtils.jsm");
Components.utils.import("resource://fileutils/process.jsm");
Components.utils.import("resource://diag/prefs.jsm");

const Cc = Components.classes;
const Ci = Components.interfaces;
const Cr = Components.results;

const nsISocketTransportService = Cc["@mozilla.org/network/socket-transport-service;1"]
		.getService(Ci.nsISocketTransportService);
const nsISocketTransport		= Ci.nsISocketTransport;
const nsITransport				= Ci.nsITransport;
const nsIInputStream			= Ci.nsIInputStream;
const nsIScriptableInputStream	= Ci.nsIScriptableInputStream;
const nsIOutputStream			= Ci.nsIOutputStream;
const nsIInputStreamPump		= Ci.nsIInputStreamPump;

function newTransport() {
	return nsISocketTransportService
			.createTransport(null,0,prefs.getCharPref("host"),prefs.getIntPref("port"),null);
}

function data2Packet(data) {
	var cmdPrefix = data.length.toString(16);
	var padLen = 4-cmdPrefix.length;
	ASSERT(padLen<4);
	var cmdPacket = "";
	while(padLen<4&&padLen--) cmdPacket+='0';
	cmdPacket+=cmdPrefix+data;
	return cmdPacket;
}

function checkRespCode(is, cmd) {
	var respCode;
	try {
		respCode = is.readBytes(4);
	} catch (e) {
		printd("Exception on response checking.");
		printd("filename : " +e.filename+", line : " + e.lineNumber + " : " + e.name + " : " + e.message);
		throw e;
	}

	switch(respCode) {
		case "OKAY":
			return true;
		case "FAIL":
			printd(cmd + " failed...");
			throw Cr.NS_ERROR_FAILURE;
		default:
			throw Cr.NS_ERROR_UNEXPECTED;
	}

	return false;
}

function determineProtocol(data) {
	var protocolList = ["host:", "shell:"];
	
	for(var i in protocolList){
		var protocol = protocolList[i];
		if(protocol == data.substr(0, protocol.length))
			return protocol;
	}
	return undefined;
}

function doProcotolDefault(is, os, data) {
	var packet = data2Packet(data);
	os.write(packet, packet.length);

	var respData="";
	if(checkRespCode(is, data)){
		var lengthStr = is.readBytes(4);
		var length = parseInt(lengthStr, 16);

		if(length >= 0 && length == is.available()){
			respData = is.readBytes(length);
		} else {
			respData = lengthStr;
			while(is.available())
				respData += is.readBytes(is.available());
		}
	}

	try {
		ASSERT(is.available()==0,"Some data remained... : " + is.readBytes(is.available()));
	} catch(e if e == Cr.NS_BASE_STREAM_CLOSED){
		// Excerpt : https://developer.mozilla.org/en/nsIInputStream#available%28%29
		// Note: Some nsIInputStream implementations automatically close() when eof is reached; some do not.
		throw e;
	} finally {
		return respData;
	}

}

function doProtocolShell(targetPacket, is, os, data) {
	os.write(targetPacket, targetPacket.length);

	ASSERT(checkRespCode(is, data), "\""+targetPacket+"\" is not working properly");

	if(data == "shell:")
		throw Cr.NS_ERROR_NOT_IMPLEMENTED;

	var packet = data2Packet(data);
	os.write(packet, packet.length);

	var respData="";
	try {
		if(checkRespCode(is, data)){
			try {
				// NS_BASE_STREAM_CLOSED exception will be occured on 'is.available()' method.
				//  "shell:" protocol will be closed automatically when it prints out all results.
				while(1)
					if(is.available())
						respData += is.readBytes(is.available());
			} catch(e if e == Cr.NS_BASE_STREAM_CLOSED){
				// Excerpt : https://developer.mozilla.org/en/nsIInputStream#available%28%29
				// Note: Some nsIInputStream implementations automatically close() when eof is reached; some do not.
				throw e;
			}
		}
	} finally {
		return respData;
	}
}

var adbBridgeSync = function() {
	var tp = null;
	var _is = null;
	var is = null;
	var os = null;
	var targetPacket=data2Packet("host:transport-any");

	const syncStreamFlags = nsITransport.OPEN_BLOCKING | nsITransport.OPEN_UNBUFFERED;

	function connect() {
		if(tp != null)
			throw Cr.NS_ERROR_ALREADY_INITIALIZED;

		tp = newTransport();
		_is = tp.openInputStream(syncStreamFlags,0,0);
		is = Cc["@mozilla.org/scriptableinputstream;1"]
				.createInstance(nsIScriptableInputStream);
		is.init(_is);
		os = tp.openOutputStream(syncStreamFlags,0,0);
	}

	connect();
	this.reconnect = function() {
		if(!tp)
			throw Cr.NS_ERROR_NOT_INITIALIZED;

		this.disconnect();
		connect();
	}

	this.disconnect = function() {
		os && os.close();
		is && is.close();
		_is && _is.close();
		tp && tp.close(Cr.NS_OK);
		tp = _is = is = os = null;
	};
	this.isAlive = function() {
		if(!tp || !tp.isAlive()) {
		}
		return tp && tp.isAlive();
	};
	this.setTargetPacket = function(androidSerial) {
		targetPacket = data2Packet("host:transport"+(androidSerial?(":"+androidSerial):("-any")));
	};
	this.doProtocol = function(data) {
		if(!tp)
			throw Cr.NS_ERROR_NOT_INITIALIZED;
		else if(!this.isAlive())
			this.reconnect();

		try {
			switch(determineProtocol(data)) {
				case "shell:":
					return doProtocolShell(targetPacket, is, os, data);
				default:
					return doProcotolDefault(is, os, data);
			}
		} catch(e if e == Cr.NS_BASE_STREAM_CLOSED){
			// Excerpt : https://developer.mozilla.org/en/nsIInputStream#available%28%29
			// Note: Some nsIInputStream implementations automatically close() when eof is reached; some do not.
			this.disconnect();
		}
	};
};
(function(){
	adbBridgeSync.prototype.isConnected = function() {
		return this.isAlive();
	};
	adbBridgeSync.prototype.setTarget = function(androidSerial) {
		this.setTargetPacket(androidSerial);
		return this;
	};
	adbBridgeSync.prototype.exec = function(cmd) {
		return this.doProtocol(cmd);
	};
	adbBridgeSync.prototype.close = function() {
		this.disconnect();
	};
})();

var adbBridgeAsync = function() {
	var tp = null;
	var _is = null;
	var is = null;
	var os = null;

	throw Cr.NS_ERROR_NOT_IMPLEMENTED;

//		var instream	= transport.openInputStream(nsITransport.OPEN_UNBUFFERED,0,0);
//		var outstream	= transport.openOutputStream(nsITransport.OPEN_BLOCKING,0,0);
//
//		var pump = Cc["@mozilla.org/network/input-stream-pump;1"]
//						.createInstance(nsIInputStreamPump);
//		pump.init(instream, -1, -1, 0, 0, false);
//		pump.asyncRead(this.defaultListener, outstream);
//
//		return {
//			transport : transport,
//			outstream : outstream,
//			isAlive : function() {
//				return this.transport && this.transport.isAlive();
//			},
//			exec : function(cmd) {
//				var packet = cmd2Packet(cmd);
//				this.outstream.write(packet, packet.length);
//				return this;
//			}
//		};

};
(function() {
	adbBridgeAsync.prototype.isConnected = function(){
		throw Cr.NS_ERROR_NOT_IMPLEMENTED;
	};
	adbBridgeAsync.prototype.exec = function(cmd){
		throw Cr.NS_ERROR_NOT_IMPLEMENTED;
	};
	adbBridgeAsync.prototype.getResult = function(cmd){
		throw Cr.NS_ERROR_NOT_IMPLEMENTED;
	};
	adbBridgeAsync.prototype.getData = function(cmd){
		throw Cr.NS_ERROR_NOT_IMPLEMENTED;
	};
	adbBridgeAsync.prototype.close = function(){
		throw Cr.NS_ERROR_NOT_IMPLEMENTED;
	};
})();

var adbBridge = function() {
	this.defaultListener = {};
	this.defaultListener.instream = null;
	this.defaultListener.onStartRequest = function(aRequest, outstream) {
		try{
			this.asyncListener.onStartRequest(aRequest, outstream);
		} catch (e if e.result==Cr.NS_ERROR_XPC_JSOBJECT_HAS_NO_FUNCTION_NAMED) {
			printd("Got exception...");
		} catch (e) {
			printd("Unknown exception occured.");
			printd("filename : " +e.filename+", line : " + e.lineNumber + " : " + e.name + " : " + e.message);
			throw e;
		}
	};
	this.defaultListener.onStopRequest = function(aRequest, outstream, aStatusCode) {
		try {
			this.asyncListener.onStopRequest(aRequest, outstream, aStatusCode);
		} catch (e if e.result==Cr.NS_ERROR_XPC_JSOBJECT_HAS_NO_FUNCTION_NAMED) {
		} catch (e) {
			printd("Unknown exception occured.");
			printd("filename : " +e.filename+", line : " + e.lineNumber + " : " + e.name + " : " + e.message);
			throw e;
		}
		if(this.instream) this.instream.close(0);
		outstream.close(0);
	};
	this.defaultListener.onDataAvailable = function(aRequest, outstream, inputStream, offset, count){
		if(this.asyncListener && this.asyncListener.onDataAvailable){
			this.asyncListener.onDataAvailable(aRequest, outstream, inputStream, offset, count);
			return;
		}
		if(this.instream === null){
			this.instream = Cc["@mozilla.org/scriptableinputstream;1"]
					.createInstance(nsIScriptableInputStream);
			this.instream.init(inputStream);
		}

		if(offset != 0 || count < 4)
			throw Cr.NS_ERROR_UNEXPECTED;

		var resultCode = this.instream.readBytes(4);
		count -= resultCode.length;

		switch(resultCode) {
			case "OKAY":
				var data = this.instream.readBytes(count)
				printd("Data : " + data);
				break;
			case "FAIL":
				throw Cr.NS_ERROR_FAILURE;
				break;
			default:
				throw Cr.NS_ERROR_UNEXPECTED;
				break;
		}	
	};

	return this;
};

(function(){
	adbBridge.prototype.classID = Components.ID("{7191b9cb-ebf7-4b2e-8af5-133f5a1778aa}");
	adbBridge.prototype.QueryInterface = XPCOMUtils.generateQI([Ci.adbBridgeI]);

	adbBridge.prototype.openSync = function() {
		return new adbBridgeSync();
	};

	adbBridge.prototype.openAsync = function(callback) {
		return {
			isConnected : function(){},
			exec : function(cmd) {},
			getResult : function(cmd) {},
			getData : function(cmd) {},
			close : function(){},
		};
		return new adbBridgeAsync();
	};

})();

const NSGetFactory = XPCOMUtils.generateNSGetFactory([adbBridge]);
