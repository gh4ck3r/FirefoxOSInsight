"use strict"

var on=self.port.on;

let $body = $("body")

var adbStatusElem=$("#adbAddonStatus");
var deviceCountElem=$("#adbDeviceCounter");

on("adbHelperAddonStatusChanged", exist=>{
  if(exist) {
    $body.css("border", "1px dotted red")
    adbStatusElem.text("Helper addon exist.");
  } else {
    $body.css("border", "")
    adbStatusElem.text("Helper addon not exist");
  }
});

on("adbDeviceConnectionChanged", devices=>{
    deviceCountElem.text("available Devices : "+devices.length)
});

