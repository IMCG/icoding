//http://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem/
/*Given a set of non-negative integers, and a value sum, determine if 
there is a subset of the given set with sum equal to given sum.*/

#include <iostream>
using namespace std;

/*The isSubsetSum problem can be divided into two subproblems
…a) Include the last element, recur for n = n-1, sum = sum – set[n-1]
…b) Exclude the last element, recur for n = n-1.
If any of the above the above subproblems return true, then return true.*/
//A recursive solution for subset sum problem
bool isSubsetSum(int set[], int n, int sum)
{
	//Base Cases
	if (sum == 0)
		return true;
	if (n == 0 && sum != 0)
		return false;
	//If last element is greater than sum,then ignore it
	if (set[n - 1] > sum)
		return isSubsetSum(set, n - 1, sum);
	/* else, check if sum can be obtained by any of the following
	(a) including the last element
	(b) excluding the last element   */
	return isSubsetSum(set,n-1,sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

/*create a boolean 2D table subset[][] and fill it in bottom up manner. The value of 
subset[i][j] will be true if there is a subset of set[0..j-1] with sum equal to i., 
otherwise false. Finally, we return subset[sum][n]*/
//A Dynamic Programming solution for subset sum problem
bool isSubsetSum1(int set[], int n, int sum)
{
	// The value of subset[i][j] will be true if there is a subset of set[0..j-1]
	//  with sum equal to i
	bool subset[sum + 1][n + 1];

	// If sum is 0, then answer is true
	for (int i = 0; i <= n; i++)
		subset[0][i] = true;

	// If sum is not 0 and set is empty, then answer is false
	for (int i = 1; i <= sum; i++)
		subset[i][0] = false;

	// Fill the subset table in botton up manner
	for (int i = 1; i <= sum; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			subset[i][j] = subset[i][j - 1];
			if (i >= set[j - 1])
				subset[i][j] = subset[i][j] || subset[i - set[j - 1]][j - 1];
		}
	}

	/* // uncomment this code to print table
	for (int i = 0; i <= sum; i++)
	{
	for (int j = 0; j <= n; j++)
	printf ("%4d", subset[i][j]);
	printf("\n");
	} */

	return subset[sum][n];
}
//Driver program to test above function
int main()
{
	int set[] = { 3, 34, 4, 12, 5, 2 };
	int sum= 14;
	int n = sizeof(set) / sizeof(set[0]);
	if (isSubsetSum(set, n, sum) == true)
		printf("Found a subset with given sum");
	else
		printf("No subset with given sum");
	return 0;
}