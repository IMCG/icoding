//http://www.geeksforgeeks.org/write-an-efficient-method-to-check-if-a-number-is-multiple-of-3/
//Write an Efficient Method to Check if a Number is Multiple of 3

//Method 1
/* If sum of digits in a number is multiple of 3 then number is multiple of 3 e.g., 
for 612 sum of digits is 9 so it’s a multiple of 3. But this solution is not efficient.
*/

//Method 2
/*There is a pattern in binary representation of the number that can be used to 
find if number is a multiple of 3. If difference between count of odd set bits 
(Bits set at odd positions) and even set bits is multiple of 3 then is the number.

Example: 23 (00..10111)
1) Get count of all set bits at odd positions (For 23 it’s 3).
2) Get count of all set bits at even positions (For 23 it’s 1).
3) If difference of above two counts is a multiple of 3 then number is 
also a multiple of 3.
*/
#include <stdio.h>

/* Fnction to check if n is a multiple of 3*/
int isMultipleOf3(int n)
{
    int odd_count = 0;
    int even_count = 0;
 
    /* Make no positive if +n is multiple of 3
       then is -n. We are doing this to avoid
       stack overflow in recursion*/
    if(n < 0)   n = -n;
    if(n == 0) return 1;
    if(n == 1) return 0;
 
    while(n)
    {
        /* If odd bit is set then
           increment odd counter */
        if(n & 1) 
           odd_count++;
        n = n>>1;
 
        /* If even bit is set then
           increment even counter */
        if(n & 1)
            even_count++;
        n = n>>1;
    }
 
     return isMultipleOf3(abs(odd_count - even_count));
}
 
/* Program to test function isMultipleOf3 */
int main()
{
    int num = 23;
    if (isMultipleOf3(num))    
        printf("num is multiple of 3");
    else
        printf("num is not a multiple of 3");
    getchar();
    return 0;
}