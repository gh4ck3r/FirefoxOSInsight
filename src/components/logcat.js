Components.utils.import("resource://debug/debug.jsm");
Components.utils.import("resource://gre/modules/XPCOMUtils.jsm");
Components.utils.import("resource://logfox/prefs.jsm");

const nsISocketTransportService = Components.classes["@mozilla.org/network/socket-transport-service;1"]
		.getService(Components.interfaces.nsISocketTransportService);
const nsITransport = Components.interfaces.nsITransport;
const nsIScriptableInputStream = Components.interfaces.nsIScriptableInputStream;
const nsIInputStreamPump = Components.interfaces.nsIInputStreamPump;

function adb_cmd_atom(cmd, expect){
	var cmd_prefix = cmd.length.toString(16);
	var pad_len = 4-cmd_prefix.length;
	ASSERT(pad_len<4);
	while(pad_len<4&&pad_len--) this.cmd+='0';
	this.cmd+=cmd_prefix+cmd;
	this.expect = expect;
}adb_cmd_atom.prototype = {
	cmd : "",
	expect : null,
	result : null,
}

function adb_cmd() {
	this._cmds = arguments;
}adb_cmd.prototype = {
	_idx : 0,
	_cmds : [],

	cmd		: function(){return this._cmds[this._idx].cmd;},

	expect	: function(){return this._cmds[this._idx].expect;},

	set_result	: function(result){this._cmds[this._idx].result = result;},
	get_result	: function(){return this._cmds[this._idx].result;},

	done : function(){return this._idx>=this._cmds.length;},

	proceed : function(){this._idx++;},

	reset : function(){this._idx=0;},
}

var cmd_logcat = new adb_cmd(
//	new adb_cmd_atom("host:transport:LG_ANDROID_M3OPEN_GB_", "OKAY"), 
	new adb_cmd_atom("host:transport-any", "OKAY"), 
	new adb_cmd_atom("shell:export ANDROID_LOG_TAGS=\"\" ; exec logcat -v long", "OKAY")
);

function logcatListener(callback){
	this.callback = callback;
} logcatListener.prototype = {
	callback : null,
	instream : null,
	onStartRequest : function(aRequest, outstream){},
	onStopRequest : function(aRequest, outstream, aStatusCode){
		if(aStatusCode != Components.results.NS_OK)
			this.callback.onError(aStatusCode);
		try{
			if(this.instream)
				this.instream.close(0);
		} catch (e) {
			printd("Exception occured : " + e.name + "(" + e.result + ")" + ": " + e.message);
		}
		try{
			outstream.close(0);
		} catch (e if e.result!=Components.results.NS_ERROR_NOT_INITIALIZED) {
			printd("Exception occured : " + e.name + "(" + e.result + ")" + ": " + e.message);
		}
	},

	onDataAvailable : function(aRequest, outstream, inputStream, offset, count){
		if(this.instream === null){
			this.instream = Components.classes["@mozilla.org/scriptableinputstream;1"]
					.createInstance(nsIScriptableInputStream);
			this.instream.init(inputStream);
		}

		if(!cmd_logcat.done())
		{
			cmd_logcat.set_result(this.instream.readBytes(cmd_logcat.expect().length));
			count-=cmd_logcat.expect().length;

			if(cmd_logcat.get_result() == cmd_logcat.expect()){
				cmd_logcat.proceed();
				if(!cmd_logcat.done()){
					outstream.write(cmd_logcat.cmd(),cmd_logcat.cmd().length);
				}
			} else {
				switch(cmd_logcat.get_result()){
					case "FAIL":
						printd("Command '" + cmd_logcat.cmd() + "' FAILED!!");
						break;
					default:
						printd("Unexpected result : " + cmd_logcat.get_result());
						break;
				}
				while(count>0) {
					if(count>=4) {
						var len = parseInt("0x"+this.instream.readBytes(4), 16);
						printd("Followed : " + this.instream.readBytes(len));
						count -= len;
					} else {
						printd("Followed : " + this.instream.readBytes(count));
						count=0;
					}
				}
				this.instream.close(0);
				return;
			}

			ASSERT(count==0, "FIXME : Some data remained...("+count+" bytes)");
//			ASSERT(count==0, "FIXME : Some data remained...("+count+" bytes) -- " + this.instream.readBytes(count));
			
			return;
		}
		this.callback.onMsg(this.instream, count);
	}
}

function logcat() {
} logcat.prototype = {
	classID: Components.ID("{0616a42f-9dcc-4efb-9a3e-6bc431a0d5d5}"),
	QueryInterface: XPCOMUtils.generateQI([Components.interfaces.adbIlogcat]),
	constructor : function() { },

	transport : null,

	start		: function(callback){
		this.connect();

		// Open in/out streams
		var instream = this.transport.openInputStream(nsITransport.OPEN_UNBUFFERED,0,0);
		var outstream = this.transport.openOutputStream(nsITransport.OPEN_BLOCKING,0,0);

		var pump = Components.classes["@mozilla.org/network/input-stream-pump;1"]
						.createInstance(nsIInputStreamPump);
		pump.init(instream, -1, -1, 0, 0, false);
		pump.asyncRead(new logcatListener(callback), outstream);

		outstream.write(cmd_logcat.cmd(),cmd_logcat.cmd().length);
	},
	stop		: function(){
		this.transport.close(Components.results.NS_OK);
		this.transport = null;
	},
	pause		: function(){printd("logcat : pause");},
	resume		: function(){printd("logcat : resume");},

	/*************************************************************************/
	connect : function() {
		this.transport = nsISocketTransportService
				.createTransport(null,0,prefs.getCharPref("host"),prefs.getIntPref("port"),null);
		cmd_logcat.reset();
	},
	isConnected : function() {
		return this.transport && this.transport.isAlive();
	},
}

const NSGetFactory = XPCOMUtils.generateNSGetFactory([logcat]);
