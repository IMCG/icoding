//count number of 1s in binary representation of an integer.

//Simple Method  Loop through all bits in an integer
/* Function to get no of set bits in binary
   representation of passed binary no. */
int countSetBits(unsigned int n)
{
  unsigned int count = 0;
  while(n)
  {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

//Good Method
/* Function to get no of set bits in binary
   representation of passed binary no. */
int countSetBits(int n)
{
    unsigned int count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
    return count;
}