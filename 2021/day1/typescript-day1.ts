import * as fs from "fs";
import * as path from "path";

const processFileInput = () => {
  let input = getInput("input.txt").trim().split("\n").map(Number);

  if (!input) {
    console.error("There's no input to process!");
    return;
  }

  let counter = 0;

  for (let i = 0; i < input.length - 3; ++i) {
    let x = input[i] + input[i + 1] + input[i + 2];
    let y = input[i + 1] + input[i + 2] + input[i + 3];

    if (isNaN(x) || isNaN(y)) {
      break;
    } else if (x < y) {
      counter++;
    }
  }

  console.log(counter);
};

const getInput = (p: string): string => {
  const inputPath = path.join(__dirname, p);

  try {
    return fs.readFileSync(inputPath, "utf8");
  } catch (err) {
    console.error("Can't read from the file", err);
    return "";
  }
};

processFileInput();
