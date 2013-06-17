Components.utils.import("resource://debug/debug.jsm");
Components.utils.import("resource://fileutils/picker.jsm");
Components.utils.import("resource://fileutils/process.jsm");

const prefs = Components.classes["@mozilla.org/preferences-service;1"]
		.getService(Components.interfaces.nsIPrefService)
		.getBranch("extensions.DiagMsgMon.pref.adb.");

const nsILocalFile = Components.interfaces.nsILocalFile;

function isADB(aFile)
{
	try {
		if(execFile(aFile, ["version"])==0)
			return true;
	} catch (e) {
		printd("Exception : " + e);
	}

	alert("Failed to set \"adb\"");

	return false;
}

function pickADB()
{
	var aFile = pickExecFile("Please find \"adb\"");

	if(aFile && isADB(aFile)) {
		prefs.setComplexValue("path", nsILocalFile, aFile);
	}
}

