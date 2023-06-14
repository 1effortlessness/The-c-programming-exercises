/*
Exercise 1-18. Write a program to remove trailing blanks and tabs from each line
of input, and to delete entirely blank lines.
*/

#include <stdio.h>
#define MAX_LINE_LENGTH 1000
int get_line(char[], int);
int main() {
  char line[MAX_LINE_LENGTH];
  int line_length = 0;
  while ((line_length = get_line(line, MAX_LINE_LENGTH)) > 0) {
    int i = line_length - 2;
    while (i >= 0 && (line[i] == ' ' || line[i] == '\t')) {
      i--;
    }
    if (i >= 0) {
      line[++i] = '\n';
      line[++i] = '\0';
      printf("%s", line);
    }
  }
  return 0;
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