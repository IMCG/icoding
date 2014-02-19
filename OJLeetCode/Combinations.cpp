/*Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>>result;
		if (k == 1){
			for (int i = 1; i <= n; i++)
				result.push_back(vector<int>(1, i));
			return result;
		}
		for (auto& a : combine(n,k-1))
		{
			for (int i = 1; i <= n; i++)
			{
				vector<int>cur = a;
				if (i > cur[cur.size() - 1]){
					cur.push_back(i);
					result.push_back(cur);
				}	
			}
		}
		return result;
    }
};