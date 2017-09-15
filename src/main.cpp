#ifndef  DBG_OUTPUT_PORT
#define DBG_OUTPUT_PORT Serial
#endif

// valide modes:
// WIFI_AUTOCONNECT_MODE or WIFI_CFGPORTAL_MODE (only one should be used)
//   CFGPORTAL mode forces the wifi manager configuration portal to be always listening
//     and is used for testing or initial setup (autoconnect sometimes connects to open wifi nodes)
// and WIFI_SOFTAP_MODE
#define WIFI_SOFTAP_MODE

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

#if defined (WIFI_AUTOCONNECT_MODE) || (defined WIFI_CFGPORTAL_MODE)
#ifndef ESPAsyncWiFiManager_h
#include <ESPAsyncWiFiManager.h>
#endif
#endif

#ifdef WIFI_SOFTAP_MODE
#ifndef WiFi_h
#include <ESP8266WiFi.h>
#endif
#ifndef DNSServer_h
#include <DNSServer.h>
#endif
#endif

#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>


typedef struct pathInfo {
    String path;
    String dir;
    String name;
    String base;
    String ext;
    String type;
    bool gzip = false;
    bool compress = false;
    bool min = false;
} PINF;

const byte DNS_PORT = 53;
const char* host = "FlashAsync";
const char* ssid = "ESPWiFiMini";
IPAddress ip ( 10, 10, 10, 10 ); // for softAP mode if used

AsyncWebServer asyncWebServer(80);
DNSServer dnsServer;
FSInfo fs_info;
String serverError;

void returnOK(AsyncWebServerRequest *request) {request->send(200, "text/plain", "");}

void returnFail(AsyncWebServerRequest *request, String msg) {request->send(500, "text/plain", msg + "\r\n");}

void returnFailJSON(AsyncWebServerRequest *request, String msg) {request->send(500, "application/json", "{serverError:\"" + msg + "\"}");}

