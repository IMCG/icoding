//http://www.geeksforgeeks.org/count-set-bits-in-an-integer/

//count-set-bits-in-an-integer

//@@1  Loop through all bits in binary
int countSetBits(unsigned int n)
{
	unsigned int count = 0;
	while(n)
	{
		count += n & 1;
		n>>=1;
	}
	return count;
}

//@@2  (good)Subtraction of 1 from a number toggles all the bits
int countSetBits(int n)
{
	unsigned int count = 0;
	while(n)
	{
		n &= (n-1);
		count++;
	}
	return count;
}

//Count number of bits to be flipped to convert A to B
//几次为转换能从A--->B
1. Calculate XOR of A and B.      
        a_xor_b = A ^ B
  2. Count the set bits in the above calculated XOR result.
        countSetBits(a_xor_b)

/* A  = 1001001
   B  = 0010101
   a_xor_b = 1011100
   No of bits need to flipped = set bit count in a_xor_b i.e. 4
*/