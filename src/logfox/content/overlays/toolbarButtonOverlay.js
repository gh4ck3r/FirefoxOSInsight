const wm = Components.classes["@mozilla.org/appshell/window-mediator;1"]
				.getService(Components.interfaces.nsIWindowMediator);
const chromeURI = "chrome://logfox/content/logfox.xul";

function toolBarClicked(event) {
	openUILinkIn("chrome://logfox/content/", "tab");
}

function disableChrome() {
	try {
		var navWindow = wm.getMostRecentWindow("navigator:browser");
		var browserWindow = navWindow.XULBrowserWindow;
		if(browserWindow.inContentWhitelist.indexOf(chromeURI) == -1)
			browserWindow.inContentWhitelist.push(chromeURI);
	} catch (e) {
		Components.utils.reportError("Exception thrown during attempt to include extension's URL in inContentWhitelist for hiding chrome. The exception message is as follows:\n" + e.message);
	}
}
disableChrome();
