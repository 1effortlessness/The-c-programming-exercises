#include <stdio.h>
/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */
int fahr_to_celsius(int);
int main() {
  int fahr, celsius;
  int lower, upper, step;
  lower = 0;
  upper = 300;
  step = 20;
  /* lower limit of temperature scale */
  /* upper limit */
  /* step size */
  fahr = lower;
  while (fahr <= upper) {
    celsius = fahr_to_celsius(fahr);
    printf("%d\t%d\n", fahr, celsius);
    fahr = fahr + step;
  }
  return 0;
}

int fahr_to_celsius(int fahr) { return 5 * (fahr - 32) / 9; }