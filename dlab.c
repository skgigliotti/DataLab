
/* 
 * upperBits - pads n upper bits with 1's
 *  You may assume 0 <= n <= 32
 *  Example: upperBits(4) = 0xF0000000
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 1
 */
int upperBits(int n) {
   //set var y to be either 0 or 1
   //this handles the case where n = 0 
   int y = !!n;

   //shift y all the way to the left
   //y will be 1000... or all 0
   y = y << 31;

   //add shift y to the right n-1 times
   y = y >> (n + ~0);

   return y;
}

int isNotEqual(int x, int y) {
   
  return !(!(x ^ y));
}

/*
 * isZero - returns 1 if x == 0, and 0 otherwise 
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) {
  //if x is 0, !x = 1
  return !x;
}


/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
    //shift x almost all the way to the right
    int y = x >> 30;

    //if x is 1 or -1, z will be 1
    //if x is 0, z will be 0 
    int z = !!x;
    
    //if x is negative, y will be 1111...110 and or with 1 will be -1
    //if x is zero, y will be 0 and or with 0 is 0
    //if x is positive, y will be 0 and or with 1 is 1
    return y|z; 
}

/* 
 * isNegative - return 1 if x < 0, return 0 otherwise 
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) {

  int y = 1;

  //shift 1 to the left
  y = y << 31;
  
  //mask the sign bit of x
  //if this is 1 return 1, else return 0
  return !(!(x & y));
}


/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
  //mask with 1
  //count the number of ones
  //return the count masked with 1
  int count = 0;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  count = count + (x & 1); 
  x = x >> 1;
  return count & 1;
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
int ezThreeFourths(int x) {
  
  int s, r;
  s = (1 << 31);
  r = x >> 31; 
  s = s & x;
  //s = !!s;
  printf("%d \n", s);
  //s = !(!(x >> 31));
  x = x + x + x;
  
  
  x = x >> 2;
  x = x + ~(!r);

  return x;
}

/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
  //0 inverted is -1
  return ~0;
}


/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 * 01000000100001000000000000000000
 * 01000000100100000000000000000000
 * 01000000100110000000000000000000
 */
int float_f2i(unsigned uf) {
  

  return 2;
}

/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  unsigned ret;
  if(uf != uf){
    return uf;
  }
 return 2;
}




int main(int argc, char *argv[]){
  //printf("%d \n", sign(4));
  //printf("%d \n", sign(0));
  printf("%d \n", float_neg(512));
  printf("%d \n", float_neg(-512));
  printf("%d \n", float_neg(-2147483648));
  //printf("%d \n",ezThreeFourths(11));
  //printf("%d \n",ezThreeFourths(-9));
  //printf("%d \n",ezThreeFourths(-2147483648));

}





