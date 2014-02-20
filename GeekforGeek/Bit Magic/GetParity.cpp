//Write a C program to find the parity of an unsigned integer
//奇偶校验
#include <stdio.h>
#define bool int

/* Function to get parity of number n. It returns 1
   if n has odd parity, and returns 0 if n has even
   parity */
 bool getParity(unsigned int n)
{
	bool partity=0;
	while(n){
		partity = !partity;	//good
		n=n&(n-1);
	}
	return partity;
}
/* Driver program to test getParity() */
int main()
{
    unsigned int n = 7;
    printf("Parity of no %d = %s",  n, 
             (getParity(n)? "odd": "even"));
     
    getchar();
    return 0;
}