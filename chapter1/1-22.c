/*
Exercise 1-22. Write a program to ``fold'' long input lines into two or more
shorter lines after the last non-blank character that occurs before the n-th
column of input. Make sure your program does something intelligent with very
long lines, and if there are no blanks or tabs before the specified column.
*/

#include <stdio.h>
// specify the max length of a line
#define MAX_COLUMN 10
int main() {
  int c;
  int column = 0;
  int last_blank_column = -1;
  while ((c = getchar()) != EOF) {
    // 1, if c is not \n, print c, columns++
    // fold the line if columns > specific column num, recursively
    // 2, if c is \n, print c, columns = 0
    if (c != '\n') {
      if (column < MAX_COLUMN) {
        putchar(c);
        column++;
        if (c != ' ' && c != '\t') {
          last_blank_column = column;
        }
      } else {
        if (last_blank_column == -1) {
          putchar(c);
          putchar('\n');
          column = 0;
        } else {
          putchar('\n');
          putchar(c);
          column = 1;
          last_blank_column = 1;
        }
      }
    } else {
      putchar(c);
      column = 0;
      last_blank_column = -1;
    }
  }
  return 0;
}