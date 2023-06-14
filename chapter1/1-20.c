/*

Exercise 1-20. Write a program detab that replaces tabs in the input with the
proper number of blanks to space to the next tab stop. Assume a fixed set of tab
stops, say every n columns. Should n be a variable or a symbolic parameter?
*/
#include <stdio.h>
#define TAB_STOP 4
int detab(int tab_stop, int column);
int main() {
  int c;
  int column = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      detab(TAB_STOP, column);
    } else if (c == '\n') {
      putchar(c);
      column = 0;
    } else {
      putchar(c);
      column++;
    }
  }
  return 0;
}

int detab(int tab_stop, int column) {
  int space_count = tab_stop - (column % tab_stop);
  while (space_count > 0) {
    putchar(' ');
    space_count--;
  }
  return space_count;
}
