//
// Created by swood on 9/13/17.
//

#ifndef _PATHINFO_H
#define _PATHINFO_H
#endif //_PATHINFO_H

#ifndef FS_H
#include <FS.h>
#endif

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

class PathInfo
{
  public:
    PathInfo();
    PINF getPathInfo (String path);
    PINF getTruePathInfo(String fPath);
  private:
    FSInfo fs_info;
};