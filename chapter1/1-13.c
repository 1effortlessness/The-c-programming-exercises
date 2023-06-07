#include <stdio.h>

int main() {
  int c, in_word = 0, word_length = 0;
  int word_length_freq[10] = {0};

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (in_word) {
        if (word_length > 9) {
          word_length_freq[9]++;
        } else {
          word_length_freq[word_length]++;
        }
        in_word = 0;
        word_length = 0;
      }
    } else {
      in_word = 1;
      word_length++;
    }
  }

  printf("Histogram of word lengths:\n");

  for (int i = 1; i <= 9; i++) {
    printf("%2d: ", i);
    for (int j = 0; j < word_length_freq[i]; j += 1) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}
