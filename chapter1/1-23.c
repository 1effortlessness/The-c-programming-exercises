/*
Exercise 1-23. Write a program to remove all comments from a C program. Don't
forget to handle quoted strings and character constants properly. C comments
don't nest.
*/

// fopen open file in read mode
// getc, get a char from a file stream
// fclose, close a file stream after all work done

/* === comments conditions === */
// 1. block comments /* */
// 2. single line comment //
#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_CHAR_NUMBER 1000

void reset_char(char *, int *, int *);
int main() {

  // open file
  FILE *fp = fopen("1-23-test.c", "r");

  if (fp == NULL) {
    printf("Did not find the file\n");
    exit(0);
  }
  // read char in the file
  // print char to stdout
  int c;
  char container[MAX_FILE_CHAR_NUMBER];
  int i = 0;
  while ((c = fgetc(fp)) != EOF && i < MAX_FILE_CHAR_NUMBER) {
    container[i] = c;
    i++;
  }
  if ((c = fgetc(fp) != EOF) && i >= MAX_FILE_CHAR_NUMBER) {
    printf("the length of file content oversize the max length %d\n",
           MAX_FILE_CHAR_NUMBER);
    exit(0);
  }
  int start_comment_index = -1;
  int end_comment_index = -1;
  int block_comment_flag = 0;
  int single_line_comment_flag = 0;
  int in_string = 0;
  for (i = 0; i < MAX_FILE_CHAR_NUMBER; i++) {
    c = container[i];
    if (c == '\0') {
      break;
    } else {
      // block comment
      if (in_string == 0) {
        if (c == '/' && container[i + 1] == '*' && block_comment_flag == 0) {
          start_comment_index = i;
          block_comment_flag = 1;
        } else if (c == '*' && container[i + 1] == '/' &&
                   block_comment_flag == 1) {
          end_comment_index = i + 1;
          reset_char(container, &start_comment_index, &end_comment_index);
          block_comment_flag = 0;
        }

        if (c == '/' && container[i + 1] == '/' &&
            single_line_comment_flag == 0) {
          start_comment_index = i;
          single_line_comment_flag = 1;
        } else if (c == '\n' && single_line_comment_flag == 1 &&
                   start_comment_index != -1) {
          end_comment_index = i;
          reset_char(container, &start_comment_index, &end_comment_index);
          single_line_comment_flag = 0;
        }
      }
      if (c == '"' && in_string == 0) {
        in_string = 1;
      } else if (c == '"' && in_string == 1) {
        in_string = 0;
      }
    }
  }

  printf("%s\n", container);
  // close file
  fclose(fp);
  return 0;
}

void reset_char(char *container, int *start_comment_index,
                int *end_comment_index) {
  int i;
  for (i = *start_comment_index; i <= *end_comment_index; i++) {
    container[i] = ' ';
  }
  *start_comment_index = -1;
  *end_comment_index = -1;
}