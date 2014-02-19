//http://www.geeksforgeeks.org/write-one-line-c-function-to-find-whether-a-no-is-power-of-two/
//Write one line C function to find whether a no is power of two
#include <stdio.h>
#define bool int

//@@1	dividing the number by two
bool isPowerOfTwo(int n)
{
	if(n == 0)
		return 0;
	while(n != 0)
	{
		if( n%2 != 0)
			return 0;
		n/=2;
	}
	return 1;
}
//@@2	All power of two numbers have only one bit set
/*count the number(1)=1;
*/

//@@3
/* If we subtract a power of 2 numbers by 1 then all unset bits after the only set bit become set; and the set bit become unset.

For example for 4 ( 100) and 16(10000), we get following after subtracting 1
3 –> 011
15 –> 01111			n&(n-1)=0;
*/
/* Function to check if x is power of 2*/
bool isPowerOfTwo (int x)
{
  /* First x in the below expression is for the case when x is 0 */
  return x && (!(x&(x-1)));
}
