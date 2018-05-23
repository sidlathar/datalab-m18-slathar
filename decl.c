#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TMin INT_MIN
#define TMax INT_MAX

#include "btest.h"
#include "bits.h"

test_rec test_set[] = {
// under constructions
//1
 {"tmax", (funct_t) tmax, (funct_t) test_tmax, 0, "! ~ & ^ | + << >>", 4, 1,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"bitNor", (funct_t) bitNor, (funct_t) test_bitNor, 2, "& ~", 8, 1,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
//2
 {"getByte", (funct_t) getByte, (funct_t) test_getByte, 2,
    "! ~ & ^ | + << >>", 6, 2,
  {{TMin, TMax},{0,3},{TMin,TMax}}},
 {"allOddBits", (funct_t) allOddBits, (funct_t) test_allOddBits, 1,
    "! ~ & ^ | + << >>", 12, 2,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"fitsBits", (funct_t) fitsBits, (funct_t) test_fitsBits, 2,
    "! ~ & ^ | + << >>", 15, 2,
  {{TMin, TMax},{1,32},{TMin,TMax}}},
//3
 {"bitMask", (funct_t) bitMask, (funct_t) test_bitMask, 2,
    "! ~ & ^ | + << >>", 16, 3,
  {{0, 31},{0,31},{TMin,TMax}}},
 {"addOK", (funct_t) addOK, (funct_t) test_addOK, 2,
    "! ~ & ^ | + << >>", 20, 3,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
 {"ezThreeFourths", (funct_t) ezThreeFourths, (funct_t) test_ezThreeFourths, 1,
    "! ~ & ^ | + << >>", 12, 3,
  {{TMin,TMax},{TMin,TMax},{TMin,TMax}}},
 {"isGreater", (funct_t) isGreater, (funct_t) test_isGreater, 2,
    "! ~ & ^ | + << >>", 24, 3,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
//4"
 {"bitCount", (funct_t) bitCount, (funct_t) test_bitCount, 1, "! ~ & ^ | + << >>", 40, 4,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
{"isPallindrome", (funct_t) isPallindrome, (funct_t) test_isPallindrome, 1, "! ~ & ^ | + << >>", 40, 4,
 {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
//float
 {"floatNegate", (funct_t) floatNegate, (funct_t) test_floatNegate, 1,
    "$", 10, 2,
     {{1, 1},{1,1},{1,1}}},
 {"floatInt2Float", (funct_t) floatInt2Float, (funct_t) test_floatInt2Float, 1,
    "$", 30, 4,
     {{1, 1},{1,1},{1,1}}},
 {"floatScale4", (funct_t) floatScale4, (funct_t) test_floatScale4, 1,
    "$", 30, 4,
     {{1, 1},{1,1},{1,1}}},
  {"", NULL, NULL, 0, "", 0, 0,
   {{0, 0},{0,0},{0,0}}}
};
