"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var fs = require("fs");
var path = require("path");
var processFileInput = function () {
    var input = getInput('input.txt').trim().split("\n").map(Number);
    if (!input) {
        console.error("There's no input to process!");
        return;
    }
    var counter = 0;
    for (var i = 0; i < input.length - 3; ++i) {
        var x = input[i] + input[i + 1] + input[i + 2];
        var y = input[i + 1] + input[i + 2] + input[i + 3];
        if (isNaN(x) || isNaN(y)) {
            break;
        }
        else if (x < y) {
            counter++;
        }
    }
    console.log(counter);
};
var getInput = function (p) {
    var inputPath = path.join(__dirname, p);
    try {
        return fs.readFileSync(inputPath, "utf8");
    }
    catch (err) {
        console.error("Can't read from the file", err);
        return "";
    }
};
processFileInput();
