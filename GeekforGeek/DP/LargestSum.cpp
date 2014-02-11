//http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
//Maximum subarray problem
1>
//Initialize:
	max_so_far = 0;
	max_ending_here = 0;
//Loop for each element
	for each int i in vector
		max_ending_here += i;
	if(max_ending_here < 0)
		max_ending_here = 0;
	if(max_ending_here > max_so_far)
		max_so_far = max_ending_here;
return max_so_far;

#include<stdio.h>
int maxSubArraySum(int a[], int size)
{
   int max_so_far = 0, max_ending_here = 0;
   int i;
   for(i = 0; i < size; i++)
   {
     max_ending_here = max_ending_here + a[i];
     if(max_ending_here < 0)
        max_ending_here = 0;

     /* Do not compare for all elements. Compare only   
        when  max_ending_here > 0 */
     else if (max_so_far < max_ending_here)
         max_so_far = max_ending_here;

     if(max_so_far < max_ending_here)
        max_so_far = max_ending_here;
    }
    return max_so_far;
} 
 
/*Driver program to test maxSubArraySum*/
int main()
{
   int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = maxSubArraySum(a, n);
   printf("Maximum contiguous sum is %d\n", max_sum);
   getchar();
   return 0;
}
2>

#include<stdio.h>
 
int max(int x, int y)
{ return (y > x)? y : x; }
 
int maxSubArraySum(int a[], int size)
{
   int max_so_far = a[0], i;
   int curr_max = a[0];
 
   for (i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}
 
/* Driver program to test maxSubArraySum */
int main()
{
   int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = maxSubArraySum(a, n);
   printf("Maximum contiguous sum is %d\n", max_sum);
   return 0;
}