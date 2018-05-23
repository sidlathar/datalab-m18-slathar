/* Testing Code */

#include <limits.h>
#include <math.h>

/* Routines used by floation point test code */

/* Convert from bit level representation to floating point number */
float u2f(unsigned u) {
  union {
    unsigned u;
    float f;
  } a;
  a.u = u;
  return a.f;
}

/* Convert from floating point number to bit-level representation */
unsigned f2u(float f) {
  union {
    unsigned u;
    float f;
  } a;
  a.f = f;
  return a.u;
}

// under constructions
//1
int test_tmax(void) {
  return 0x7FFFFFFF;
}
int test_bitNor(int x, int y)
{
  return ~(x|y);
}
//2
int test_getByte(int x, int n)
{
    unsigned char byte;
    switch(n) {
    case 0:
      byte = x;
      break;
    case 1:
      byte = x >> 8;
      break;
    case 2:
      byte = x >> 16;
      break;
    default:
      byte = x >> 24;
      break;
    }
    return (int) (unsigned) byte;
}
int test_allOddBits(int x) {
  int i;
  for (i = 1; i < 32; i+=2)
      if ((x & (1<<i)) == 0)
   return 0;
  return 1;
}
int test_fitsBits(int x, int n)
{
  int TMin_n = (-1) << (n-1);
  int TMax_n = -(TMin_n + 1);
  return x >= TMin_n && x <= TMax_n;
}
//3
int test_bitMask(int highbit, int lowbit)
{
  int result = 0;
  int i;
  for (i = lowbit; i <= highbit; i++)
    result |= 1 << i;
  return result;
}
int test_addOK(int x, int y)
{
    long long lsum = (long long) x + y;
    return lsum == (int) lsum;
}
int test_ezThreeFourths(int x)
{
  return (x*3)/4;
}
int test_isGreater(int x, int y)
{
  return x > y;
}
//4"
int test_bitCount(int x) {
  int result = 0;
  int i;
  for (i = 0; i < 32; i++)
    result += (x >> i) & 0x1;
  return result;
}
int test_isPallindrome(int x) {
    int result = 1;
    int i;
    int mask = 0xFFFF;
    int xlo = x & mask;
    int xhi = (x >> 16) & mask;
    for (i = 0; i < 16; i++) {
 int flipi = 15-i;
 int bhigh = (xhi >> i) & 0x1;
 int blow = (xlo>> flipi) & 0x1;
 result = result && (bhigh == blow);
    }
    return result;
}
//float
unsigned test_floatNegate(unsigned uf) {
    float f = u2f(uf);
    float nf = -f;
    if (isnan(f))
 return uf;
    else
 return f2u(nf);
}
unsigned test_floatInt2Float(int x) {
  float f = (float) x;
  return f2u(f);
}
unsigned test_floatScale4(unsigned uf) {
  float f = u2f(uf);
  float tf = 4*f;
  if (isnan(f))
    return uf;
  else
    return f2u(tf);
}
