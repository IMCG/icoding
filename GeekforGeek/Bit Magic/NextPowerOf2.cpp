//http://www.geeksforgeeks.org/next-power-of-2/
/*Write a function that, for a given no n, finds a number p which is g
 *reater than or equal to n and is a power of 2.
 */

 //Method 1 Using log of the number
 	1. Calculate Position of set bit in p(next power of 2):
        pos =  ceil(lgn)  (ceiling of log n with base 2)
    2.  Now calculate p:
        p   = pow(2, pos) 

 //Method 2 By getting the position of only set bit in result
 unsigned int nextPowerOf2(unsigned int n)
{
	unsigned count=0;
	//?power of 2
	if(n&&!(n&(n-1)))
		return n;
	while(n!=0){
		n>>=1;
		count++;
	}
	return 1<<count;
}
 //Method 3 Shift result one by one
 unsigned int nextPowerOf2(unsigned int n)
 {
 	unsigned int p=1;
 	if(n&&!(n&(n-1)))
 		return n;
 	while(p<n)
 	{
 		p<<=1;
 	}
 	return p;
 }

 //Method 4 Customized and Fast	后面的都置为1s
 # include <stdio.h>
 
/* Finds next power of two for n. If n itself
   is a power of two then returns n*/
 
 /* Below solution works only if integer is 32 bits */
unsigned int nextPowerOf2(unsigned int n)
{
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}
 
/* Driver program to test above function */
int main()
{
    unsigned int n = 5;
    printf("%d", nextPowerOf2(n));
 
    getchar();
    return 0;
 
}