const { classes: Cc, interfaces: Ci, utils: Cu } = Components;

Cu.import("resource://debug/debug.jsm");
Cu.import("resource://fileutils/picker.jsm");
Cu.import("resource://fileutils/process.jsm");

const prefs = Cc["@mozilla.org/preferences-service;1"]
    .getService(Ci.nsIPrefService)
    .getBranch("extensions.DiagMsgMon.pref.adb.");

const nsILocalFile = Ci.nsILocalFile;

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

