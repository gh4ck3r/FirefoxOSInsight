Components.utils.import("resource://debug/debug.jsm");
Components.utils.import("resource://gre/modules/XPCOMUtils.jsm");
Components.utils.import("resource://fileutils/process.jsm");
Components.utils.import("resource://diag/prefs.jsm");

const nsILocalFile = Components.interfaces.nsILocalFile;
const nsISocketTransportService = Components.classes["@mozilla.org/network/socket-transport-service;1"]
		.getService(Components.interfaces.nsISocketTransportService);
const nsITransport = Components.interfaces.nsITransport;
const nsIScriptableInputStream = Components.interfaces.nsIScriptableInputStream;
const nsIInputStreamPump = Components.interfaces.nsIInputStreamPump;
function adb() {
	this.transport = null;
	return this;
}

var adbAlive = false;
(function(){
	var adbWatcher;
	var adbWatcherTimer = Components.classes["@mozilla.org/timer;1"]
			.createInstance(Components.interfaces.nsITimer);
	const nsIObserverService = Components.classes["@mozilla.org/observer-service;1"]
			.getService(Components.interfaces.nsIObserverService);
	adb.prototype.OB_TOPIC = "adb-state";
	adb.prototype.OB_STATE_CONNECTED = "connected";
	adb.prototype.OB_STATE_DISCONNECTED = "disconnected";

	function broadcastObserver(aStatusCode){
		nsIObserverService
			.notifyObservers(null, adb.prototype.OB_TOPIC, aStatusCode);
	}
	function checkADB(){
		adbWatcherTimer.initWithCallback({
			notify : function(timer){
				adbWatcher = Components.classes["@gh4ck3r.com/adbBridge;1"]
									.getService(Components.interfaces.adbBridgeI)
									.openAsync({
					onStartRequest : function(){},
					onStopRequest : function(aRequest, outstream, aStatusCode) {
						if(adbAlive)
							broadcastObserver(adb.prototype.OB_STATE_DISCONNECTED);
						checkADB();
					}
				});
				if(adbWatcher.isConnected())
					broadcastObserver(adb.prototype.OB_STATE_CONNECTED);
				else
					checkADB();
			}
		}, 500, Components.interfaces.nsITimer.TYPE_ONE_SHOT);
	}
	checkADB();
	var adbObserver = {
		observe : function(aSubject, aTopic, aData) {
			if(aTopic != adb.prototype.OB_TOPIC)
				throw Components.results.NS_ERROR_UNEXPECTED;

			switch(aData) {
				case adb.prototype.OB_STATE_CONNECTED:
					trace("ADB connected");
					adbAlive = true;
					break;
				case adb.prototype.OB_STATE_DISCONNECTED:
					trace("ADB disconnected");
					adbAlive = false;
					adbWatcher=null;
					break;
				default:
					throw Components.results.NS_ERROR_UNEXPECTED;
					break;
			}
		}
	};
	nsIObserverService.addObserver(adbObserver, adb.prototype.OB_TOPIC, false);
})();

(function(){
	function window()
	{
		const nsIWindowMediator = Components.interfaces.nsIWindowMediator;
		const wm =  Components.classes["@mozilla.org/appshell/window-mediator;1"]
				.getService(nsIWindowMediator);
		return wm.getMostRecentWindow(null);
	}


	adb.prototype.classID = Components.ID("{75b3607d-142e-4e34-883a-9cb91a7bcfb7}");
	adb.prototype.QueryInterface = XPCOMUtils.generateQI([Components.interfaces.adbI]);

	adb.prototype.isAlive = function() {
		return adbAlive;
	};

	adb.prototype.exec = function(blocked) {
		if(typeof(blocked)!="boolean") // Type of first parameter must be in boolean - execution in blocked or not
			throw Components.results.NS_ERROR_NO_INTERFACE;
		if(arguments.length<=1)	// Subcommand for adb must be written from 2nd parameter.
			throw Components.results.NS_ERROR_XPC_NOT_ENOUGH_ARGS;

		var args = Array.prototype.slice.call(arguments);
		args.shift();
		try {
			execFile(prefs.getComplexValue("path", nsILocalFile), args, blocked);
		} catch(e if e.result==Components.results.NS_ERROR_FILE_UNRECOGNIZED_PATH) {
			window().openDialog("chrome://diag/content/conf.xul", "Configuration", "chrome");
		}
	};

	adb.prototype.startServer = function() {
		if(!this.isAlive()){
			this.exec(true, ["start-server"]);
		}
	};
	adb.prototype.killServer = function() {
		this.exec(true, ["kill-server"]);
	};
	adb.prototype.getDeviceList = function() {
		this.startServer();
		var adbBridge = Components.classes["@gh4ck3r.com/adbBridge;1"]
						.getService(Components.interfaces.adbBridgeI);
		var resp = adbBridge.exec("host:devices");
		var hosts = [];

		var host;
		var regEx = /^(\w+)\s+device/gmy;		// flag 'y' is important
		while(host = regEx.exec(resp)){
			hosts.push(host[1]);
			host = null;
		}

		return hosts;
	};
	adb.prototype.getDeviceCnt = function() {
		return this.getDeviceList().length;
	};
	adb.prototype.getDeviceId = function(idx) {
		var deviceList = this.getDeviceList();
		return deviceList.length>idx?deviceList[idx]:undefined;
	};
})();

const NSGetFactory = XPCOMUtils.generateNSGetFactory([adb]);
