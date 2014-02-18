/*Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		vector<vector<int>>result;
		sort(S.begin(), S.end());
		for (auto& i : S)
		{
			result.push_back(vector<int>(1, i));
		}
		for (auto& a : S)
		{
			
			//int j = 0;
			for (size_t i = 0; i < result.size(); i++)
			{
				//j = result.size();
				vector<int>cur = result[i];
				if (a>cur[cur.size() - 1])
				{
					cur.push_back(a);
					result.push_back(cur);
				}
			}
		}
		result.push_back(vector<int>());
		return result;
	}
};
void print(vector<vector<int>>&result)
{
	for (auto& a : result)
	{
		cout << "[";
		for (auto& i : a)
		{
			cout << i << " ";
		}
		cout << "]";
		cout << endl;
	}
}
int main()
{
	Solution s;
	vector<int>str{ 1, 2, 3 };
	vector<vector<int>>result = s.subsets(str);
	cout << "size=" << result.size() << endl;
	print(result);
	return 0;
}