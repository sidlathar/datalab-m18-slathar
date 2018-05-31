//#include "stdio.h"
/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
      However, if you require values larger than this,
      you may build these values using 8-bit constants and allowed operations
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than, or equal to, the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result; 
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. For example: 
-, ==, &&, ||, !=, if, for, and while are all allowed.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting other than implicit casting in conditional 
     comparions and return statements.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
// under constructions
//1
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
  return ~(1 << 31);
}
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  return (~x & ~y);
}
//2
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (least significant) to 3 (most significant)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  return (x >> (n << 3)) & 0xFF;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int mask = (0xAA << 24) | (0xAA << 16) | (0xAA << 8) | 0xAA;

  return !((x & mask) ^ mask);
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) 
{
  int shift = 32 + (~n) + 1;

  int tmp = x << shift;

  int check = tmp >> shift;

  return !(check ^ x);
}
//3
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) 
{
  int res, lower_mask, one0, neg_one, bit_mask;
  
  one0 = (1 << 31);

  neg_one = (one0 >> 31);

  lower_mask = neg_one << lowbit;
  lower_mask = ~lower_mask;

  bit_mask = (1 << highbit);  //bit before leading bit zero

  res = (neg_one << highbit) & ~(bit_mask);
  res = ~(res | lower_mask);

  return res;
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) 
{
  int same_sign = !(((x >> 31) & 0x1) ^ ((y >> 31) & 0x1));

  int x_sign = (x >> 31) & 0x1;

  int res_sign = ((x + y) >> 31) & 0x1;

  return (!same_sign) | !(x_sign ^ res_sign);
}
/*
 * ezThreeFourths - multiplies by 3/4 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/4),
 *   including overflow behavior.
 *   Examples: ezThreeFourths(11) = 8
 *             ezThreeFourths(-9) = -6
 *             ezThreeFourths(1073741824) = -268435456 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */

//Pg 105-106 "Idea of Bias"
int ezThreeFourths(int x) 
{
  int three_times = (x << 1) + x;

  int sign = (three_times >> 31) & 0x1;

  int res = (three_times + ((3) & (sign + (sign << 1)))) >> 2;
  
  return res;
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) 
{
  int ints_equal = !!(x^y);

  int x_most_sig = (x >> 31);

  int y_most_sig = (y >> 31);

  int sub_sign = !(((x + ~(y) + 1) >> 31));
  
  int same_sign = (x_most_sig ^ y_most_sig);

  return (ints_equal) & (((same_sign) & (!x_most_sig)) | ((!same_sign) & (sub_sign)));
}


//4"
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */


/*
IGNORE
11|10|10|01|01|01|00|01|01|10|01|10|00|01|00|10
10|01|01|01|01|01|00|01|01|01|01|01|00|01|00|01|
1001|0101
*/

