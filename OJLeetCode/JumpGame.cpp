/*Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/
//DP
class Solution {
public:
    bool canJump(int A[], int n) {
        if (n < 0)return false;
		vector<bool>dp(n, false);
		dp[0] = true;
		for (int i = 1; i < n; i++){
			for (int j = 0; j < i; j++){
				if (dp[j] && A[j] >= i - j){
					dp[i] = true;
					break;
				}
			}
		}
		return dp[n - 1];
    }
};