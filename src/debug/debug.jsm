var EXPORTED_SYMBOLS = [
	"ASSERT",
	"_invoke_trace_window",
	"printd",
	"trace",
	"printObj",
	"result2str",
	"restartFirefox"
];


var gTraceOnAssert = true;
var _trace_window = null;
const consoleService = Components.classes["@mozilla.org/consoleservice;1"]
							.getService(Components.interfaces.nsIConsoleService);

function _invoke_trace_window()
{
	if(_trace_window && !_trace_window.closed)
		_trace_window.focus();
	else {
		var wm = Components.classes["@mozilla.org/appshell/window-mediator;1"]
					.getService(Components.interfaces.nsIWindowMediator);
		_trace_window = wm.getMostRecentWindow("global:console");
		if(!_trace_window) {
			var parent_window = wm.getMostRecentWindow(null);

			_trace_window = parent_window.open("chrome://console2/content/console2.xul",
					"Error Console",
					"chrome,dialog=yes,centerscreen,titlebar=yes,toolbar=yes,minimizable=yes,close=yes,resizable=yes,dependent=yes,status=yes,fullscreen=yes", null);
		}
	}
}

/**
 * This function provides a simple assertion function for JavaScript.
 * If the condition is true, this function will do nothing.  If the
 * condition is false, then the message will be printed to the console
 * and an alert will appear showing a stack trace, so that the (alpha
 * or nightly) user can file a bug containing it.  For future enhancements, 
 * see bugs 330077 and 330078.
 *
 * To suppress the dialogs, you can run with the environment variable
 * XUL_ASSERT_PROMPT set to 0 (if unset, this defaults to 1).
 *
 * @param condition represents the condition that we're asserting to be
 *                  true when we call this function--should be
 *                  something that can be evaluated as a boolean.
 * @param message   a string to be displayed upon failure of the assertion
 */

function ASSERT(condition, message) {
	if (condition) return;
	if(!_trace_window) _invoke_trace_window();
	var releaseBuild = true;
	var defB = Components.classes["@mozilla.org/preferences-service;1"]
		.getService(Components.interfaces.nsIPrefService)
		.getDefaultBranch(null);
	try {
		switch (defB.getCharPref("app.update.channel")) {
			case "nightly":
				case "beta":
				case "default":
				releaseBuild = false;
		}
	} catch(ex) {}

	var caller = arguments.callee.caller;
	var assertionText = "ASSERT FAILED: " + message + "\n";

	if (releaseBuild) {
		// Just report the error to the console
		//Components.utils.reportError(assertionText);
		var caller			= Components.stack.caller;

		var aSourceName		= caller.filename;
		var aSouceLine		= caller.sourceLine;
		var aLineNumber		= caller.lineNumber;
		var aColumnNumber	= 0;
		var aFlags			= 0;	// error
		var aCategory		= null;

		var scriptError		= Components.classes["@mozilla.org/scripterror;1"]
								.createInstance(Components.interfaces.nsIScriptError);
		scriptError.init(
				(caller.name?caller.name + "() : ":"") + assertionText,
				aSourceName,
				aSouceLine,
				aLineNumber,
				aColumnNumber,
				aFlags,
				aCategory);
		consoleService.logMessage(scriptError);
		return;
	}

	// Otherwise, dump to stdout and launch an assertion failure dialog
	dump(assertionText);

	var stackText = "";
	if (gTraceOnAssert) {
		stackText = "Stack Trace: \n";
		var count = 0;
		while (caller) {
			stackText += count++ + ":" + caller.name + "(";
			for (var i = 0; i < caller.arguments.length; ++i) {
				var arg = caller.arguments[i];
				stackText += arg;
				if (i < caller.arguments.length - 1)
					stackText += ",";
			}
			stackText += ")\n";
			caller = caller.arguments.callee.caller;
		}
	}

	var environment = Components.classes["@mozilla.org/process/environment;1"].
		getService(Components.interfaces.nsIEnvironment);
	if (environment.exists("XUL_ASSERT_PROMPT") &&
			!parseInt(environment.get("XUL_ASSERT_PROMPT")))
		return;

	var source = null;
	if (this.window)
		source = this.window;
	var ps = Components.classes["@mozilla.org/embedcomp/prompt-service;1"].
		getService(Components.interfaces.nsIPromptService);
	ps.alert(source, "Assertion Failed", assertionText + stackText);
}


function printd(msg)
{
	if(!_trace_window) _invoke_trace_window();

	var caller			= Components.stack.caller;

	var aSourceName		= caller.filename;
	var aSouceLine		= caller.sourceLine;
	var aLineNumber		= caller.lineNumber;
	var aColumnNumber	= 0;
	var aFlags			= 1;	// warning
	var aCategory		= null;

	var scriptError		= Components.classes["@mozilla.org/scripterror;1"]
							.createInstance(Components.interfaces.nsIScriptError);
		scriptError.init(
				(caller.name?caller.name + "() : ":"") + msg,
				aSourceName,
				aSouceLine,
				aLineNumber,
				aColumnNumber,
				aFlags,
				aCategory);
	consoleService.logMessage(scriptError);
}


function Obj2Str(obj, name, indent, depth)
{
	var MAX_DUMP_DEPTH = 10;

	if (depth > MAX_DUMP_DEPTH) {
		return indent + name + ": <Maximum Depth Reached>\n";
	}
	if (typeof obj == "object") {
		var child = null;
		var output = indent + name + "\n";
		var total = 0;
		indent += "\t";
		try {
			if(true || obj.toString().indexOf("XPCNativeWrapper")!=-1)
			{
				for (var item in obj)
				{
					try {
						child = obj[item];
					} catch (e) {
						child = "<Unable to Evaluate>";
					}

					if (typeof child == "object") {
						output += Obj2Str(child, item, indent, depth + 1);
					} else {
						output += indent + item + ": " + child + "\n";
					}
				}
			}
		} catch(e){
			printd("obj : " + obj + ", length : " + obj.length + ", name : " + name + ", depth : " + depth);
			printd(obj.toString());
			printd(e);
		}
		return output;
	} else {
		return obj;
	}
}

function printObj(obj)
{
	var message = Obj2Str(obj);
	var caller			= Components.stack.caller;

	var aSourceName		= caller.filename;
	var aSouceLine		= caller.sourceLine;
	var aLineNumber		= caller.lineNumber;
	var aColumnNumber	= 0;
	var aFlags			= 1;	// warning
	var aCategory		= null;

	var scriptError		= Components.classes["@mozilla.org/scripterror;1"]
							.createInstance(Components.interfaces.nsIScriptError);
		scriptError.init(
				(caller.name?caller.name + "() : ":"") + message,
				aSourceName,
				aSouceLine,
				aLineNumber,
				aColumnNumber,
				aFlags,
				aCategory);
	consoleService.logMessage(scriptError);
}

function trace(msg)
{
	var caller = trace.caller.name;
	if(caller)
		consoleService.logStringMessage(caller+" : " + msg);
	else
		consoleService.logStringMessage(msg);
}

function result2str(result)
{
	// TODO : use nsIErrorService
	for(var i in Components.results)
		if(Components.results[i] == result) return i;
	return "Unknown"
}

function restartFirefox()
{
	var boot = Components.classes["@mozilla.org/toolkit/app-startup;1"].getService(Components.interfaces.nsIAppStartup);  
	boot.quit(Components.interfaces.nsIAppStartup.eForceQuit|Components.interfaces.nsIAppStartup.eRestart);  
}
