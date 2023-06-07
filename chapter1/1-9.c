#include <stdio.h>
/* copy input to output; 2nd version  */
#define Blank ' '
int main() {
  int c;
  int temp = 0;

  while ((c = getchar()) != EOF) {
    if (c != Blank) {
      if (temp == Blank) {
        putchar(temp);
        temp = 0;
      }
      putchar(c);
    } else {
      temp = c;
    }
  }
  if (temp == Blank) {
    putchar(temp);
    temp = 0;
  }
  return 0;
}