#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

void read_file_day3_p1(char *filepath) {
  FILE *file;
  char buffer[32];
  char gamma[13] = {0};
  char eplision[13] = {0};

  file = fopen(filepath, "r");
  if (file != NULL) {
    for (int index = 0; index < 12; index++) {
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
        gamma[index] = '0';
        eplision[index] = '1';
      } else if (one > zero) {
        gamma[index] = '1';
        eplision[index] = '0';
      }
    }

    int gammaDecimal = strtol(gamma, NULL, 2);
    int eplisionDecimal = strtol(eplision, NULL, 2);

    printf("C day3 part 1 result is : %d\n", gammaDecimal * eplisionDecimal);

  } else {
    perror("File not found!");
  }
}
void c_day3_p1() { read_file_day3_p1("./day3/input.txt"); }
