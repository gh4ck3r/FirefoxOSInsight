"use strict"

const {Cu} = require("chrome");
const {Devices} = Cu.import("resource://gre/modules/devtools/Devices.jsm");

let tabs=require("sdk/tabs");
let data=require("sdk/self").data;

let widget = require("sdk/widget").Widget({
  id: "FirefoxOS Insight",
  label: "FirefoxOS Insight Widget",
  contentURL: data.url("logo.png"),
  onClick: () => {
    tabs.open({
      url: data.url("index.html"),
      onReady: tab => {
        let emit = tab.attach({
          contentScriptFile: [
            data.url("js/jquery-1.10.2.min.js"),
            data.url("js/main.js"),
          ]
        }).port.emit;

        function adbHelperAddonStatusChanged() {
          emit("adbHelperAddonStatusChanged", Devices.helperAddonInstalled);
        };
        function adbDeviceConnectionChanged() {
          emit("adbDeviceConnectionChanged", Devices.available());
        };

        Devices.on("addon-status-updated", adbHelperAddonStatusChanged);
        Devices.on("register", adbDeviceConnectionChanged);
        Devices.on("unregister", adbDeviceConnectionChanged);

        adbHelperAddonStatusChanged();
        adbDeviceConnectionChanged();
      }
    })
  }
});

