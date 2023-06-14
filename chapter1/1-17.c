// Exercise 1-17. Write a program to print all input lines that are longer than
// 80 characters.
// gpt version:
// https://chat.openai.com/share/f8f58a86-72e6-427b-9973-a0ed9f2493fe

#include <stdio.h>
#include <stdlib.h>

#define MIN_LINE_LENGTH 80
#define MAX_LINE_LENGTH 1000
int get_line(char[], int);
void add_line(char[], char[], int);
int main() {
  printf("=== This program will print all the lines that exceed 80 characters, "
         "exit by CTRL+D ===\n");
  char line[MAX_LINE_LENGTH];
  char *container = malloc(MAX_LINE_LENGTH);
  int line_length = 0;
  int total_length = 0;
  // step - 1, get the line that exceed 80 characters
  while ((line_length = get_line(line, MAX_LINE_LENGTH)) > 0) {
    // step - 2, add it to the container
    if (line_length > MIN_LINE_LENGTH) {
      int current_total_length = total_length;
      total_length += line_length;
      if (total_length > MAX_LINE_LENGTH) {
        container = realloc(container, total_length);
        if (container == NULL) {
          printf("Error: failed to allocate memory");
          return -1;
        }
      }
      add_line(container, line, current_total_length);
    }
  }
  // step - 3, print all the lines in the container one by one
  if (total_length > 0) {
    printf("%s", container);
  }

  // step - 5, handle clean work
  free(container);
  return 0;
}

void add_line(char container[], char line[], int current_length) {
  int i = 0;
  while ((container[current_length + i] = line[i]) != '\0') {
    i++;
  }
  container[++i] = '\0';
}
int get_line(char line[], int max) {
  int c, i;
  for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = c;
    i++;
  }
  line[i] = '\0';
  return i;
}