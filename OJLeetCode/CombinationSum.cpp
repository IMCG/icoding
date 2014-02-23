/*Given a set of candidate numbers (C) and a target number (T), find all unique 
combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. 
(ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/
class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<vector<int>>result;//结果
		sort(candidates.begin(), candidates.end());
		vector<int>cur;//中间值
		helpSum(candidates, result, cur, target,0);
		return result;
	}
	void helpSum(vector<int>&candidates,vector<vector<int>>&result,
		vector<int>&cur, int target,int start){//加入start为了去重复
		if (target == 0){//终止条件
			result.push_back(cur);
			return;
		}
		for (size_t i = start; i < candidates.size(); i++)//扩张状态
		{
			if (target < candidates[i])return;//剪枝

			cur.push_back(candidates[i]);//扩展动作
			helpSum(candidates, result, cur, target - candidates[i],i);
			cur.pop_back();//回溯
		}
	}
};