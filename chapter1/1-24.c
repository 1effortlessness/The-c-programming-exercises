/*
Exercise 1-24. Write a program to check a C program for rudimentary syntax
errors like unmatched parentheses, brackets and braces. Don't forget about
quotes, both single and double, escape sequences, and comments. (This program is
hard if you do it in full generality.)
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 1000
int read_file_to_container(char *, char *, int);
void clear_comment(char *, int);
int main() {
  // Determine whether it is in the comment
  // Determine whether it is in the escape sequences
  char container[MAX_LENGTH];
  char *filename = "1-23-test.c";
  int read_flag = read_file_to_container(container, filename, MAX_LENGTH);
  if (read_flag == -1) {
    exit(0);
  }
  clear_comment(container, MAX_LENGTH);
  int parentheses_count = 0;
  int brackets_count = 0;
  int braces_count = 0;
  int in_single_quotes = -1; 
  int in_double_quotes = -1; 
  for (int i = 0; i < MAX_LENGTH; i++) {
    if (container[i] == '\0') {
      break;
    }
    int c = container[i];
    if (c == '\'' && in_single_quotes == -1) {
      in_single_quotes = 1;
    } else if (c == '\'' && container[i-1] != '\\' && in_single_quotes == 1) {
      in_single_quotes = -1;
    } else if (c == '"' && in_double_quotes == -1) {
      in_double_quotes = 1;
    } else if (c == '"' && container[i-1] != '\\' && in_double_quotes == 1) {
      in_double_quotes = -1;
    } else if (in_single_quotes == -1 && in_double_quotes == -1) {
      if (c == '(') {
        parentheses_count++;
      } else if (c == ')') {
        parentheses_count--;
      } else if (c == '[') {
        brackets_count++;
      } else if (c == ']') {
        brackets_count--;
      } else if (c == '{') {
        braces_count++;
      } else if (c == '}') {
        braces_count--;
      }
    }
  }
  
  if (parentheses_count != 0) {
    printf("parentheses not match\n");
  }
  if (brackets_count != 0) {
    printf("brackets not match\n");
  }
  if (braces_count != 0) {
    printf("braces not match\n");
  }
  if (parentheses_count == 0 && brackets_count == 0 && braces_count == 0) {
    printf("all match\n");
  }
  return 0;
}

/*
  Read file from memory, and store it in the container
  return -1 if the file is oversize the max length or not found
  return 1 if the file is read successfully
*/
int read_file_to_container(char *container, char *filename, int max_length) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Did not find the file\n");
    return -1;
  }
  int c;
  int i = 0;
  while ((c = fgetc(fp)) != EOF && i < max_length) {
    container[i] = c;
    i++;
  }
  if ((c = fgetc(fp) != EOF) && i >= max_length) {
    printf("the length of file content oversize the max length %d\n",
           max_length);
    return -1;
  }
  return 1;
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
/*
  clear comment in the container
*/
void clear_comment(char *container, int MAX_FILE_CHAR_NUMBER) {
  int start_comment_index = -1;
  int end_comment_index = -1;
  int block_comment_flag = 0;
  int single_line_comment_flag = 0;
  int in_string = 0;
  int c, i;
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
}