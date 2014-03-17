/*Given a set of numbers, find the Length of the Longest Arithmetic Progression (LLAP) in it.

Examples:

set[] = {1, 7, 10, 15, 27, 29}
output = 3
The longest arithmetic progression is {1, 15, 29}

set[] = {5, 10, 15, 20, 25, 30}
output = 6
The whole set is in AP
*/

//A simple eg

#include <stdio.h>
// The function returns true if there exist three elements in AP
// Assumption: set[0..n-1] is sorted. 
// The code strictly implements the algorithm provided in the reference.
bool arithmeticThree(int set[], int n)
{
    // One by fix every element as middle element
    for (int j=1; j<n-1; j++)
    {
        // Initialize i and k for the current j
        int i = j-1, k = j+1;
 
        // Find if there exist i and k that form AP
        // with j as middle element
        while (i >= 0 && k <= n-1)
        {
            if (set[i] + set[k] == 2*set[j])
                return true;
            (set[i] + set[k] < 2*set[j])? k++ : i–;
        }
    }
 
    return false;
}


// Returns length of the longest AP subset in a given set
int lenghtOfLongestAP(int set[], int n)
{
    if (n <= 2)  return n;
 
    // Create a table and initialize all values as 2. The value of
    // L[i][j] stores LLAP with set[i] and set[j] as first two
    // elements of AP. Only valid entries are the entries where j>i
    int L[n][n];
    int llap = 2;  // Initialize the result
 
    // Fill entries in last column as 2. There will always be
    // two elements in AP with last number of set as second
    // element in AP   			前两个元素
    for (int i = 0; i < n; i++)
        L[i][n-1] = 2;
 
    // Consider every element as second element of AP
    //固定的是前两个元素，所以从后往前。
    for (int j=n-2; j>=1; j--)
    {
        // Search for i and k for j
        int i = j-1, k = j+1;
        while (i >= 0 && k <= n-1)
        {
           if (set[i] + set[k] < 2*set[j])
               k++;
 
           // Before changing i, set L[i][j] as 2
           else if (set[i] + set[k] > 2*set[j])
           {   L[i][j] = 2, i--;   }
 
           else
           {
               // Found i and k for j, LLAP with i and j as first two
               // elements is equal to LLAP with j and k as first two
               // elements plus 1. L[j][k] must have been filled
               // before as we run the loop from right side
               L[i][j] = L[j][k] + 1;
 
               // Update overall LLAP, if needed
               llap = max(llap, L[i][j]);
 
               // Change i and k to fill more L[i][j] values for
               // current j
               i--; k++;
           }
        }
 
        // If the loop was stopped due to k becoming more than
        // n-1, set the remaining entties in column j as 2
        while (i >= 0)
        {
            L[i][j] = 2;
            i--;
        }
    }
    return llap;
}

/* Drier program to test above function*/
int main()
{
    int set1[] = {1, 7, 10, 13, 14, 19};
    int n1 = sizeof(set1)/sizeof(set1[0]);
    cout <<   lenghtOfLongestAP(set1, n1) << endl;
 
    int set2[] = {1, 7, 10, 15, 27, 29};
    int n2 = sizeof(set2)/sizeof(set2[0]);
    cout <<   lenghtOfLongestAP(set2, n2) << endl;
 
    int set3[] = {2, 4, 6, 8, 10};
    int n3 = sizeof(set3)/sizeof(set3[0]);
    cout <<   lenghtOfLongestAP(set3, n3) << endl;
 
    return 0;
}