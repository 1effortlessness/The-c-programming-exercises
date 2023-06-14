/*
Exercise 1-23. Write a program to remove all comments from a C program. Don't
forget to handle quoted strings and character constants properly. C comments
don't nest.
*/

// fopen open file in read mode
// getc, get a char from a file stream
// fclose, close a file stream after all work done
#include <stdio.h>
#include <stdlib.h>

int main() {

  // open file
  FILE *fp = fopen("hello.c", "r");
  char *test = "1234 [ // s";
  char c = '(';
  if (fp == NULL) {
    printf("Did not find the file\n");
    exit(0);
  }
  // read char in the file
  // print char to stdout
  while ((c = getc(fp)) != EOF) {
    putchar(c);
  }
  printf("%s\n", test);
  // close file
  fclose(fp);
  return 0;
}
