/*Date:2014/2/14
@Author:icodingc
Given an array S of n integers, are there elements a, b, c in S such that
a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int>> result;
		if (num.size() < 3)
			return result;
		vector<int>tmp;
		sort(num.begin(), num.end());
		auto begin = num.begin();
		auto end = num.end();

		for (auto i = begin; i < prev(end, 2); i = upper_bound(i, prev(end, 2), *i))
		{
			for (auto j = next(i); j < prev(end); j = upper_bound(j, prev(end), *j))
			{
				int target = 0 - *i - *j;
				if (binary_search(next(j), end, target))
					result.push_back(vector<int>{*i, *j, target});
			}
		}
		return result;
	}
};
void Print(vector<vector<int>>&result)
{
	for (auto& a : result)
	{
		cout << "(";
		for (auto& i : a)
		{
			cout << i << " ";
		}
		cout << ")" << endl;
	}
	cout << endl;
}
int main()
{
	vector<int>arr = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>>result;
	Solution s;
	result = s.threeSum(arr);
	cout <<"num="<< result.size() << endl;
	Print(result);
	return 0;
}