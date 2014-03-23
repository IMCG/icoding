//have bug
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
	vector<vector<int>>Combinate(vector<int>&t, int r)
	{
		sort(t.begin(), t.end());
		vector<vector<int>>result;
		vector<int>cur;
		dfs(result, cur, t, 0, r);
		return result;
	}
private:
	void dfs(vector<vector<int>>&result, vector<int>&cur,
		vector<int>&t,int begin,int r)
	{
		const int k = t.size();
		if (cur.size() == r){
			result.push_back(cur);
			return;
		}
		if (begin == r)
			return;
		//判断是否为空是关键。否则就会溢出
		for (int i = begin; i < k; i++){
			if (!cur.empty()){
				if (t[i] <= cur.back())
					continue;
			}
			cur.push_back(t[i]);
			dfs(result, cur, t, begin + 1, r);
			cur.pop_back();
		}
		return;
	}
};
void print(vector<vector<int>>&result){
	for (auto& i : result)
	{
		for (auto& a : i)
		{
			cout << a << " ";
		}
		cout << endl;
	}
}
int main()
{
	vector<int>t{ 1, 2, 3, 4 };
	Solution s;
	vector<vector<int>>result = s.Combinate(t, 2);
	print(result);
	

	return 0;
}
