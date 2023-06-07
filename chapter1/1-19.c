#include <stdio.h>
#include <stdlib.h>

int get_line(char *[], int *);
void copy_str(char[], char[]);
int main() {
  // init the array to store the line input by user
  int default_max_line_length = 100;
  char *line = malloc(default_max_line_length);
  char *longest = malloc(default_max_line_length);
  int line_length = 0;
  int max_length = 0;
  while ((line_length = get_line(&line, &default_max_line_length)) > 0) {
    if (line_length > max_length) {
      max_length = line_length;
      longest = realloc(longest, max_length);
      if (longest == NULL) {
        // handle the error
        return -1;
      }
      copy_str(longest, line);
    }
  }
  if (max_length > 0) {
    // print longest
    printf("%s", longest);
  }
  // free the allocated memory
  free(line);
  free(longest);
  return 0;
}

void copy_str(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') {
    i++;
  }
}

int get_line(char *line[], int *max_line_length) {
  int c, i;
  for (i = 0; i < *max_line_length - 1 && (c = getchar()) != EOF && c != '\n';
       i++) {
    // if the line length close the max line length, realloc the line size by
    // adding 100
    if (i == *max_line_length - 1) {
      *max_line_length += 100;
      *line = realloc(*line, *max_line_length);
      if (*line == NULL) {
        // handle the error
        return -1;
      }
    }
    (*line)[i] = c;
  }
  if (c == '\n') {
    (*line)[i] = c;
    i++;
  }
  // add the null terminator
  (*line)[i] = '\0';

  return i;
}