#include <stdio.h>
#include <stdlib.h>

void readFile(const char *filepath) {
  FILE *fptr;
  int total = 0;
  int previous = 0;
  char buffer[100];
  fptr = fopen(filepath, "r");
  if (fptr != NULL) {
    if (fgets(buffer, 100, fptr) != NULL) {
      previous = atoi(buffer);
    }
    while (fgets(buffer, sizeof(buffer), fptr)) {
      int current = atoi(buffer);
      if (current > previous) {
        total++;
      }

      previous = current;
    }
    fclose(fptr);
    printf("the result: %d\n", total);
  } else {
    perror("File not found!");
  }
}

int main() {
  readFile("input.txt");
  return 0;
}
