"use strict"

const Cu=Components.utils;
const Ci=Components.interfaces;
const Cc=Components.classes;

Cu.import("resource://debug/debug.jsm");
Cu.import("resource://gre/modules/XPCOMUtils.jsm");
Cu.import("resource://fileutils/process.jsm");
Cu.import("resource://logfox/prefs.jsm");

const nsILocalFile = Ci.nsILocalFile;
const nsISocketTransportService = Cc["@mozilla.org/network/socket-transport-service;1"]
		.getService(Ci.nsISocketTransportService);
const nsITransport = Ci.nsITransport;
const nsIScriptableInputStream = Ci.nsIScriptableInputStream;
const nsIInputStreamPump = Ci.nsIInputStreamPump;

var adbAlive = false;
function adb() {
	this.transport = null;
	return this;
}

(function(){
	function window()
	{
		const nsIWindowMediator = Ci.nsIWindowMediator;
		const wm =  Cc["@mozilla.org/appshell/window-mediator;1"]
				.getService(nsIWindowMediator);
		return wm.getMostRecentWindow(null);
	}

	adb.prototype = {
		classID : Components.ID("{75b3607d-142e-4e34-883a-9cb91a7bcfb7}"),
		QueryInterface : XPCOMUtils.generateQI([Ci.adbI]),

		OB_TOPIC : "adb-state",
		OB_STATE_CONNECTED : "connected",
		OB_STATE_DISCONNECTED : "disconnected",

		isAlive : function /*$adb_isAlive*/() {
			return adbAlive;
		},
		exec : function /*$adb_exec*/(blocked) {
			if(typeof(blocked)!="boolean") // Type of first parameter must be in boolean - execution in blocked or not
				throw Components.results.NS_ERROR_NO_INTERFACE;
			if(arguments.length<=1)	// Subcommand for adb must be written from 2nd parameter.
				throw Components.results.NS_ERROR_XPC_NOT_ENOUGH_ARGS;

			var args = Array.prototype.slice.call(arguments);
			args.shift();
			try {
				prefs.getComplexValue("path", Ci.nsILocalFile)
				execFile(prefs.getComplexValue("path", Ci.nsILocalFile), args, blocked);
			} catch(e if e.result===Components.results.NS_ERROR_FILE_UNRECOGNIZED_PATH) {
				printd("NS_ERROR_FILE_UNRECOGNIZED_PATH : Check ADB Path");
				window().openDialog("chrome://logfox/content/conf.xul", "Configuration", "chrome");
			} catch(e) {
				printd("Unknown Exception Occured....");
			}
		},
		startServer : function /*$adb_startServer*/() {
			if(!this.isAlive()){
				this.exec(true, ["start-server"]);
			}
		},
		killServer : function /*$adb_killServer*/() {
			this.exec(true, ["kill-server"]);
		},
		getDeviceList : function /*$adb_getDeviceList*/() {
			this.startServer();
			var adbBridge = Cc["@gh4ck3r.com/adbBridge;1"]
							.getService(Ci.adbBridgeI);
			var resp = adbBridge.exec("host:devices");
			var hosts = [];

			var host;
			var regEx = /^(\w+)\s+device/gmy;		// flag 'y' is important
			while(host = regEx.exec(resp)){
				hosts.push(host[1]);
				host = null;
			}

			return hosts;
		},
		getDeviceCnt : function /*$adb_getDeviceCnt*/() {
			return this.getDeviceList().length;
		},
		getDeviceId : function /*$adb_getDeviceId*/(idx) {
			var deviceList = this.getDeviceList();
			return deviceList.length>idx?deviceList[idx]:undefined;
		}
	}
)();
const NSGetFactory = XPCOMUtils.generateNSGetFactory([adb]);

(function(){
	var adbWatcher;
	var adbWatcherTimer = Cc["@mozilla.org/timer;1"]
			.createInstance(Ci.nsITimer);
	const nsIObserverService = Cc["@mozilla.org/observer-service;1"]
			.getService(Ci.nsIObserverService);

	function broadcastObserver(aStatusCode){
		nsIObserverService
			.notifyObservers(null, adb.prototype.OB_TOPIC, aStatusCode);
	}
	function checkADB(){
		adbWatcherTimer.initWithCallback({
			notify : function(timer){
				adbWatcher = Cc["@gh4ck3r.com/adbBridge;1"]
									.getService(Ci.adbBridgeI)
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
		}, 500, Ci.nsITimer.TYPE_ONE_SHOT);
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

