
#ifndef Arduino_h
#include <Arduino.h>
#endif

#ifndef _PATHINFO_H
#include "PathInfo.h"
#endif

#ifndef FS_H
#include <FS.h>
#endif

PathInfo::PathInfo() {
}

PINF PathInfo::getPathInfo(String path) {
    PINF pInfo;
    pInfo.path = path;
    int8_t lastIdx = path.lastIndexOf("/");
    pInfo.dir = "";
    pInfo.name = path;
    if((lastIdx != -1) && (lastIdx > 0)) {
        pInfo.dir = path.substring(0, lastIdx + 1);
        pInfo.name = path.substring(lastIdx+1);
    }
    lastIdx = pInfo.name.lastIndexOf(".");
    if(lastIdx != -1) {
        pInfo.base = pInfo.name.substring(0, lastIdx);
        pInfo.ext = pInfo.name.substring(lastIdx+1);

        // comment out next 6 lines to keep .min. in basenames
        lastIdx = pInfo.base.lastIndexOf(".min");
        if(lastIdx != -1) {
            pInfo.min = true;
            pInfo.base = pInfo.base.substring(0, lastIdx) + pInfo.base.substring(lastIdx+4);
            //DBG_OUTPUT_PORT.println("unminified base: " + pInfo.base);
        }

        while((pInfo.ext == "gz") || (pInfo.ext == "Z") || (pInfo.ext == "z")) {
            if(pInfo.ext == "gz") {
                pInfo.gzip = true;
            } else if((pInfo.ext == "Z") || (pInfo.ext == "z")) {
                pInfo.compress = true;
            }
            lastIdx = pInfo.base.lastIndexOf(".");
            if(lastIdx != -1) {
                pInfo.ext = pInfo.base.substring(lastIdx+1);
                pInfo.base = pInfo.base.substring(0, lastIdx);
            }
        }
    } else {
        pInfo.base = pInfo.name;
        pInfo.ext = "";
    }
    pInfo.type = "application/octet-stream";

    if(pInfo.ext == "htm") pInfo.type = "text/html";
    else if(pInfo.ext == "txt") pInfo.type = "text/plain";
    else if(pInfo.ext == "css") pInfo.type = "text/css";
    else if(pInfo.ext == "xml") pInfo.type = "text/xml";
    else if(pInfo.ext == "rtf") pInfo.type = "text/richtext";
    else if(pInfo.ext == "csv") pInfo.type = "text/csv";
    else if(pInfo.ext == "js")  pInfo.type = "application/javascript";
    else if(pInfo.ext == "png") pInfo.type = "image/png";
    else if(pInfo.ext == "gif") pInfo.type = "image/gif";
    else if((pInfo.ext == "jpg") || (pInfo.ext == "jpeg")) pInfo.type = "image/jpeg";
    else if(pInfo.ext == "ico") pInfo.type = "image/x-icon";
    else if(pInfo.ext == "svg") pInfo.type = "image/svg+xml";
    else if(pInfo.ext == "pdf") pInfo.type = "application/pdf";
    else if(pInfo.ext == "zip") pInfo.type = "application/zip";

    return pInfo;
}

PINF PathInfo::getTruePathInfo(String fPath) {
    PINF fpInf = PathInfo::getPathInfo(fPath);
    if(SPIFFS.exists(fpInf.path))
        return fpInf;

    //DBG_OUTPUT_PORT.println("path not found, trying alternatives...");

    //DBG_OUTPUT_PORT.println("Trying...");
    String altPath = fpInf.path + ".gz";
    //DBG_OUTPUT_PORT.println("   " + altPath);
    if((altPath.length() <= fs_info.maxPathLength) && SPIFFS.exists(altPath)) {
        fpInf.gzip = true;
        fpInf.path = altPath;
    } else if(!fpInf.min && !fpInf.gzip && !fpInf.compress && (fpInf.ext != "")) {
        altPath = fpInf.dir + fpInf.base + ".min." + fpInf.ext;
        //DBG_OUTPUT_PORT.println("   " + altPath);
        if((altPath.length() <= fs_info.maxPathLength) && SPIFFS.exists(altPath)) {
            fpInf.min = true;
            fpInf.path = altPath;
        } else {
            altPath = altPath + ".gz";
            //DBG_OUTPUT_PORT.println("   " + altPath);
            if((altPath.length() <= fs_info.maxPathLength) && SPIFFS.exists(altPath)) {
                fpInf.gzip = true;
                fpInf.path = altPath;
            }
        }
    }
    /*
    if(fPath != fpInf.path ) {
        DBG_OUTPUT_PORT.println("using alternate path: " + altPath);
    }
     */
    return fpInf;
}
