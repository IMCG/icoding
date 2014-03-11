//其实就是最长递增子序列
#include <stdio.h>
#include <stdlib.h>
 
// Structure for a pair
struct pair
{
  int a;
  int b;
};
 //已经排序		小数字	
// This function assumes that arr[] is sorted in increasing order
// according the first (or smaller) values in pairs.
int maxChainLength( struct pair arr[], int n)
{
   int i, j, max = 0;
   int *mcl = (int*) malloc ( sizeof( int ) * n );
 
   /* Initialize MCL (max chain length) values for all indexes */
   for ( i = 0; i < n; i++ )
      mcl[i] = 1;
 
   /* Compute optimized chain length values in bottom up manner */
   for ( i = 1; i < n; i++ )
      for ( j = 0; j < i; j++ )
         if ( arr[i].a > arr[j].b && mcl[i] < mcl[j] + 1)
            mcl[i] = mcl[j] + 1;
 
   // mcl[i] now stores the maximum chain length ending with pair i
 
   /* Pick maximum of all MCL values */
   for ( i = 0; i < n; i++ )
      if ( max < mcl[i] )
         max = mcl[i];
 
   /* Free memory to avoid memory leak */
   free( mcl );
 
   return max;
}
 
 
/* Driver program to test above function */
int main()
{
    struct pair arr[] = { {5, 24}, {15, 25},
                          {27, 40}, {50, 60} };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of maximum size chain is %d\n",
           maxChainLength( arr, n ));
    return 0;
}
//C++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int>MyP;
int maxChainLength(vector<MyP>&cur)
{
  const int m = cur.size();
  vector<int>dp(m, 1);
  for (int i = 1; i < m; i++){
    for (int j = 0; j < i; j++){
      if (cur[i].first>cur[j].second && dp[i] < dp[j] + 1)
        dp[i] = dp[j] + 1;
    }
  }
  return *max_element(dp.begin(),dp.end());
}
int main()
{
  int S[4] = { 5, 15, 27, 50 };
  int T[4] = { 10, 25, 40, 60 };
  vector<MyP>cur(4);
  for (size_t i = 0; i < cur.size(); i++){
    cur[i].first = S[i];
    cur[i].second = T[i];
  }
  /*排序时按second 就用贪心算法。
  int ans = 0, t = 0;//t是最后所选工作结束时间
  for (auto& a : cur)
  {
    if (a.second>t){
      ans++;
      t = a.first;
    }
  }
  cout << ans;
  */
  sort(cur.begin(), cur.end());
  int len = maxChainLength(cur);
  cout << len << endl;
  return 0;
}


//贪心算法 排序大数字。
#include<stdio.h>
 
// Prints a maximum set of activities that can be done by a single
// person, one at a time.
//  n   -->  Total number of activities
//  s[] -->  An array that contains start time of all activities
//  f[] -->  An array that contains finish time of all activities
void printMaxActivities(int s[], int f[], int n)
{
    int i, j;
 
    printf ("Following activities are selected \n");
 
    // The first activity always gets selected
    i = 0;
    printf("%d ", i);
 
    // Consider rest of the activities
    for (j = 1; j < n; j++)
    {
      // If this activity has start time greater than or equal to the finish
      // time of previously selected activity, then select it
      if (s[j] >= f[i])
      {
          printf ("%d ", j);
          i = j;
      }
    }
}
 
// driver program to test above function
int main()
{
    int s[] =  {1, 3, 0, 5, 8, 5};
    int f[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);
    printMaxActivities(s, f, n);
    getchar();
    return 0;
}