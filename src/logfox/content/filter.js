Components.utils.import("resource://debug/debug.jsm");
var msgFilter = window.arguments[0];

const filterTree = document.getElementById("filter-tree");
filterTree.view = msgFilter;

const pidElem = document.getElementById("pid-filter");
const tidElem = document.getElementById("tid-filter");
const tagElem = document.getElementById("tag-filter");

function addFilter()
{
	var pidVal = pidElem.value;
	var tidVal = tidElem.value;
	var tagVal = tagElem.value;

	if(pidVal==0&&tidVal==0&&!tagVal) return;
	var filter = {};
	if(pidVal!=0)	filter.pid = parseInt(pidVal);
	if(tidVal!=0)	filter.tid = parseInt(tidVal);
	if(tagVal)		filter.tag = tagVal;

	msgFilter.addFilter(filter);

	pidElem.reset();
	tidElem.reset();
	tagElem.reset();
}

function delSelectedFilter()
{
	msgFilter.delSelectedFilter();
}
