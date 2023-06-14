/*
Exercise 1-21. Write a program entab that replaces strings of blanks by the
minimum number of tabs and blanks to achieve the same spacing. Use the same tab
stops as for detab. When either a tab or a single blank would suffice to reach a
tab stop, which should be given preference?
*/

#include <stdio.h>
#define TAB_STOP 4
int entab(int blank_count, int);
int main() {
  // step1, initialize variables, includes char, blank count
  int c, blank_count = 0;
  // step2, enter the input mode
  while ((c = getchar()) != EOF) {
    // 2.1 if char is not blank, print it
    // 2.1.1 print the remaining blank, reset blank count to 0
    // 2.2 if char is blank, blank count add 1
    // 2.3 if char is \n,  reset blank count to 0
    if (c == ' ') {
      blank_count++;
    } else if (c == '\n') {
      putchar(c);
      blank_count = 0;
    } else {
      blank_count = entab(blank_count, TAB_STOP);
      putchar(c);
    }
  }
  return 0;
}

int entab(int blank_count, int tab_stop) {
  int tab_count = 0;
  // step1, calculate the tab count
  while (blank_count > 0) {
    if (blank_count >= tab_stop) {
      tab_count++;
      blank_count -= tab_stop;
    } else {
      break;
    }
  }
  // step2, calculate the blank count
  // step3, print the tab and blank
  while (tab_count > 0) {
    putchar('\t');
    tab_count--;
  }
  while (blank_count > 0) {
    putchar(' ');
    blank_count--;
  }
  // step4, reset the blank count
  return 0;
}