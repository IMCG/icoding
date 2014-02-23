/*Given a collection of candidate numbers (C) and a target number (T), find 
all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. 
(ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/
class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		vector<vector<int>>result;
		vector<int>cur;
		sort(num.begin(), num.end());
		helpSum(num, target, result, cur, 0);
		return result;
	}
	void helpSum(vector<int>&num, int target, vector<vector<int>>&result,
		vector<int>&cur, int start)
	{
		if (target == 0){//找到一个合法解
			if (find(result.begin(), result.end(), cur) == result.end())
				result.push_back(cur);
			return;
		}
		for (size_t i = start; i < num.size(); i++)
		{
			if (num[i] > target)return;//剪枝

			cur.push_back(num[i]);
			helpSum(num, target - num[i], result, cur, i+1);
			cur.pop_back();//恢复环境
		}
	}
};