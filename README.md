# ESPAsyncFlashWebServer
Modifications and enhancements to the ESPAsyncSDWebServer to run from Flash filesystem

I created this to make it easier to serve files from an ESP8266 without the need to have to add an SD card to the SPI and thus require additional hardware to serve basic websites, but still be able to serve vibrant content by including larger helper files such as jquery.js or bootstrap which often fail or are slow in serving with the standard web asyncWebServer.

I had to do some adjustments to the SD webserver code, such as removing the deleteRecursive method as the SPIFFS filesystem is not truely directory oriented. (files are flatfiles but can include directory separators in the name and it does have openDir to emulate directory listings based on the use of these separators).
The existing delete handler was changed to a /delete url for better clarity. Uploading was also changed to /upload and I added support for including a GET parameter in the url for 'dir' to specify a path to pre-pend onto the filename.

Since I wanted to speed up delivery of content as well as reduce the size in the Flash/SPIFFS filesystem, I added support for serving 7-bit content as gzipped data. I also added in support to do something similar to speling apache modules specifically for files with ".min" in the filename (such as javascript, css or html) and for any files ending in .gz.

There is a limitation in the SPIFFS filesystem in that filenames including the pseudopath must be 32 characters or less. This code tries to check that both when checking substitutions and when uploading a file with the "dir" prefix.

I've added extra data directory examples. data_small is an example for something such as a esp-01 with a minimal toolkit. I managed to also shrink a version of the widg editor down as small as possible in data_widg including embedding it's icons into the css as data urls to avoid exceeding the 5 maximum connections of the device. data_markitup is a work-in-progress of doing the same thing with the MarkItUp editor, but I'm not sure if I can get it small enough to fit on an '01.

What I presently do is symlink the directory I want as a starting point to 'data' before running an uploadfs to a given target. 