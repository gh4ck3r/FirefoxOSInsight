const { classes: Cc, interfaces: Ci, utils: Cu } = Components;
Cu.import("resource://debug/debug.jsm");

/*
	const nsILocalFile = Cc["@mozilla.org/file/local;1"].  
			createInstance(Ci.nsILocalFile);  

	nsILocalFile.initWithFile(aFile);

	if(nsILocalFile.exists() && nsILocalFile.isFile() && nsILocalFile.isExecutable()){
		const process = Cc["@mozilla.org/process/util;1"]
				.createInstance(Ci.nsIProcess);
		process.init(nsILocalFile);

		var args = ["version"];
		process.run(true, args, args.length);	
		if(process.exitValue == 0)
			return true;
	}
*/

//Cu.import("chrome://logfox/content/adb.js");
//var loader = Cc["@mozilla.org/moz/jssubscript-loader;1"]
//                       .getService(Ci.mozIJSSubScriptLoader); 
//loader.loadSubScript("chrome://logfox/content/adb.js");

var gMsgList = document.getElementsByTagName("logfox-msg-list")[0];
var msg_list = [];

function test()
{
	printd("list capacity : " + gMsgList.capacity);
/*
	printd("function test() is invoked");
	try {
		var msgs = [
			"[ 05-11 12:39:25.929   176:0xbc D/MobileDataStateTracker ]",
			"tab\ttab\tnewline\n4space    <b><!></b>android.net.MobileDataStateTracker$MobileDataStateReceiver 335<!> (type=mms,featureId=-1) received ACTION_ANY_DATA_CONNECTION_STATE_CHANGED",
			"2nd line..",
			"",
		];
		parseStream(msgs);
		for(var i in msg_list){
			var msg=msg_list[i];
			if(!msg.msg.length) msg.msg.push("");
			gMsgList.appendMsg(msg);
		}
	} catch(ex) {
		printd("filename : " +ex.filename+", line : " + ex.lineNumber + " : " + ex.name + " : " + ex.message);
	}
*/
}

/*
Cu.import("resource://gre/modules/AddonManager.jsm");
var addonListener = {
	onEnabling: function(addon, needsRestart){},
	onEnabled: function(addon){},
	onDisabling: function(addon, needsRestart){},
	onDisabled: function(addon) {},
	onInstalling: function(addon, needsRestart){},
	onUninstalling: function(addon, needsRestart){},
	onOperationCancelled: function(addon){},
	onPropertyChanged: function(addon, properties){}

	onDisabled: function(addon) {},
	onEnabled: function(addon){},

	onInstalled: function(addon){
		window.openDialog("chrome://logfox/content/conf.xul", "Configuration", "chrome");
	},
	onUninstalled: function(addon){
		printd("onUninstalled");
	},
}
AddonManager.addAddonListener(addonListener);
*/
