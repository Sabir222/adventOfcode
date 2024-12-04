
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFile3(const char *filepath) {
  FILE *file;
  char buffer[16];
  char direction[16];
  int units[16];
  int x = 0;
  int y = 0;
  int aim = 0;
  file = fopen(filepath, "r");
  if (file != NULL) {
    while (fgets(buffer, sizeof(buffer), file)) {
      sscanf(buffer, "%s %d", direction, units);
      if (strcmp(direction, "forward") == 0) {
        x += *units;
        y += aim * *units;

      } else if (strcmp(direction, "down") == 0) {
        // y += *units;
        aim += *units;
      } else if (strcmp(direction, "up") == 0) {
        // y -= *units;
        aim -= *units;
      }
    }
    printf("C day2 part 2 result is : %d\n", x * y);
  } else {
    perror("File not found!");
  }
}

void c_day2_p2() { readFile3("./day2/input.txt"); }
