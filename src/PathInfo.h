//
// Created by swood on 9/13/17.
//

#ifndef _PATHINFO_H
#define _PATHINFO_H
#endif //_PATHINFO_H

class PathInfo
{
  public:
    PathInfo(String path) { _initFromPath(path); };
    PathInfo(String dir, String base, String ext, String enc, String type, bool min) { _initFromVals(dir, base, ext, enc, type, min); };
    PathInfo(String dir, String base, String ext, String enc, bool min) { _initFromVals(dir, base, ext, enc, "", min); };
    PathInfo(String dir, String base, String ext) { _initFromVals(dir, base, ext, "", "", false); };
    String buildRealName();
    String getAlias();
    String buildRealPath();
    String getAliasPath();
    String extEncoding(String ex);

    bool isGZipped() { return ((_enc == "gzip") || (_ext == "gz") || (_type == "application/gzip")); };
    bool isCompressed() { return ((_enc == "compress") || (_ext == "Z") || (_type == "application/zlib")); };

    String getPath() { return _path; };
    String getDir()  { return _dir;  };
    String getName() { return _name; };
    String getBase()  { return _base;  };
    String getExt()  { return _ext; };
    String getEnc()  { return _enc; };
    String getType() { return _type; };
    bool isMinified() { return _min; };
    String infoJSON();
  private:
    void _initFromPath(String path);
    void _initFromVals(String dir, String base, String ext, String enc, String type, bool min);
    String _path = "";
    String _dir = "";
    String _name = "";
    String _base = "";
    String _ext = "";
    String _enc = "";
    String _type = "application/octet-stream";
    bool _min = false;
};