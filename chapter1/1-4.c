#include <stdio.h>

int main() {
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;
  printf("=== Celsius => Fahrenheit ===\n");
  while (celsius <= upper) {
    fahr = (9 * celsius) / 5 + 32;
    printf("%3.0f %6.0f\n", celsius, fahr);
    celsius += step;
  }
  return 0;
}