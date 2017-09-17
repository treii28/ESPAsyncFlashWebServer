#ifndef  DBG_OUTPUT_PORT
#define DBG_OUTPUT_PORT Serial
#endif

// needed for platformio
#ifndef Arduino_
#include <Arduino.h>
#endif

// needed for async webserver that doesn't seem to find Hash
#ifndef HASH_H_
#include <Hash.h>
#endif
#ifndef FS_H
#include <FS.h>
#endif
#ifndef _ESPAsyncWebServer_H_
#include <ESPAsyncWebServer.h>
#endif

//ifndef SPIFFSEditor_H_
//include <SPIFFSEditor.h>
//endif


#ifndef WiFi_h
#include <ESP8266WiFi.h>
#endif
#ifndef DNSServer_h
#include <DNSServer.h>
#endif


#ifndef ESP8266MDNS_H
#include <ESP8266mDNS.h>
#endif

#ifndef __ARDUINO_OTA_H
#include <ArduinoOTA.h>
#endif

#ifndef _PATHINFO_H
#include "PathInfo.h"
#endif

const byte DNS_PORT = 53;
const char* apHostname = "WiFiGeoCache";
const char* apSSID = "CCR_WiFi_GeoCache";
const char* localSSID = "Samsung Galaxy Note 4";
const char* localPass = "on the road again";

IPAddress apIp ( 10, 10, 10, 10 ); // for softAP mode if used
const char* captiveRedirect = "geo.htm";

AsyncWebServer asyncWebServer(80);
DNSServer dnsServer;
FSInfo fs_info;
String serverError;

void returnOK(AsyncWebServerRequest *request) {request->send(200, "text/plain", "");}
void returnFail(AsyncWebServerRequest *request, String msg) {request->send(500, "text/plain", msg + "\r\n");}
void returnFailJSON(AsyncWebServerRequest *request, String msg) {request->send(500, "application/json", "{serverError:\"" + msg + "\"}");}

void logData(String csvString) {
    DBG_OUTPUT_PORT.println("appending entry to log");
    // open the file. note that only one file can be open at a time,
    // so you have to close this one before opening another.
    File dataFile = SPIFFS.open("/datalog.csv", "a+");

    // if the file is available, write to it:
    if (dataFile) {
        dataFile.println(csvString);
        dataFile.close();
        // print to the serial port too:
        DBG_OUTPUT_PORT.println(csvString);
    }
        // if the file isn't open, pop up an error:
    else {
        DBG_OUTPUT_PORT.println("error opening datalog.txt");
        serverError = "FILE ERROR";
    }
}
void addLog(AsyncWebServerRequest *request) {
    DBG_OUTPUT_PORT.println("adding new log entry");
    String logLine = "";

    // date is first CSV field - created by code
    logLine += (request->hasArg("datetime")) ? request->arg("datetime") : "";
    DBG_OUTPUT_PORT.println("Date and Time is: " + String(request->arg("datetime")));

    logLine += "|";

    // name is next, sanitize quotes and pipes
    String name = (request->hasArg("name")) ? request->arg("name") : "";
    name.replace("\"", "\"\"");
    name.replace("|", "");
    if (name == "") returnFail(request, "NAME REQUIRED");
    logLine += name;

    logLine += "|";

    // id is digits or blank. Should be sanitized by form/code
    logLine += (request->hasArg("memberId")) ? request->arg("memberId") : "";

    logLine += "|";

    // sanitize quotes and pipes in comment
    String comment = (request->hasArg("comment")) ? request->arg("comment") : "";
    comment.replace("\"", "\"\"");
    name.replace("|", "");
    logLine += comment;

    logLine += "\n";
    DBG_OUTPUT_PORT.println(logLine);

    // call logData to append line to log file
    logData(logLine);
    if (serverError != "") {
        returnFailJSON(request, serverError);
        serverError = "";
    } else {
        request->redirect("/datalog.csv");
    }
}

