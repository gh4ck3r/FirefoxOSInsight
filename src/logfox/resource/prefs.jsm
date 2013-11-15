var EXPORTED_SYMBOLS = [
  "prefs"
];

const prefs =  Components.classes["@mozilla.org/preferences-service;1"]
                   .getService(Components.interfaces.nsIPrefService)
                   .getBranch("extensions.DiagMsgMon.pref.adb.");