void logData(String csvString)
{
    DBG_OUTPUT_PORT.println("appending entry to log");
    // open the file. note that only one file can be open at a time,
    // so you have to close this one before opening another.
    File dataFile = SPIFFS.open("/datalog.csv", "w");

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

PINF getPathInfo(String path) {
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
            DBG_OUTPUT_PORT.println("unminified base: " + pInfo.base);
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

PINF getTruePathInfo(String fPath) {
    PINF fpInf = getPathInfo(fPath);
    if(SPIFFS.exists(fpInf.path))
        return fpInf;

    DBG_OUTPUT_PORT.println("path not found, trying alternatives...");

    DBG_OUTPUT_PORT.println("Trying...");
    String altPath = fpInf.path + ".gz";
    DBG_OUTPUT_PORT.println("   " + altPath);
    if((altPath.length() <= fs_info.maxPathLength) && SPIFFS.exists(altPath)) {
        fpInf.gzip = true;
        fpInf.path = altPath;
    } else if(!fpInf.min && !fpInf.gzip && !fpInf.compress && (fpInf.ext != "")) {
        altPath = fpInf.dir + fpInf.base + ".min." + fpInf.ext;
        DBG_OUTPUT_PORT.println("   " + altPath);
        if((altPath.length() <= fs_info.maxPathLength) && SPIFFS.exists(altPath)) {
            fpInf.min = true;
            fpInf.path = altPath;
        } else {
            altPath = altPath + ".gz";
            DBG_OUTPUT_PORT.println("   " + altPath);
            if((altPath.length() <= fs_info.maxPathLength) && SPIFFS.exists(altPath)) {
                fpInf.gzip = true;
                fpInf.path = altPath;
            }
        }
    }
    if(fPath != fpInf.path ) {
        DBG_OUTPUT_PORT.println("using alternate path: " + altPath);
    }

    return fpInf;
}


bool printDir(AsyncWebServerRequest *request) {
    String dPath = request->url();
    // remove any trailing slash
    if(!dPath.endsWith("/"))
        dPath += "/";
    DBG_OUTPUT_PORT.println("attempting printDir on '" + dPath + "'");
    Dir webDir = SPIFFS.openDir(dPath);
    String dirList = "";
    while (webDir.next()) {
        PINF pInfo = getPathInfo(webDir.fileName());
        String fName = pInfo.base + "." + pInfo.ext;
        dirList += "<tr><td><a href=\"" + pInfo.dir + fName + "\">" +fName + "</a></td><td>&nbsp;...&nbsp;</td>";
        File f = webDir.openFile("r");
        dirList += "<td>" + String(f.size()) + "</td></tr>";
        f.close();
    }
    if(dirList != "") {
        DBG_OUTPUT_PORT.println("Sending directory listing.");
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
    DBG_OUTPUT_PORT.println("checking flash for " + path);

    PINF upInf = getTruePathInfo(path);

    // if upInf doesn't include an existing file, try index.htm and/or try listing directory
    if(!SPIFFS.exists(upInf.path)) {
        if(path.endsWith("/")) { // user seems to be trying to get a dir listing
            // check for index file in dir first
            PINF ixInf = getTruePathInfo(path + "index.htm");
            // filenames must be under 32 characters all told
            if(SPIFFS.exists(ixInf.path)) {
                upInf = ixInf;
            } else {
                return printDir(request);
            }
        } else {
            // try slash+index.htm just for kicks
            PINF ixInf = getTruePathInfo(path + "/index.htm");
            if (SPIFFS.exists(ixInf.path)) {
                upInf = ixInf;
            } else {
                return printDir(request);
            }
        }
    }


    File webFile  = SPIFFS.open(upInf.path, "r");

    if (!webFile){
        DBG_OUTPUT_PORT.println("problem opening " + upInf.path);
        return false;
    }

    AsyncWebServerResponse *response = request->beginResponse(
            webFile, upInf.path, upInf.type, false, NULL);

    if(upInf.gzip)
        response->addHeader("Content-Encoding", "gzip");
    else if(upInf.compress)
        response->addHeader("Content-Encoding", "compress");
    request->send(response);

    return true;
}

void handleNotFound(AsyncWebServerRequest *request){
    String path = request->url();
    if(loadFromFlash(request)){
        return;
    } else {
        DBG_OUTPUT_PORT.println("load from flash failed");
    }
    String message = "\nNo Handler\r\n";
    message += "URI: ";
    message += request->url();
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
    //DBG_OUTPUT_PORT.print(message);
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
        DBG_OUTPUT_PORT.print("Upload: END, Size: "); DBG_OUTPUT_PORT.println(thisUploadRequest->fileSize);
        uploadRequest* linkUploadRequest = &uploadRequestHead;
        while(linkUploadRequest->next != thisUploadRequest) linkUploadRequest = linkUploadRequest->next;
        linkUploadRequest->next = thisUploadRequest->next;
        delete thisUploadRequest;
    }
}

void handleDelete(AsyncWebServerRequest *request){
    if( ! request->params()) returnFail(request, "No Path");
    String path = request->arg("path");
    if(path == "/")
        returnFail(request, "Invalid Path");
    PINF fInf = getTruePathInfo(path);
    if(!SPIFFS.exists(fInf.path)) {
        returnFail(request, "Bad Path");
    }
    if(SPIFFS.remove(path)) {
        returnOK(request);
    } else {
        returnFail(request, "remove " + fInf.path + " failed");
    }
}

void initDebug() {
    DBG_OUTPUT_PORT.begin(115200);
    delay(1500);
    DBG_OUTPUT_PORT.setDebugOutput(true);
    DBG_OUTPUT_PORT.println("Debug output initialized");
}
void initWifi() {
 #if defined (WIFI_AUTOCONNECT_MODE) || (defined WIFI_CFGPORTAL_MODE)
    AsyncWiFiManager wifiManager(&asyncWebServer, &dnsServer);
#endif
#ifdef WIFI_AUTOCONNECT_MODE
    wifiManager.autoConnect(ssid);
#endif
#ifdef WIFI_CFGPORTAL_MODE
    wifiManager.startConfigPortal(ssid);
#endif
#ifdef WIFI_SOFTAP_MODE
    WiFi.hostname(host);
    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig ( ip, ip, IPAddress ( 255, 255, 255, 0 ) );
    WiFi.softAP(ssid);
    dnsServer.setErrorReplyCode(DNSReplyCode::NoError);
    dnsServer.start ( DNS_PORT, "*", WiFi.softAPIP() ); // captive portal redirect everything to here when in AP mode
#endif
}

void initMDNS() {
    if (MDNS.begin(host)) {
        MDNS.addService("http", "tcp", 80);
        DBG_OUTPUT_PORT.println("MDNS responder started");
        DBG_OUTPUT_PORT.print("You can now connect to http://");
        DBG_OUTPUT_PORT.print(host);
        DBG_OUTPUT_PORT.println(".local");
    }
}
void initWebserver() {
    asyncWebServer.on("/delete", HTTP_DELETE, handleDelete);
    // upload a file to /upload
    asyncWebServer.on("/upload", HTTP_POST, returnOK, handleUpload);
    // Catch-All Handlers
    asyncWebServer.onFileUpload(handleUpload);
    //asyncWebServer.onRequestBody(onBody);

    //Android captive portal. Maybe not needed. Might be handled by notFound handler.
    asyncWebServer.on ( "/generate_204", returnOK );
    //Microsoft captive portal. Maybe not needed. Might be handled by notFound handler.
    asyncWebServer.on ( "/fwlink", returnOK );
    //Microsoft windows 10
    asyncWebServer.on ( "/connecttest.txt", returnOK );
    // apple devices
    asyncWebServer.on ( "/hotspot-detect.html", returnOK );
    asyncWebServer.on ( "/library/test/success.html", returnOK );
    // kindle
    asyncWebServer.on ( "/kindle-wifi/wifistub.html", returnOK );

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
    initMDNS();
    initWebserver();
    initSPIFFS();
    initOTA();
}

void loop() {
    ArduinoOTA.handle();
    dnsServer.processNextRequest();
}