PathInfo* getTruePathInfo(String fPath) {
    DBG_OUTPUT_PORT.println("getTruePathInfo: looking for true path of: " + fPath);

    PathInfo* fpInf = new PathInfo(fPath);
    bool pathExists = SPIFFS.exists(fpInf->getPath());
    if(!pathExists) {
        DBG_OUTPUT_PORT.println("getTruePathInfo: path not found, trying...");

        PathInfo* tInf;
        if(!pathExists && !fpInf->isMinified()) {
            DBG_OUTPUT_PORT.println("getTruePathInfo: minified...");
            tInf = new PathInfo(fpInf->getDir(), fpInf->getBase(), fpInf->getExt(), fpInf->getEnc(), true );
            pathExists = SPIFFS.exists(tInf->getPath());
            if(pathExists)
                fpInf = tInf;
        }
        if(!pathExists && (fpInf->getEnc() == "")) {
            DBG_OUTPUT_PORT.println("getTruePathInfo: gzipped...");
            tInf = new PathInfo(fpInf->getDir(), fpInf->getBase(), fpInf->getExt(), "gzip", fpInf->isMinified());
            pathExists = SPIFFS.exists(tInf->getPath());
            if(pathExists)
                fpInf = tInf;
            if(!pathExists && !fpInf->isMinified()) {
                DBG_OUTPUT_PORT.println("getTruePathInfo: gzipped and minified...");
                tInf = new PathInfo(fpInf->getDir(), fpInf->getBase(), fpInf->getExt(), "gzip", true );
                pathExists = SPIFFS.exists(tInf->getPath());
                if(pathExists)
                    fpInf = tInf;
            }
        }
        if(!pathExists && (fpInf->getEnc() == "")) {
            DBG_OUTPUT_PORT.println("getTruePathInfo: compressed...");
            tInf = new PathInfo(fpInf->getDir(), fpInf->getBase(), fpInf->getExt(), "compress", fpInf->isMinified());
            pathExists = SPIFFS.exists(tInf->getPath());
            if (pathExists)
                fpInf = tInf;
            if(!pathExists && !fpInf->isMinified()) {
                DBG_OUTPUT_PORT.println("getTruePathInfo: compressed and minified...");
                tInf = new PathInfo(fpInf->getDir(), fpInf->getBase(), fpInf->getExt(), "compress", true );
                pathExists = SPIFFS.exists(tInf->getPath());
                if(pathExists)
                    fpInf = tInf;
            }
        }
        if(pathExists) {
            DBG_OUTPUT_PORT.println("getTruePathInfo: found: " + fpInf->getPath());
        }
    }

    return fpInf;
}

