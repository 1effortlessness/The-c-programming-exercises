#include <stdio.h>
int c_getline(char line[], int max_line_length) {
  int i, c;
  for (i = 0; i < max_line_length && ((c = getchar()) != EOF) && c != '\n'; i++) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = '\n';
    ++i;
  }
  line[i] = '\0';
  return i;
}