#include <stdio.h>
#include <stdlib.h>

int *getData(const char *filepath) {
  FILE *file;
  char buffer[16];
  int *array = NULL;
  int size = 0;
  int capacity = 0;
  unsigned char increment = 10;
  int num;
  file = fopen(filepath, "r");
  if (file != NULL) {
    while (fgets(buffer, sizeof(buffer), file)) {
      if (sscanf(buffer, "%d", &num) != 1) {
        printf("Failed to extract number");
        exit(0);
      }
      if (size == capacity) {
        capacity += increment;
        array = realloc(array, capacity * sizeof(int));
        if (array == NULL) {
          perror("Memory allocation failed.");
          fclose(file);
          exit(0);
        }
      }
      array[size++] = num;
    }
    fclose(file);
  } else {
    perror("File not found!");
    exit(0);
  }
  return array;
}
int arr_length(int *arr) {
  int count = 0;
  for (int i = 0; arr[i] != '\0'; i++) {
    count++;
  }
  return count++;
}

int processData(int *data) {
  int result = 0;
  int index = 0;
  int count = 0;
  int length = arr_length(data);

  while (index + 3 < length) {
    if (data[2] == '\0') {
      break;
    }
    int prev = data[index] + data[index + 1] + data[index + 2];
    int curr = data[index + 1] + data[index + 2] + data[index + 3];

    if (curr > prev) {
      result += curr;
      count++;
    }
    index++;
  }
  printf("C day1 part 2 result is : %d\n", count);
  return result;
}

void c_day1_p2() {
  int *data = getData("./day1/input.txt");
  processData(data);
  free(data);
}