bool printDir(AsyncWebServerRequest *request) {
    String dPath = request->url();
    // remove any trailing slash
    if(!dPath.endsWith("/"))
        dPath += "/";
    DBG_OUTPUT_PORT.println("printDir: attempting printDir on '" + dPath + "'");
    Dir webDir = SPIFFS.openDir(dPath);
    String dirList = "";
    while (webDir.next()) {
        PathInfo* pInfo = new PathInfo(webDir.fileName());
        String fName = pInfo->getAlias();
        dirList += "<tr><td><a href=\"" + pInfo->getDir() + fName + "\">" +fName + "</a></td><td>&nbsp;...&nbsp;</td>";
        File f = webDir.openFile("r");
        dirList += "<td>" + String(f.size()) + "</td></tr>";
        f.close();
    }
    if(dirList != "") {
        DBG_OUTPUT_PORT.println("printDir: Sending directory listing.");
        String dirHtml = "<html><head><title>" + dPath + " Directory Listing</title></head>";
        dirHtml += "<body><h1>" + dPath + " Directory Listing</h1><hr /><table>" + dirList + "</table></body></html>";
        request->send(200, "text/html", dirHtml);
        return true;
    } else {
        return false;
    }
}
bool loadFromFlash(AsyncWebServerRequest *request) {
    String path = request->url();
    DBG_OUTPUT_PORT.println("loadFromFlash: checking SPIFFS FS for " + path);

    bool pathExists = false;
    PathInfo* upInf;
    if((path == "") || (path == "/")) path = "/index.htm";

    // see if file exists
    upInf = getTruePathInfo(path);
    pathExists = SPIFFS.exists(upInf->getPath());
    if(pathExists) {
        DBG_OUTPUT_PORT.println("loadFromFlash: truepath: " + upInf->getPath());
    } else {
        DBG_OUTPUT_PORT.println("loadFromFlash: checking for dir...");
        if(path.endsWith("/")) { // user seems to be trying to get a dir listing
            DBG_OUTPUT_PORT.println("loadFromFlash: ends with '/', looking for index...");
            // check for index file in dir first
            upInf = getTruePathInfo(path + "index.htm");
            // filenames must be under 32 characters all told
            pathExists = SPIFFS.exists(upInf->getPath());
            if(pathExists) {
                DBG_OUTPUT_PORT.println("loadFromFlash: found");
            } else {
                DBG_OUTPUT_PORT.println("loadFromFlash: not found, calling printDir");
                return printDir(request);
            }
        } else if(path.indexOf("index.htm") == -1){
            DBG_OUTPUT_PORT.println("loadFromFlash: trying with /index.htm appended...");
            // try slash+index.htm just for kicks
            upInf = getTruePathInfo(path + "/index.htm");
            pathExists = SPIFFS.exists(upInf->getPath());
            if (pathExists) {
                DBG_OUTPUT_PORT.println("loadFromFlash: found");
            } else {
                DBG_OUTPUT_PORT.println("loadFromFlash: not found, calling printDir");
                return printDir(request);
            }
        }
    }

    if(pathExists == false) { // shouldn't trigger
        DBG_OUTPUT_PORT.println("loadFromFlash: something went wrong");
        return false;
    }

    delay(1000);
    DBG_OUTPUT_PORT.println("loadFromFlash: opening: " + upInf->getPath());
    delay(1000);
    File webFile  = SPIFFS.open(upInf->getPath(), "r");

    if (!webFile){
        DBG_OUTPUT_PORT.println("loadFromFlash: problem opening " + upInf->getPath());
        return false;
    }

    DBG_OUTPUT_PORT.println("loadFromFlash: creating response");
    AsyncWebServerResponse *response = request->beginResponse(
            webFile, upInf->getPath(), upInf->getType(), false, NULL);

    if(upInf->getEnc() != "") {
        DBG_OUTPUT_PORT.println("loadFromFlash: adding encoding header for '" + upInf->getEnc() + "'");
        response->addHeader("Content-Encoding", upInf->getEnc());
    }
    DBG_OUTPUT_PORT.println("loadFromFlash: sending response");
    request->send(response);

    return true;
}

void sendNotFoundInfo(AsyncWebServerRequest *request){
    String message = "\nNo Handler\r\n";
    message += "URI: ";
    message += request->url();
    message += "\nHOST: ";
    message += request->host();
    message += "\nMethod: ";
    message += (request->method() == HTTP_GET)?"GET":"POST";
    message += "\nParameters: ";
    message += request->params();
    message += "\n";
    for (uint8_t i=0; i<request->params(); i++){
        AsyncWebParameter* p = request->getParam(i);
        message += String(p->name().c_str()) + " : " + String(p->value().c_str()) + "\r\n";
    }
    request->send(404, "text/plain", message);
}
void handleNotFound(AsyncWebServerRequest *request){
    String path = request->url();
    DBG_OUTPUT_PORT.println("handleNotFound: no specific handler, checking SPIFFS for url:" + path);
    if(loadFromFlash(request)) return;
    sendNotFoundInfo(request);
}
void handleUpload(AsyncWebServerRequest *request, String filename, size_t index, uint8_t *data, size_t len, bool final) {
    struct uploadRequest {
        uploadRequest* next;
        AsyncWebServerRequest *request;
        File uploadFile;
        uint32_t fileSize;
        uploadRequest(){next = NULL; request = NULL; fileSize = 0;}
    };
    static uploadRequest uploadRequestHead;
    uploadRequest* thisUploadRequest = NULL;

    if( ! index){
        String toFile = filename;
        if(request->hasParam("dir")) {
            AsyncWebParameter* p = request->getParam("dir");
            DBG_OUTPUT_PORT.println("dir param: " + p->value());
            toFile = p->value();
            if(!toFile.endsWith("/"))
                toFile += "/";
            toFile += filename;
        }
        if(!toFile.startsWith("/"))
            toFile = "/" + toFile;

        if(toFile.length() > fs_info.maxPathLength) {
            returnFail(request, "full filename too long");
            return;
        }

        if(SPIFFS.exists(toFile))
            SPIFFS.remove(toFile);
        thisUploadRequest = new uploadRequest;
        thisUploadRequest->request = request;
        thisUploadRequest->next = uploadRequestHead.next;
        uploadRequestHead.next = thisUploadRequest;
        thisUploadRequest->uploadFile = SPIFFS.open(toFile, "w");
        DBG_OUTPUT_PORT.println("Upload: START, filename: " + toFile);
    }
    else{
        thisUploadRequest = uploadRequestHead.next;
        while(thisUploadRequest->request != request) thisUploadRequest = thisUploadRequest->next;
    }

    if(thisUploadRequest->uploadFile){
        for(size_t i=0; i<len; i++){
            thisUploadRequest->uploadFile.write(data[i]);
        }
        thisUploadRequest->fileSize += len;
    }

    if(final){
        thisUploadRequest->uploadFile.close();
        DBG_OUTPUT_PORT.println("Upload: END, Size: "); DBG_OUTPUT_PORT.println(thisUploadRequest->fileSize);
        uploadRequest* linkUploadRequest = &uploadRequestHead;
        while(linkUploadRequest->next != thisUploadRequest) linkUploadRequest = linkUploadRequest->next;
        linkUploadRequest->next = thisUploadRequest->next;
        delete thisUploadRequest;
    }
}
void handleDelete(AsyncWebServerRequest *request) {
    if( ! request->params()) returnFail(request, "No Path");
    String path = request->arg("path");
    DBG_OUTPUT_PORT.println("deleting " + path );
    if((path == "/") || (path == ""));
        returnFail(request, "Invalid Path");
    PathInfo* fInf = getTruePathInfo(path);
    if(!SPIFFS.exists(fInf->getPath())) {
        returnFail(request, "Bad Path");
    }
    if(SPIFFS.remove(fInf->getPath())) {
        returnOK(request);
    } else {
        returnFail(request, "remove " + fInf->getPath() + " failed");
    }
}

