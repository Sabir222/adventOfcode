#include <stdio.h>
#include <string.h>
void get_input_d2p2(char *filepath) {
  FILE *file;
  char buffer[32];

  file = fopen(filepath, "r");

  if (file != NULL) {
    for (int index = 0; index < 5; index++) {
      rewind(file);
      int zero = 0;
      int one = 0;
      while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = 0;
        if (buffer[index] == '0') {
          zero++;
        } else if (buffer[index] == '1') {
          one++;
        }
      }
      if (zero > one) {
        printf("0");
      } else if (one > zero) {
        printf("1");
      }
    }

  } else {
    perror("File not found!");
  }
}
