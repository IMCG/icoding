//http://www.geeksforgeeks.org/find-position-of-the-only-set-bit/
/*Find position of the only set bit*/

#include <stdio.h>
//A utility function to check whether n is power of 2 or not.
int isPowerOfTwo(unsigned n)
{
	return n && (!(n&(n - 1)));
}
//Returns position of the only set bit in 'n'
int findPosition(unsigned n)
{
	if (!isPowerOfTwo(n))
		return -1;
	unsigned i = 1, pos = 1;
	//这种方法好，mask
	while (!(i&n))
	{
		i = i << 1;
		++pos;
	}
	return pos;
}
//One by one move
int findPosition1(unsigned n)
{
	if (!isPowerOfTwo(n))
		return -1;
	unsigned count = 0;
	while (n)
	{
		n = n >> 1;
		count++;
	}
	return count;
}

//use log base 2 to find  递归
unsigned int log2n(unsigned int n)
{
	return (n > 1) ? 1 + log2n(n / 2) : 0;
}
int findPosition2(unsigned n)
{
	if (!isPowerOfTwo(n))
		return -1;
	return log2n(n) + 1;
}
// Driver program to test above function
int main(void)
{
	int n = 0;
	int pos = findPosition(n);
	(pos == -1) ? printf("n = %d, Invalid number\n", n) :
		printf("n = %d, Position %d \n", n, pos);

	n = 12;
	pos = findPosition(n);
	(pos == -1) ? printf("n = %d, Invalid number\n", n) :
		printf("n = %d, Position %d \n", n, pos);

	n = 128;
	pos = findPosition(n);
	(pos == -1) ? printf("n = %d, Invalid number\n", n) :
		printf("n = %d, Position %d \n", n, pos);

	return 0;
}