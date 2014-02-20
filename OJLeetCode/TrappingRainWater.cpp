/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining. 

For example, 
 Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 

*/
 //容量正好是连个高度差，纵着想一下。
class Solution {
public:
	int trap(int A[], int n) {
		int max = 0;//最高的柱子
		for (int i = 0; i < n;i++)
			if (A[i]>A[max])max = i;
		
		int water = 0;
		for (int i = 0, peak = 0; i < max; i++){
			if (A[i]> peak)peak = A[i];
			else water += peak - A[i];
		}
		for (int i = n - 1, top = 0; i > max; i--){
			if (A[i] > top)top = A[i];
			else water += top - A[i];
		}
		return water;
	}
};