int bitCount(int x) 
{
  int count = 0;

  int every_other, every_2nd_other, every_4th_other, every_8th_other, every_16th_other;
  every_other = (0x55 << 8) | (0x55);
  every_other |= (every_other << 16);

  every_2nd_other = (0x33 << 8) | (0x33);
  every_2nd_other |=  (every_2nd_other << 16);

  every_4th_other = (0x0F << 8) | (0x0F);
  every_4th_other |= (every_4th_other << 16);

  every_8th_other = (0xFF << 16 | 0xFF);

  every_16th_other = (0xFF << 8 | 0xFF);


  //16 pairs of 2
  count = (x & every_other) + ((x >> 1) & every_other); 
  //8 pairs of 4
  count = (count & every_2nd_other) + ((count >> 2) & every_2nd_other); 
  //4 pairs of 8
  count = (count & every_4th_other) + ((count >> 4) & every_4th_other); 
  //2 pairs of 16
  count = (count & every_8th_other) + ((count >> 8) & every_8th_other);
  //final count (1 pair)
  count = (count & every_16th_other) + ((count >> 16) & every_8th_other);
  
  return count;
}
/*
 * isPallindrome - Return 1 if bit pattern in x is equal to its mirror image
 *   Example: isPallindrome(0x0123C480) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int isPallindrome(int x) 
{
  //Using same logic as bitCount

  int every_other, every_2nd_other, every_4th_other;
  int every_8th_other, every_16th_other, rev, res;
  
  every_other = (0x55 << 8) | (0x55);
  every_other |= (every_other << 16);

  every_2nd_other = (0x33 << 8) | (0x33);
  every_2nd_other |=  (every_2nd_other << 16);

  every_4th_other = (0x0F << 8) | (0x0F);
  every_4th_other |= (every_4th_other << 16);

  every_8th_other = (0xFF << 16 | 0xFF);

  every_16th_other = (0xFF << 8 | 0xFF);

  //reversing bit pattern using same logic as bitcount, | ing istead of add
  //to preseve bits
  
  rev = (every_other      & (x >> 1))        | ((x   & every_other)      << 1);
  //printf("rev %x \n", rev);
  rev = (every_2nd_other  & (rev >> 2))  | ((rev & every_2nd_other)  << 2);
  //printf("rev %x \n", rev);
  rev = (every_4th_other  & (rev >> 4))  | ((rev & every_4th_other)  << 4);
  //printf("rev %x \n", rev);
  rev = (every_8th_other  & (rev >> 8))  | ((rev & every_8th_other)  << 8);
  //printf("rev %x \n", rev);
  rev = (every_16th_other & (rev >> 16)) | ((rev & every_16th_other) << 16);
  //printf("rev %x \n", rev);

  res = !(rev ^ x);
  return res;
}
//float
/* 
 * floatNegate - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatNegate(unsigned uf) 
{
  int mask_neg = 0x80000000;
  int nan_exp = (uf >> 23) & 0xFF;
  int frac =(uf & 0x7FFFFF);

  if(nan_exp == 0xFF && frac != 0) return uf;
  
  return uf ^ mask_neg;
}
/* 
 * floatInt2Float - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatInt2Float(int x) 
{
  int sign;
  int frac;
  int index;
  int tmp;
  
  sign = (x >> 31) & 0x1;
  index = 31;
  tmp = x;

  if(tmp == 0)
  {
    return 0;
  }

  if(tmp < 0)
  {
    tmp = -tmp;
  }

  while(!(tmp >> index)) //check for leading zeros
  {
    index = index - 1;
  }

  //printf("index %d \n", index);

  tmp = tmp << (31 - index);  //remove leading zeros
  index = index + 127;    //add bias to index to get exp
  frac = (tmp & 0x7FFFFFFF) >> 8;

  //rounding, checking last 8 bits
  if ( ((tmp & 0x80) && (tmp & 127) > 0) || (tmp & 128) && (frac & 1) == 1)
  {
    frac = frac + 1;
  }

  return (sign << 31) + (index << 23) + frac;
}
/* 
 * floatScale4 - Return bit-level equivalent of expression 4*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale4(unsigned uf) 
{
  unsigned sign = uf >> 31;
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned frac =(uf & 0x7FFFFF);

  //NaN
  if(exp == 0xFF) 
  {
    return uf;
  }

  //denormalized; close to 0
  else if(exp == 0)
  {
    if(frac <= 0xFFFFF)
    {
      frac = frac << 2;
    }
    else if(frac <= 0x1FFFFF)
    {
      frac = frac << 1;
      exp = exp + 1;
    }
    else
    {
      exp = exp + 2;
      frac = (frac & 0x3FFFFF) << 1;
    }
  }

  //normalized
  else
  {
    if(exp < 0xFD)
    {
      exp += 2;
    }
    else
    {
      exp = 0xFF;
      frac = 0;
    }
  }

  //printf("num %x \n", uf);
  //printf("frac %x \n", frac);

  return (sign << 31) | (exp << 23) | frac;
}
