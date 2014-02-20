/*Given an array of positive integers. All numbers occur even number of 
times except one number which occurs odd number of times. 
Find the number in O(n) time & constant space.*/
#include <stdio.h>
 
int getOddOccurrence(int ar[], int ar_size)
{
     int i;
     int res = 0; 
     for (i=0; i < ar_size; i++)     
        res = res ^ ar[i];
      
     return res;
}
 
/* Diver function to test above function */
int main()
{
     int ar[] = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
     int n = sizeof(ar)/sizeof(ar[0]);
     printf("%d", getOddOccurrence(ar, n));
     return 0;
}