#include <stdio.h>
#define NewLine '\n'
#define Blank ' '
#define TableChar '\t'
int main() {
  int c, n;
  n = 0;
  while ((c = getchar()) != EOF) {
    if (
        // meet equal condition
        c == NewLine || c == Blank || c == TableChar) {
      n++;
    }
  }
  printf("total num: %d\n", n);
  return 0;
}