/*Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
//注意 temp 和 result 交换的技巧
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int>> result;
		if (S.size() < 1)
			return result;
		sort(S.begin(), S.end());
		result.push_back(vector<int>());
		vector<vector<int>>temp(result);
		for (auto& a : S)
		{
			for (size_t i = 0; i < temp.size(); i++)
			{
				vector<int>cur = temp[i];
				if (cur.empty())
					cur.push_back(a);
				else if (a >= cur[cur.size() - 1])
					cur.push_back(a);
				if (find(result.begin(), result.end(), cur) == result.end())
					result.push_back(cur);
			}
			temp = result;
		}
		return result;
    }
};