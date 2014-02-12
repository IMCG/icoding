/*There are two sorted arrays A and B of size m and n respectively.
 Find the median of the two sorted arrays.
 The overall run time complexity should be O(log (m+n)).

  Solution: 1. O(m+n)
            2. O(log(m+n))
*/

#include <iostream>
#include <algorithm>
using namespace std;
//Median  k in sorted arrays.
class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
        return findMedianSortedArrays_1(A, m, B, n);
    }

    double findMedianSortedArrays_1(int A[], int m, int B[], int n) {
        int i = 0, j = 0;
        int m1 = 0, m2 = 0;
        int total = m + n;

        for (int k = 0; k <= total / 2; ++k)
        {
            int a = (i == m) ? INT_MAX : A[i];
            int b = (j == n) ? INT_MAX : B[j];

            m1 = m2;
            m2 = min(a, b);

            if (a < b) i++;
            else j++;
        }
        if (total & 0x1) return m2;
        else return (m1 + m2) / 2.0;
    }
};

/*写一个递归函数，什么时候终止呢。
1。当A 或者 B空。
2. k=1.
3.A[k/2-1]=B[k/2-1];

*/
class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int total = m + n;
		if (total & 0x1)
			return find_kth(A, m, B, n, total / 2 + 1);
		else
			return (find_kth(A, m, B, n, total / 2) + find_kth(A, m, B, n, total / 2 + 1)) / 2;
	}
private:
	static double find_kth(int A[], int m, int B[], int n, int k)
	{
		//always assume that m is equal or smaller than n
		if (m > n) return find_kth(B, n, A, m, k);
		if (m == 0)return B[k - 1];
		if (k == 1) return min(A[0], B[0]);

		//divide k into two parts
		int pa = min(k / 2, m), pb = k - pa;  //pa+pb=k...
		if (A[pa - 1] < B[pb - 1])
			return find_kth(A + pa, m - pa, B, n, k-pa);
		else if (A[pa - 1]>B[pb - 1])
			return find_kth(A, m, B + pb, n - pb, k-pb);
		else
			return A[pa - 1];
	}
};

//http://leetcode.com/2011/03/median-of-two-sorted-arrays.html
//Median of Two Sorted Arrays
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;
double findMedianSingleArray(int A[], int n){
	assert(n > 0);
	return ((n % 2 == 1) ? A[n / 2] : (A[n / 2 - 1] + A[n / 2]) / 2.0);
}
double findMedianSortedArrays(int A[], int m, int B[], int n)
{
	assert(m + n >= 1);
	if (m == 0)
		return findMedianSingleArray(B, n);
	else if (n == 0)
		return findMedianSingleArray(A, m);
	
	int i = m / 2, j = n / 2, k;
	if (A[i] <= B[j]){
		k = ((m % 2 == 0) ? min(i - 1, n - j - 1) : min(i, n - j - 1));
		//assert(k > 0);
		return findMedianSortedArrays(A + k, m - k, B, n - k);
	}
	else{
		k = ((n % 2 == 0) ? min(m - i - 1, j - 1) : min(m - i - 1, j));
		//assert(k > 0);
		return findMedianSortedArrays(A, m - k, B + k, n - k);
	}

}
int main()
{
	int A[] = { 1, 2, 4, 8, 9, 10 };
	int B[] = { 3, 5, 6, 7 };
	double result = findMedianSortedArrays(A, 6, B, 4);
	cout << result;
}

