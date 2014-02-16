/*Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int>>result;

		gene(numRows, 1, result);
		return result;
	}
	void gene(int numRows, size_t level, vector<vector<int>>&result)
	{
		if (numRows == 0)
			return;
		if (level>result.size())
			result.push_back(vector<int>());
		if (level == 1)
			result[level - 1].push_back(1);
		else
		{
			result[level - 1].push_back(1);
			for (size_t i = 0; i<result[level - 2].size() - 1; i++)
			{
				result[level - 1].push_back(result[level - 2][i] + result[level - 2][i + 1]);
			}
			result[level - 1].push_back(1);
		}
		gene(numRows - 1, level + 1, result);
	}
};
void print(vector<vector<int>>&v)
{
	for (auto& a : v)
	{
		for (auto& i : a)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int main()
{
	Solution s;
	vector<vector<int>>result = s.generate(6);
	print(result);

	return 0;
}