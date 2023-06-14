/*
Exercise 1-19. Write a function reverse(s) that reverses the character string s.
Use it to write a program that reverses its input a line at a time.
*/
#include "../common/c_getline.h"
#include <stdio.h>

#define MAX_LINE_LENGTH 1000
void reverse_line(char[], int line_length);
int main() {
  char line[MAX_LINE_LENGTH];
  int line_length = 0;
  while ((line_length = c_getline(line, MAX_LINE_LENGTH)) > 0) {
    reverse_line(line, line_length);
  }
  return 0;
}

void reverse_line(char line[], int line_length) {
  int valid_str_length = line_length - 2; // omit '\n' and '\0'
  if (valid_str_length > 0) {
    int i = valid_str_length;
    char reverse_line[line_length];
    while (i >= 0) {
      reverse_line[valid_str_length - i] = line[i];
      i--;
    }
    reverse_line[++valid_str_length] = '\n';
    reverse_line[++valid_str_length] = '\0';
    printf("%s", reverse_line);
  }
}