/*
Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. Explain why. Use this observation to write a faster version of bitcount.
*/

// x = x & (x - 1)
// actual example
// x = 0b1011
// x - 1 = 0b1010
// x & (x-1) = 0b1010
// x = 0b1010
// x - 1 = 0b1001
// x & (x-1) = 0b1000
// explain reason why...thinking...
/*
In a two's complement number system, the operation x &= (x-1) indeed deletes the rightmost 1-bit in x. Here's why:

Let's consider a number x in binary representation. The rightmost 1-bit in x means it's the least significant 1-bit.

Now, when we subtract 1 from x (x-1), what happens is that the least significant 1-bit in x becomes 0, and all the bits to the right of it become 1 (if there are any). This is because subtracting 1 essentially "borrows" from the least significant 1-bit, flipping it and all lesser significant bits.

When we perform a bitwise AND operation (&) between x and x-1, the only bit that can differ between these two numbers is the rightmost 1-bit in x, which is now 0 in x-1. Since 1 AND 0 equals 0, this bit becomes 0 in the result. All bits to the right of this (if any) are 0 in x and 1 in x-1, so they also result in 0. All bits to the left are the same in both numbers, so they remain the same in the result.

So, x &= (x-1) effectively removes the rightmost 1-bit in x.

For example, let's take x = 12, which is 1100 in binary:

Subtract 1 from x to get x-1 = 11, which is 1011 in binary.
Perform x & (x-1), which is 1100 & 1011 = 1000 in binary, or 8 in decimal. As you can see, the rightmost 1-bit in x has been removed.
*/
int bitcount(unsigned x) {
  int n = 0;
  while (x != 0) {
    x &= (x - 1);
    n++;
  }
  return n;
}