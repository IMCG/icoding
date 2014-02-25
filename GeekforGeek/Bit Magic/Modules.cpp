N = 87 (1010111 – binary form)

N%2 = N & (2-1) = 1010111 & 1 = 1 = 1

N%4 = N & (4-1) = 1010111 & 11 = 11 = 3

N%8 = N & (8-1) = 1010111 & 111 = 111 = 7

N%16 = N & (16-1) = 1010111 & 1111 = 111 = 7

N%32 = N & (32-1) = 1010111 & 11111 = 10111 = 23

//Note that the technique will work only
// for divisors that are powers of 2

//Add 1 to a given number without operator
//寻找最右侧 1串    Method 1
int addOne(int x)
{
  int m = 1;
 
  /* Flip all the set bits until we find a 0 */
  while( x & m )
  {
    x = x^m;
    m <<= 1;
  }
 
  /* flip the rightmost 0 bit */
  x = x^m;
  return x;
}
//~x=-(x+1)		Method 2
int addOne(int x)
{
   return (-(~x));
}

