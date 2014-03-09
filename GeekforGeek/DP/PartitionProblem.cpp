/*Partition problem is to determine whether a given set can be partitioned 
into two subsets such that the sum of elements in both subsets is same.
.............就是寻找是否有subsets==sum/2;
*/
/ A recursive solution for partition problem
#include <stdio.h>
 
// A utility function that returns true if there is a subset of arr[]
// with sun equal to given sum
bool isSubsetSum (int arr[], int n, int sum)
{
   // Base Cases
   if (sum == 0)
     return true;
   if (n == 0 && sum != 0)
     return false;
 
   // If last element is greater than sum, then ignore it
   if (arr[n-1] > sum)
     return isSubsetSum (arr, n-1, sum);
 
   /* else, check if sum can be obtained by any of the following
      (a) including the last element
      (b) excluding the last element
   */
   return isSubsetSum (arr, n-1, sum) || isSubsetSum (arr, n-1, sum-arr[n-1]);
}
 
// Returns true if arr[] can be partitioned in two subsets of
// equal sum, otherwise false
bool findPartiion (int arr[], int n)
{
    // Calculate sum of the elements in array
    int sum = 0;
    for (int i = 0; i < n; i++)
       sum += arr[i];
 
    // If sum is odd, there cannot be two subsets with equal sum
    if (sum%2 != 0)
       return false;
 
    // Find if there is subset with sum equal to half of total sum
    return isSubsetSum (arr, n, sum/2);
}
 
// Driver program to test above function
int main()
{
  int arr[] = {3, 1, 5, 9, 12};
  int n = sizeof(arr)/sizeof(arr[0]);
  if (findPartiion(arr, n) == true)
     printf("Can be divided into two subsets of equal sum");
  else
     printf("Can not be divided into two subsets of equal sum");
  getchar();
  return 0;
}


/*part[i][j] = true if a subset of {arr[0], arr[1], ..arr[j-1]} has sum 
             equal to i, otherwise false*/
// A Dynamic Programming solution to partition problem
#include <stdio.h>
 
// Returns true if arr[] can be partitioned in two subsets of
// equal sum, otherwise false
bool findPartiion (int arr[], int n)
{
    int sum = 0;
    int i, j;
   
    // Caculcate sun of all elements
    for (i = 0; i < n; i++)
      sum += arr[i];
     
    if (sum%2 != 0)  
       return false;
   
    bool part[sum/2+1][n+1];
     
    // initialize top row as true
    for (i = 0; i <= n; i++)
      part[0][i] = true;
       
    // initialize leftmost column, except part[0][0], as 0
    for (i = 1; i <= sum/2; i++)
      part[i][0] = false;     
      
     // Fill the partition table in botton up manner 
     for (i = 1; i <= sum/2; i++)  
     {
       for (j = 1; j <= n; j++)  
       {
         part[i][j] = part[i][j-1];
         if (i >= arr[j-1])
           part[i][j] = part[i][j] || part[i - arr[j-1]][j-1];
       }        
     }    
      
    /* // uncomment this part to print table 
     for (i = 0; i <= sum/2; i++)  
     {
       for (j = 0; j <= n; j++)  
          printf ("%4d", part[i][j]);
       printf("\n");
     } */
      
     return part[sum/2][n];
}     
 
// Driver program to test above funtion
int main()
{
  int arr[] = {3, 1, 1, 2, 2, 1};
  int n = sizeof(arr)/sizeof(arr[0]);
  if (findPartiion(arr, n) == true)
     printf("Can be divided into two subsets of equal sum");
  else
     printf("Can not be divided into two subsets of equal sum");
  getchar();
  return 0;
}

//bitset
#include <iostream>
#include <string>
#include <bitset>
#include <sstream>
using namespace std ;

const int MaxSum = 200 ;

int main()
{
  bitset<MaxSum+1>  b ;
  string  buffer ;
  istringstream os ;
  int   luggage = 0 ;
  int   sum = 0 ;
  int   casenum = 0 ;
  int   i = 0 ;

  cin >> casenum ;
  getline( cin, buffer ) ; // absorb end of line

  for( i = 1 ; i <= casenum ; i++ )
  {
    getline( cin, buffer ) ;
    os.clear() ;
    os.str( buffer ) ;

    sum = 0 ;
    b.reset() ;
    b[ 0 ] = 1 ;
    while( os >> luggage )
    {
      sum += luggage ;
      b |= b << luggage ;
    }

    if( sum % 2 == 0 && b[ sum/2 ] == 1 )
    {
      cout << "YES" << endl ;
    }
    else
    {
      cout << "NO" << endl ;
    }
  }

  return 0 ;
}