void initDebug() {
    Serial.begin(9600);
    DBG_OUTPUT_PORT.begin(115200);
    delay(1500);
    DBG_OUTPUT_PORT.setDebugOutput(true);
    DBG_OUTPUT_PORT.println("Debug output initialized");
}
void initWifi() {
    DBG_OUTPUT_PORT.println("Initializing WiFi SoftAP");
    WiFi.hostname(apHostname);
    WiFi.mode((localSSID == "") ? WIFI_AP : WIFI_AP_STA);
    WiFi.softAPConfig ( apIp, apIp, IPAddress ( 255, 255, 255, 0 ) );
    WiFi.softAP(apSSID);
    DBG_OUTPUT_PORT.println("SoftAP " + String(apHostname) + " started on " + String(WiFi.softAPIP()));

    if(localSSID != "") {
        DBG_OUTPUT_PORT.println("Initializing WiFi local connection: " + String(localSSID));
        WiFi.begin(localSSID, localPass);
        if (WiFi.waitForConnectResult() != WL_CONNECTED) {
            DBG_OUTPUT_PORT.printf("STA: Failed!\n");
            WiFi.disconnect(false);
            delay(1000);
            DBG_OUTPUT_PORT.println("retrying WiFi local connection");
            WiFi.begin(localSSID, localPass);
        }
    }
    DBG_OUTPUT_PORT.println("WiFi Initialization complete");
}
void initDNSServer() {
    DBG_OUTPUT_PORT.println("Initializing DNSServer for Captive Portal");
    dnsServer.setErrorReplyCode(DNSReplyCode::NoError);
    dnsServer.start ( DNS_PORT, "*", WiFi.softAPIP() ); // captive portal redirect everything to here when in AP mode
}
/*
void initMDNS() {
    DBG_OUTPUT_PORT.println("Initializing MDNS for local hostname on AP");
    if (MDNS.begin(apHostname)) {
        MDNS.addService("http", "tcp", 80);
        DBG_OUTPUT_PORT.println("MDNS responder started");
        DBG_OUTPUT_PORT.print("You can now connect to http://");
        DBG_OUTPUT_PORT.print(apHostname);
        DBG_OUTPUT_PORT.println(".local");
    }
}
*/
void initWebserver() {
    //asyncWebServer.addHandler(new SPIFFSEditor("admin","admin"));

    //Android captive portal. Maybe not needed. Might be handled by notFound handler.
    asyncWebServer.addRewrite( new AsyncWebRewrite("/generate_204", captiveRedirect));
    //asyncWebServer.on ( "/generate_204", returnOK );
    //Microsoft captive portal. Maybe not needed. Might be handled by notFound handler.
    asyncWebServer.addRewrite( new AsyncWebRewrite("/fwlink", captiveRedirect));
    //asyncWebServer.on ( "/fwlink", returnOK );
    //Microsoft windows 10
    //asyncWebServer.on ( "/connecttest.txt", returnOK );
    asyncWebServer.addRewrite( new AsyncWebRewrite("/connecttest.txt", captiveRedirect));
    // apple devices
    asyncWebServer.addRewrite( new AsyncWebRewrite("/hotspot-detect.html", captiveRedirect));
    //asyncWebServer.on ( "/hotspot-detect.html", returnOK );
    asyncWebServer.addRewrite( new AsyncWebRewrite("/library/test/success.html", captiveRedirect));
    //asyncWebServer.on ( "/library/test/success.html", returnOK );
    // kindle
    asyncWebServer.addRewrite( new AsyncWebRewrite("/kindle-wifi/wifistub.html", captiveRedirect));
    //asyncWebServer.on ( "/kindle-wifi/wifistub.html", returnOK );

    asyncWebServer.on("/delete", HTTP_DELETE, handleDelete);
    // upload a file to /upload
    asyncWebServer.on("/upload", HTTP_POST, returnOK, handleUpload);
    // Catch-All Handlers
    asyncWebServer.onFileUpload(handleUpload);
    //asyncWebServer.onRequestBody(onBody);

    asyncWebServer.on("/signin", HTTP_GET, addLog);

    asyncWebServer.onNotFound(handleNotFound);

    asyncWebServer.begin();
    DBG_OUTPUT_PORT.println("HTTP asyncWebServer started");
}
void getSPIFFSInfo() {
    DBG_OUTPUT_PORT.println("Filesystem Info:");
    DBG_OUTPUT_PORT.println("      total bytes : " + String(fs_info.totalBytes));
    DBG_OUTPUT_PORT.println("       used bytes : " + String(fs_info.usedBytes));
    DBG_OUTPUT_PORT.println("       block size : " + String(fs_info.blockSize));
    DBG_OUTPUT_PORT.println("        page size : " + String(fs_info.pageSize));
    DBG_OUTPUT_PORT.println("   max open files : " + String(fs_info.maxOpenFiles));
    DBG_OUTPUT_PORT.println("  max path length : " + String(fs_info.maxPathLength));
}
void formatSPIFFS() {
    Serial.println("Please wait 30 secs for SPIFFS to be formatted");
    SPIFFS.format();
    Serial.println("Spiffs formatted");
    DBG_OUTPUT_PORT.println("SPIFFS Initialized.");
    if(SPIFFS.info(fs_info)) {
        getSPIFFSInfo();
    } else {
        DBG_OUTPUT_PORT.println("Error getting SPIFFS info!");
    }
}
void initSPIFFS() {
    if( ! SPIFFS.begin()){
        DBG_OUTPUT_PORT.println("SPIFFS initiatization failed. Retrying.");
        while(!SPIFFS.begin()){
            delay(250);
        }
    }


    if(SPIFFS.info(fs_info)) {
        getSPIFFSInfo();
    } else {
        formatSPIFFS();
    }
}
void initOTA() {
    // Port defaults to 8266
    // ArduinoOTA.setPort(8266);

    // Hostname defaults to esp8266-[ChipID]
    // ArduinoOTA.setHostname("myesp8266");

    // No authentication by default
    // ArduinoOTA.setPassword((const char *)"123");

    ArduinoOTA.onStart([]() {
        Serial.println("Start");
    });
    ArduinoOTA.onEnd([]() {
        Serial.println("\nEnd");
    });
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
        Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    });
    ArduinoOTA.onError([](ota_error_t error) {
        Serial.printf("Error[%u]: ", error);
        if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
        else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
        else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
        else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
        else if (error == OTA_END_ERROR) Serial.println("End Failed");
    });
    ArduinoOTA.begin();
}

void setup() {
    initDebug();
    initWifi();
    initDNSServer();
    //initMDNS();
    initWebserver();
    initSPIFFS();
    initOTA();
}

void loop() {
    ArduinoOTA.handle();
    dnsServer.processNextRequest();
}
