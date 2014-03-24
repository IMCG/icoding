#include<stdio.h>
 
int fun(int a, int b) 
{
   if (b == 0)
       return 0;
   if (b % 2 == 0)//当是偶数时
       return fun(a+a, b/2);
 
   return fun(a+a, b/2) + a;
}
 
int main()
{
  printf("%d", fun(4, 3));
  getchar();
  return 0;
}
//Output: 12
// It calulates a*b (a multipied b).


// we replace + with * and replace return 0 with return 1,
// 本来就是求power的
#include<stdio.h>
 
int fun(int a, int b)
{
   if (b == 0)
       return 1;
   if (b % 2 == 0)
       return fun(a*a, b/2);
 
   return fun(a*a, b/2)*a;
}
 
int main()
{
  printf("%d", fun(4, 3));
  getchar();
  return 0;
}
// Output: 64
// It calulates a^b (a raised to power b).

#include<stdio.h>
 
 int fun(int n)
 {
   if (n > 100)
     return n - 10;
   return fun(fun(n+11));
 }
 
int main()
{
  printf(" %d ", fun(99));
  getchar();
  return 0;
}
// Output: 91