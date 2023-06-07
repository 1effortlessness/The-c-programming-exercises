#include <stdio.h>

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\t");  // print \t instead of tab
        } else if (c == '\b') {
            printf("\\b");  // print \b instead of backspace
        } else if (c == '\\') {
            printf("\\\\"); // print \\ instead of backslash
        } else {
            putchar(c);     // print other characters as they are
        }
    }

    return 0;
}
