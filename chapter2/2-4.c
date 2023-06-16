/*
Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2.
*/

/*
void squeeze(char s[], int c)
{
int i, j;
      for (i = j = 0; s[i] != '\0'; i++)
          if (s[i] != c)
              s[j++] = s[i];
      s[j] = '\0';
}
*/

#include <stdio.h>

int include_char(char *s, int c);
void squeeze(char s1[], char s2[]);
int main() {
  char s1[] = "hello world";
  char s2[] = "he";
  squeeze(s1, s2);
  printf("%s\n", s1);
  return 0;
}

int include_char(char *s, int c) {
  int i;
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] == c)
      return 1;
  }
  return -1;
}

void squeeze(char * s1, char * s2) {
  int i, j;
  for (i = j = 0; s1[i] != '\0'; i++) {
    if (include_char(s2, s1[i]) == -1) {
      s1[j++] = s1[i];
    }
  }
  s1[j] = '\0';
}