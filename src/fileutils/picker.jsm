const { classes: Cc, interfaces: Ci, utils: Cu } = Components;

var EXPORTED_SYMBOLS = [
  "pickExecFile",
  "pickExecFilePath",
  "pickFile",
  "pickFilePath",
];

const nsIFilePicker = Ci.nsIFilePicker;

function pickExecFile(title)
{
  return pickFile(title, nsIFilePicker.filterApps);
}

function pickExecFilePath(title)
{
  return file2path(pickExecFile(title));
}

function pickFile(title, filter)
{
  const picker = Cc["@mozilla.org/filepicker;1"]
                    .createInstance(nsIFilePicker);
  picker.init(window(), title, nsIFilePicker.modeOpen);
  picker.appendFilters(filter);
  var ret = picker.show();
  if(ret==nsIFilePicker.returnOK)
    return picker.file;
  return null;
}

function pickFilePath(title, filter)
{
  return file2path(pickFile(title, filter));
}

function file2path(aFile)
{
  return aFile?aFile.path:null;
}

function window()
{
  const wm =  Cc["@mozilla.org/appshell/window-mediator;1"]
                  .getService(Ci.nsIWindowMediator);
  return wm.getMostRecentWindow(null);
}
