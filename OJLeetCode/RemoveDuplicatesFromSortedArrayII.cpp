/*For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
What if duplicates are allowed at most twice*/
class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n == 0)return 0;
		int index = 0;
		int cur = 1;
		for (int i = 0; i < n; i++)
		{
			if (A[index] == A[i]){
				if (cur < 2){
					A[++index] = A[i];
					cur++;
					}
				}
				else{
					A[++index] = A[i];
					cur = 1;
				}
		}
		return index + 1;
	}
};