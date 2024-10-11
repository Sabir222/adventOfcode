import * as path from "path"
import * as fs from "fs"




type Direction = {
	x: number
	y: number
}

function getInput(url: string): string {

	const inputPath = path.join(__dirname, url);
	try {

		const input = fs.readFileSync(inputPath, "utf8");
		return input;

	} catch (err) {
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



function ProcessInput(something) {

	const point: Direction = { x: 0, y: 0 };
	const input = getInput("input.txt").trim().split("\n");

	for (let i = 0; i < input.length; ++i) {
		let p = input[i].split(" ");

		if (p[0] === "forward") {
			point.x += Number(p[1]);
		} else if (p[0] === "up") {
			point.y -= Number(p[1]);
		} else {
			point.y += Number(p[1]);
		}
	}

	console.log(point.y * point.x);

}



ProcessInput()

