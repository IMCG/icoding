//http://www.geeksforgeeks.org/dynamic-programming-set-28-minimum-insertions-to-form-a-palindrome/

//Minimum insertions to form a palindrome

/*Recursive Solution
The minimum number of insertions in the string str[l…..h] can be given as:
minInsertions(str[l+1…..h-1]) if str[l] is equal to str[h]
min(minInsertions(str[l…..h-1]), minInsertions(str[l+1…..h])) + 1 otherwise
*/
// A Naive recursive program to find minimum number insertions
// needed to make a string palindrome

#include <stdio.h>
#include <limits.h>
#include <string.h>

// A utility function to find minimum of two numbers
int min(int a, int b)
{
	return a < b ? a : b;
}

// Recursive function to find minimum number of insersions
int findMinInsertions(char str[], int l, int h)
{
	// Base Cases
	if (l > h) return INT_MAX;
	if (l == h) return 0;
	if (l == h - 1) return (str[l] == str[h]) ? 0 : 1;

	// Check if the first and last characters are same. On the basis of the
	// comparison result, decide which subrpoblem(s) to call
	return (str[l] == str[h]) ? findMinInsertions(str, l + 1, h - 1) :
		(min(findMinInsertions(str, l, h - 1),
		findMinInsertions(str, l + 1, h)) + 1);
}

// Driver program to test above functions
int main()
{
	char str[] = "geeks";
	printf("%d", findMinInsertions(str, 0, strlen(str) - 1));
	return 0;
}

//Dynamic Programming based Solution  (overlapping subproblems.)
//用一个表格存储起来子问题。
// A Dynamic Programming based program to find minimum number
// insertions needed to make a string palindrome
#include <stdio.h>
#include <string.h>
 
// A utility function to find minimum of two integers
int min(int a, int b)
{   return a < b ? a : b;  }
 
// A DP function to find minimum number of insersions
int findMinInsertionsDP(char str[], int n)
{
    // Create a table of size n*n. table[i][j] will store
    // minumum number of insertions needed to convert str[i..j]
    // to a palindrome.
    int table[n][n], l, h, gap;
 
    // Initialize all table entries as 0
    memset(table, 0, sizeof(table));
 
    // Fill the table（弄懂为什么会这么fill the table）
    for (gap = 1; gap < n; ++gap)
        for (l = 0, h = gap; h < n; ++l, ++h)
            table[l][h] = (str[l] == str[h])? table[l+1][h-1] :
                          (min(table[l][h-1], table[l+1][h]) + 1);
 
    // Return minimum number of insertions for str[0..n-1]
    return table[0][n-1];
}
 
// Driver program to test above function.
int main()
{
    char str[] = "geeks";
    printf("%d", findMinInsertionsDP(str, strlen(str)));
    return 0;
}


// An LCS based program to find minimum number insertions needed to
// make a string palindrome
#include<stdio.h>
#include <string.h>
 
/* Utility function to get max of 2 integers */
int max(int a, int b)
{   return (a > b)? a : b; }
 
/* Returns length of LCS for X[0..m-1], Y[0..n-1]. 
   See http://goo.gl/bHQVP for details of this function */
int lcs( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;
 
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
 
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
 
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
 
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}
 
// LCS based function to find minimum number of insersions
int findMinInsertionsLCS(char str[], int n)
{
   // Creata another string to store reverse of 'str'
   char rev[n+1];
   strcpy(rev, str);
   strrev(rev);
 
   // The output is length of string minus length of lcs of
   // str and it reverse
   return (n - lcs(str, rev, n, n));
}
 
// Driver program to test above functions
int main()
{
    char str[] = "geeks";
    printf("%d", findMinInsertionsLCS(str, strlen(str)));
    return 0;
}