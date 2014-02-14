/*Find the contiguous subarray within an array (containing at least one number) 
which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

/*More practice:
If you have figured out the O(n) solution, try coding another solution 
using the divide and conquer approach, which is more subtle.*/
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = A[0];
		int sum_cur = A[0];
		for (auto i = 1; i < n; i++)
		{
			sum_cur = max(A[i], sum_cur + A[i]);
			sum = max(sum, sum_cur);
		}
		return sum;
    }
};