const sorter = require("../lib/index.js");
console.log(sorter.addPath([1, 2.99, 3, 0, 50.2, 6.3]) == 1);
console.log(sorter.clear() == 1);
console.log(sorter.addPath([1, 4.99, 3.9, 0, 150.2, 26.3]) == 1);
console.log(sorter.sort());