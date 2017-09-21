function SVGPathSort() {
    const self = this;
    const node = require("../build/Release/path_sort.node");

    self.sort = function() {
        return node.sortPaths();
    };
    self.addPath = function(points) {
        var len = points.length / 3;
        return node.addPath(points, len);
    };
    return self;
}
module.exports = new SVGPathSort();