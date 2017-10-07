/**
 * gzipper class wrapper for node.js gzip.js library.
 *   enable for use in a browser by using node / npm and browserify.
 *   Once npm is installed install gzip-js with 'npm install gzip-js'
 *   Install browserify globally with 'npm install -g browserify' (may need administrator privileges)
 *   then turn this function into browser compatible code with:
 *
 *   browserify gzipper_node.js -o gzipper.js
 */
gzipper = function() {
    /**
     * gzip node.js instance handle
     * @type {object}
     */
    this.gzip = require('gzip-js');
    /**
     * default compression level (0-9)
     * @type {number}
     */
    this.level = 9;
    /**
     * retrieve a timestamp for use in the options
     *
     * @returns {Number}
     */
    this.getTimestamp = function() { return parseInt(Date.now() / 1000, 10);};
    /**
     * get the option string for gzip.zip();
     *
     * @param {string} filename
     * @returns {{level: number, name: *, timestamp: Number}}
     */
    this.getOptions = function(filename) {
        var opts = {
            level: this.level,
            name: filename,
            timestamp: this.getTimestamp()
        };
        return opts;
	};
    /**
     * gzip compress a string/variable and returns it as an array
     *
     * @param {string} content
     * @param {string} filename
     * @returns {*}
     */
	this.zipstr = function(content, filename) {
	    var opts = this.getOptions(filename);
    	return this.gzip.zip(content, opts);
	};
    /**
     * gzip compress a string/variable and return it as a File object
     *
     * @param {string} content
     * @param {string} filename
     * @returns {*}
     */
	this.zipfile = function(content, filename) {
	    var opts = this.getOptions(filename);
	    var sZip = this.zipstr(content, filename);
        var sFile = new File([new Blob([sZip])], filename + '.gz')
        return sFile;
    }
};
