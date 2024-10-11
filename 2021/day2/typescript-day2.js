"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var path = require("path");
var fs = require("fs");
function getInput(url) {
    var inputPath = path.join(__dirname, url);
    try {
        var input = fs.readFileSync(inputPath, "utf8");
        return input;
    }
    catch (err) {
        throw new Error("Can't read from the file");
    }
}
// the primeagen solution
//function parseLine(line: string): [number, number] {
//	const [dir, a] = line.split(" ");
//	const amount = +a;
//
//	if (dir === "forward") {
//		return [amount, 0]
//	} else if (dir === "up") {
//
//		return [0, -amount]
//	} else {
//		return [0, amount]
//	}
//
//}
function ProcessInput() {
    var point = { x: 0, y: 0 };
    var input = getInput("input.txt").trim().split("\n");
    for (var i = 0; i < input.length; ++i) {
        var p = input[i].split(" ");
        if (p[0] === "forward") {
            point.x += Number(p[1]);
        }
        else if (p[0] === "up") {
            point.y -= Number(p[1]);
        }
        else {
            point.y += Number(p[1]);
        }
    }
    console.log(point.y * point.x);
}
ProcessInput();
