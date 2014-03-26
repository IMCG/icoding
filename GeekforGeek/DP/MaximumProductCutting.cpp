//k 0:n的处理
// A Naive Recursive method to find maxium product
#include <iostream>
using namespace std;
 
//Recursion
// Utility function to get the maximum of two and three integers
int max(int a, int b) { return (a > b)? a : b;}
int max(int a, int b, int c) { return max(a, max(b, c));}
 
// The main function that returns maximum product obtainable
// from a rope of length n
int maxProd(int n)
{
    // Base cases
    if (n == 0 || n == 1) return 0;
 
    // Make a cut at different places and take the maximum of all
    int max_val = 0;
    for (int i = 1; i < n; i++)
      max_val = max(max_val, i*(n-i), maxProd(n-i)*i);
 
    // Return the maximum of all values
    return max_val;
}
//Dp 学习自行画递归图
/*mP() ---> maxProd() 

                            mP(5)
                 /        /      \     \
                /        /        \      \
            mP(4)       mP(3)     mP(2)   mP(1)
           /  |  \       /  \       |
          /   |   \     /    \      |  
     mP(3) mP(2) mP(1) mP(2) mP(1) mP(1)
    / \       |          |
   /   \      |          |   
 mP(2) mP(1) mP(1)      mP(1)
*/
// A Dynamic Programming solution for Max Product Problem
int maxProd(int n)
{
   int val[n+1];
   val[0] = val[1] = 0;
  
   // Build the table val[] in bottom up manner and return
   // the last entry from the table
   for (int i = 1; i <= n; i++)
   {
      int max_val = 0;
      for (int j = 1; j <= i/2; j++)
         max_val = max(max_val, (i-j)*j, j*val[i-j]);
      val[i] = max_val;
   }
   return val[n];
}

//One Tricky solution
/*The maximum product can be obtained be repeatedly cutting parts of size 3 while 
size is greater than 4, keeping the last part as size of 2 or 3 or 4. For example,
 n = 10, the maximum product is obtained by 3, 3, 4. For n = 11, the maximum 
 product is obtained by 3, 3, 3, 2
*/
/* The main function that teturns the max possible product */
int maxProd(int n)
{
   // n equals to 2 or 3 must be handled explicitly
   if (n == 2 || n == 3) return (n-1);
 
   // Keep removing parts of size 3 while n is greater than 4
   int res = 1;
   while (n > 4)
   {
       n -= 3;
       res *= 3; // Keep multiplying 3 to res
   }
   return (n * res); // The last part multiplied by previous parts
}