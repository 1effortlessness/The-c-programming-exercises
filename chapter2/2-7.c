/*
Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
*/

#include <stdio.h>
unsigned invert(unsigned x, int p, int n);
int main() {
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
unsigned invert(unsigned x, int p, int n) {
  // step 1, get the rightmost n bits of x with other bits set to 0
  unsigned x_rightmost_n_bits = x & ~(~0 << n);
  // step 2, invert the rightmost n bits
  unsigned x_inverted = ~x_rightmost_n_bits;
  return setbits(x, p, n, x_inverted);
}