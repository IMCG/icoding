//Compute the minimum or maximum of two integers without branching

/* The obvious approach to find minimum (involves branching) */
int min(int x, int y)
{
  return (x < y) ? x : y
}
//Method XOR
#include<stdio.h>
 
/*Function to find minimum of x and y*/
//if x < y, then -(x < y) will be all ones, 
//so r = y ^ (x ^ y) & ~0 = y ^ x ^ y = x. 
int min(int x, int y)
{
  return y ^ ((x ^ y) & -(x < y));
}
 
/*Function to find maximum of x and y*/
int max(int x, int y)
{
  return x ^ ((x ^ y) & -(x < y)); 
}
 
/* Driver program to test above functions */
int main()
{
  int x = 15;
  int y = 6;
  printf("Minimum of %d and %d is ", x, y);
  printf("%d", min(x, y));
  printf("\nMaximum of %d and %d is ", x, y);
  printf("%d", max(x, y));
  getchar();
}

//Method 2
