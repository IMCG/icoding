//http://www.geeksforgeeks.org/swap-two-numbers-without-using-temporary-variable/
/*How to swap two numbers without using a temporary variable*/
#include <cstdio>

//@@Using Arithmetic Operators
void swap1()
{
	int x = 10, y = 5;
	//Code to swap 'x' and 'y'
	x = x + y;
	y = x - y;
	x = x - y;
	printf("After Swapping:x=%d,y=%d", x, y);
	return 0;
}
//Multiplication and division can also be used for swapping
void swap2()
{
	int x = 10, y = 5;
	x = x*y;
	y = x / y;
	x = x / y;
}
//@@Using Bitwise XOR
void swap3()
{
	int x = 10, y = 5;
	//Code to swap 'x'(1010) and 'y'(0101)
	x = x^y;	//x-->1111
	y = x^y;	//y-->1010
	x = x^y;	//x-->0101
}
/************************************************************************/
/* Problem::1.算数运算溢出，2.一个不能为0，3.两个值不能相同*/
/************************************************************************/
/*Bitwise XOR
 *x=x^x;//x-->0
 *x=x^x; remains 0
 *x=x^x; remains 0
 */
void swap(int *a, int *b)
{
	if (a == b)	//Check if the two addresses are same
		return;
	*a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;
}

