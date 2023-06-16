/*
Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.
*/

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {
  // test setbits
  unsigned x = 0b11111111;
  unsigned y = 0b00000000;
  printf("%u\n", setbits(x, 3, 3, y));
  return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  // step 1, get the rightmost n bits of y with other bits set to 0
  unsigned y_rightmost_n_bits = y & ~(~0 << n);
  // step 2, shift the rightmost n bits of y to the left by p + 1 - n bits
  unsigned y_shifted = y_rightmost_n_bits << (p + 1 - n);
  // step 3, get the mask bits of x
  unsigned x_mask = ~(~(~0 << n) << (p + 1 - n));
  // step 4, set x's mask bits to 0
  unsigned x_masked = x & x_mask;
  // step 5, combine x_masked and y_shifted
  return x_masked | y_shifted;
}