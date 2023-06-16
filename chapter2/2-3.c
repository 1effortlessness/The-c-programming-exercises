/*
Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal
digits (including an optional 0x or 0X) into its equivalent integer value. The
allowable digits are 0 through 9, a through f, and A through F.
*/

#include <ctype.h>
#include <stdio.h>
int htoi(char *s);
int main() {
  char *test = "0x1234";
  htoi(test);
  return 0;
}

int htoi(char *s) {
  if (s[0] != '0' && (s[1] != 'x' || s[1] != 'X')) {
    printf("Invalid hex number\n");
    return -1;
  }
  int i, n = 0; 
  for (i = 2; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') ||
              (s[i] >= 'A' && s[i] <= 'Z');
       i++) {
    int c = tolower(s[i]);
    if (c >= '0' && c <= '9') {
      n = 16 * n + (c - '0');
    } else if (c >= 'a' && c <= 'z') {
      n = 16 * n + (c - 'a' + 10);
    }
  }
  return n;
}
