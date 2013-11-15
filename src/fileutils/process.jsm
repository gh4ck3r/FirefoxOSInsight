const { classes: Cc, interfaces: Ci, utils: Cu } = Components;
Cu.import("resource://debug/debug.jsm");
var EXPORTED_SYMBOLS = [
  "execFile",
  "execPath",
];

const nsILocalFile = Ci.nsILocalFile;
const nsIProcess   = Ci.nsIProcess;

function execFile(aFile, args, blocked)
{

  if(!aFile) {
    throw Cr.NS_ERROR_NULL_POINTER;
  } else if(!aFile.exists()) {
    throw Cr.NS_ERROR_FILE_NOT_FOUND;
  } else if(!aFile.isFile()) {
    throw Cr.NS_ERROR_FILE_IS_DIRECTORY;
  } else if(!aFile.isExecutable()) {
    throw Cr.NS_ERROR_FILE_ACCESS_DENIED;
  } else if(args && Object.prototype.toString.apply(args) != "[object Array]") {
    throw Cr.NS_ERROR_PROXY_INVALID_IN_PARAMETER;
  } else if(blocked && typeof(blocked) != "boolean") {
    throw Cr.NS_ERROR_PROXY_INVALID_IN_PARAMETER;
  }

  const process = Cc["@mozilla.org/process/util;1"]
                      .createInstance(nsIProcess);
  process.init(aFile);

  blocked = blocked || true;
  args  = args || [];

  process.run(blocked, args, args.length);

  return process.exitValue;
}

function execPath(path, args, blocked)
{
  const aFile = Cc["@mozilla.org/file/local;1"]
                    .createInstance(nsILocalFile);  
  aFile.initWithPath(path);

  return execFile(aFile, args, blocked);
}

