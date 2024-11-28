#include <stdio.h>
#include <stdlib.h>

struct {
  char *name;
  int model;
} car;
void readFile(const char *filepath) {
  FILE *fptr;
  int total = 0;
  int previous = 0;
  char buffer[100];

  int *arr = malloc(10 * sizeof(int));
  if (arr == NULL) {
    perror("Memory allocation failed");
    exit(EXIT_FAILURE);
  }

  fptr = fopen(filepath, "r");
  /* checking if there no file*/
  if (fptr != NULL) {
    if (fgets(buffer, 100, fptr) != NULL) {
      previous = atoi(buffer);
    }
    /* reading file lines*/
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
