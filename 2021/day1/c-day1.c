#include <stdio.h>

const char *readFile(const char *filepath) {

  FILE *file = fopen(filepath, "r");
  if (file == NULL) {
    perror("Error opening the file");
    return NULL;
  }

  fseek(file, 0, SEEK_END);
  long filesize;
  fseek(file, 0, SEEK_SET); // Reset to the beginning of the file

  return "input";
}

int main() { return 0; }
