/*http://www.careercup.com/question?id=5162009297420288
 *write "bool isSplitable(int[] arr)" to return true if the arr can be
 *divided into two parts having the equal sums; return false otherwise.
 */
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
//既是寻找是否有几个数的和是sum/2
int Sum(vector<int>&arr){
	return accumulate(begin(arr), end(arr), 0);
}
bool dfs(vector<int>&arr, int start,int target)
{
	//Base Cases 的考虑
	if (start == arr.size() - 1)
		return target == arr[arr.size() - 1];
	if (arr[start] > target)
		return dfs(arr,start + 1,target);
	return dfs(arr, start + 1, target - arr[start]) ||
		dfs(arr, start + 1, target);
}
bool isSplitable(vector<int>&arr)
{
	int target = Sum(arr) / 2;
	return dfs(arr, 0, target);
}
int main()
{
	vector<int>cur{   };
	cout << isSplitable(cur);
}