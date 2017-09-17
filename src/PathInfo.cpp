
#ifndef String_class_h
#include <WString.h>
#endif

//ifndef  DBG_OUTPUT_PORT
//define DBG_OUTPUT_PORT Serial
//endif
//ifndef HardwareSerial_h
//include <HardwareSerial.h>
//endif

#ifndef _PATHINFO_H
#include "PathInfo.h"
#endif

void PathInfo::_initFromPath(String path) {
    //DBG_OUTPUT_PORT.println("initializing from path: " + path);

    int8_t lastIdx;
    _path = path;
    _name = path;

    // check for pseudo-dir prefix
    _dir = "/";
    lastIdx = path.lastIndexOf("/");
    if(lastIdx != -1) {
        if(lastIdx > 0)
            _dir = path.substring(0, lastIdx + 1);
        _name = path.substring(lastIdx+1);
    }

    _base = _name;
    lastIdx = _name.lastIndexOf(".min");
    if(lastIdx != -1) {
        _min = true;
        _base = _name.substring(0, lastIdx) + _name.substring(lastIdx+4);
    }
    String minString = (_min) ? "Yes" : "No";

    String bs = _base;
    _ext = "";

    // check for gzip with no ext
    if(_base.endsWith(".gz")) {
        lastIdx = _base.lastIndexOf(".gz");
        bs = _base.substring(0, lastIdx);
        if(bs.lastIndexOf(".") == -1) {
            _base = bs;
            _ext = "gz";
            _enc = "";
            _type = "application/gzip";
            return;
        } else {
            _enc = "gzip";
        }
    }

    // same for compress
    if(_base.endsWith(".Z")) {
        lastIdx = _base.lastIndexOf(".Z");
        bs = _base.substring(0, lastIdx);
        if(bs.lastIndexOf(".") == -1) {
            _base = bs;
            _ext = "Z";
            _enc = "";
        } else {
            _enc = "compress";
        }
    }
    //DBG_OUTPUT_PORT.println("\tenc: " + _enc);

    lastIdx = bs.lastIndexOf(".");
    if(lastIdx != -1) {
        _base = bs.substring(0, lastIdx);
        _ext = bs.substring(lastIdx + 1);
    } else {
        _base = bs;
    }

    _type = extEncoding(_ext);

    buildRealPath(); // calls buildRealName()
    //DBG_OUTPUT_PORT.println(showInfo());
}

void PathInfo::_initFromVals(String dir, String base, String ext, String enc, String type, bool min) {
    //DBG_OUTPUT_PORT.println("initializing from values");
    _dir = dir;
    _base = base;
    _ext = ext;
    _enc = enc;
    if(type != "")
        _type = type;
    else
        _type = extEncoding(ext);
    _min = min;

    buildRealPath(); // calls buildRealName()

    //DBG_OUTPUT_PORT.println(showInfo());
}

String PathInfo::buildRealName() {
    _name = _base +
            ((_min) ? ".min" : "") +
            ((_ext == "") ? "" : "."+_ext) +
            ((_enc == "gzip") ? ".gz" : ((_enc == "compress") ? ".Z" : ""));
    return _name;
}
String PathInfo::getAlias() {
    return _base + ((_ext == "") ? "" : "."+_ext);
}
String PathInfo::buildRealPath() {
    _path = _dir + buildRealName();
    return _path;
}
String PathInfo::getAliasPath() {
    return _dir + getAlias();
}

String PathInfo::extEncoding(String ex) {
    String t = "application/octet-stream"; // default

    if(ex == "htm") t = "text/html";
    else if(ex == "txt") t = "text/plain";
    else if(ex == "css") t = "text/css";
    else if(ex == "xml") t = "text/xml";
    else if(ex == "rtf") t = "text/richtext";
    else if(ex == "csv") t = "text/csv";
    else if(ex == "js")  t = "application/javascript";
    else if(ex == "png") t = "image/png";
    else if(ex == "gif") t = "image/gif";
    else if((ex == "jpg") || (ex == "jpeg")) t = "image/jpeg";
    else if(ex == "ico") t = "image/x-icon";
    else if(ex == "svg") t = "image/svg+xml";
    else if(ex == "pdf") t = "application/pdf";
    else if(ex == "zip") t = "application/zip";
    else if(ex == "gz") t = "application/gzip";
    else if(ex == "Z") t = "application/zlib";

    return t;
}

String PathInfo::infoJSON() {
    String tmp;
    String message = "{";
    message += "path:\"" + _path + "\",";
    message += "dir:\""  + _dir  + "\",";
    message += "name:\"" + _name + "\",";
    message += "base:\"" + _base + "\",";
    message += "ext:\""  + _ext  + "\",";
    message += "enc:\""  + _enc   + "\",";
    message += "type:\"" + _type + "\",";
    tmp = (_min) ? "1" : "0";
    message += "min:" + tmp;
    message += "}";

    return message;
}