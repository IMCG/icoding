//Method 1  学会取结果的方法。
#include <stdio.h>
#include <stdlib.h>
 
/* Takes pointer to result and two numbers as
    arguments. If there is no overflow, the function
    places the resultant = sum a+b in “result” and
    returns 0, otherwise it returns -1 */
 int addOvf(int* result, int a, int b)
 {
     *result = a + b;
     if(a > 0 && b > 0 && *result < 0)
         return -1;
     if(a < 0 && b < 0 && *result > 0)
         return -1;
     return 0;
 }
 
 int main()
 {
     int *res = (int *)malloc(sizeof(int));
     int x = 2147483640;
     int y = 10;
 
     printf("%d", addOvf(res, x, y));
 
     printf("\n %d", *res);
     getchar();
     return 0;
}

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
 
int addOvf(int* result, int a, int b)
{
   if( a > INT_MAX - b)
     return -1;
   else
   {
     *result = a + b;
      return 0;
   }
}
 
int main()
{
  int *res = (int *)malloc(sizeof(int));
  int x = 2147483640;
  int y = 10;
 
  printf("%d", addOvf(res, x, y));
  printf("\n %d", *res);
  getchar();
  return 0;
}