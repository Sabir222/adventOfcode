#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFile2(const char *filepath) {
  FILE *file;
  char buffer[16];
  char direction[16];
  int units[16];
  int x = 0;
  int y = 0;
  file = fopen(filepath, "r");
  if (file != NULL) {
    while (fgets(buffer, sizeof(buffer), file)) {
      sscanf(buffer, "%s %d", direction, units);
      if (strcmp(direction, "forward") == 0) {
        x += *units;

      } else if (strcmp(direction, "down") == 0) {
        y += *units;
      } else if (strcmp(direction, "up") == 0) {
        y -= *units;
      }
    }
    printf("C day2 part 1 result is : %d\n", x * y);
  } else {
    perror("File not found!");
  }
}

void c_day2_p1() { readFile2("./day2/input.txt"); }
