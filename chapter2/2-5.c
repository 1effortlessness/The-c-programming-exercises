/*
Exercise 2-5. Write the function any(s1,s2), which returns the first location in
a string s1 where any character from the string s2 occurs, or -1 if s1 contains
no characters from s2. (The standard library function strpbrk does the same job
but returns a pointer to the location.)

*/
#include <stdio.h>
int any(char[], char[]);

int main() {
  char s1[] = "hello world";
  char s2[] = "wr";
  printf("%d\n", any(s1, s2));
  return 0;
}

int include(char s[], int c) {
  int i;
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] == c)
      return 1;
  }
  return -1;
}
int any(char s1[], char s2[]) {
  int i;
  for (i = 0; s1[i] != '\0'; i++) {
    if (include(s2, s1[i]) == 1)
      return i;
  }
  return -1;
}
