#include <stdio.h>
#define MAX 256

int main() {
  int char_code[MAX];
  int c;
  for (int i = 0; i < MAX; i++) {
    char_code[i] = 0;
  }
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      continue;
    }
    char_code[c]++;
  }
  printf("=== Histogram table ===\n");
  for (int i = 0; i < MAX; i++) {
    int v = char_code[i];
    if (v > 0) {
      printf("%2c: %2d\n", i, v);
    }
  }
  return 0;
}