/*
Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.

raw code:
for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
       s[i] = c;
*/
#include <stdio.h>

int main() {
  int lim = 10;
  int c;
  for (int i = 0; ((i < lim -1) + ((c = getchar()) != '\n') + (c != EOF)) == 3 ;i++) {
    putchar(c);
  }
  
  return 0;
}