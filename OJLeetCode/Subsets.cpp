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

//深度优先 每个元素选或者不选
class Solution{
public:
	vector<vector<int>>subsets(vector<int>&S){
		sort(S.begin(), S.end());

		vector<vector<int>>result;
		vector<int>path;
		subsets(S, path, 0, result);
		return result;
	}
private:
	static void subsets(vector<int>&S, vector<int>&path,
		int start, vector<vector<int>>&result)
	{
		if (start == S.size()){
			result.push_back(path);
			return;
		}
		//不选S[start]
		subsets(S, path, start + 1, result);
		//选S[start]
		path.push_back(S[start]);
		subsets(S, path, start + 1, result);
		path.pop_back();
	}
};
//开一个位向量，每个元素可选可不选
class Solution1{
public:
	vector<vector<int>>subsets(vector<int>&S){
		sort(S.begin(), S.end());

		vector<vector<int>>result;
		vector<bool>selected(S.size(), false);
		subsets(S, selected, 0, result);
		return result;
	}
private:
	static void subsets(vector<int>&S, vector<bool>&selected,
		int start, vector<vector<int>>&result)
	{
		if (start == S.size()){
			vector<int>sub;
			for (size_t i = 0; i < S.size(); i++){
				if (selected[i])
					sub.push_back(S[i]);
			}
			result.push_back(sub);
			return;
		}
        //不选
		selected[start] = false;
		subsets(S, selected, start + 1, result);
		//选
		selected[start] = true;
		subsets(S, selected, start + 1, result);
	}
};
//迭代
class Solution2{
public:
	vector<vector<int>>subsets(vector<int>&S){
		sort(S.begin(), S.end());
		vector<vector<int>>result(1);
		for (auto elem : S){
			result.reserve(result.size() * 2);
			auto half = result.begin() + result.size();
			copy(result.begin(), half, back_inserter(result));
			for_each(half, result.end(), [&elem](decltype(result[0]) &e)
			{e.push_back(elem); });
		}
		return result;
	}
};