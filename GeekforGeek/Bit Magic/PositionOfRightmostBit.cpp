/*Write a one line C function to return position of first 1 from 
right to left, in binary representation of an Integer.*/

#include<stdio.h>
#include<math.h>
 
unsigned int getFirstSetBitPos(int n)
{
	/*Take two's complement of the given no as all bits are reverted
	 *except the first '1' from right to left (10111)
	 */
   return log2(n&-n)+1;
}
 
int main()
{
    int n = 12;
    printf("%u", getFirstSetBitPos(n));
    getchar();
    return 0;
}