#include <stdio.h>
#include "../common/c_getline.h"

int main() {
  char s[] = "xxxx";
  char c;
  int i = 0;
  while ((c = s[i]) != '\0') {
    i++;
  }
  printf("%d\n", i);
  return 0;
}