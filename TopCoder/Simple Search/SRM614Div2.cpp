//MinimumSquareEasy
//http://community.topcoder.com/stat?c=problem_statement&pm=12982
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//search 循环遍历删除2个节点。注意i，j的顺序
int minArea(vector<int>x, vector<int>y){
	int n = x.size();
	vector<int>xx, yy;
	vector<int>res;
	//int a, b;
	for (int i = 0; i < n - 1; ++i){
		for (int j = i + 1; j < n; ++j){
			xx = x, yy = y;
			xx.erase(xx.begin() + j);
			xx.erase(xx.begin() + i);
			yy.erase(yy.begin() + j);
			yy.erase(yy.begin() + i);
			auto m1 = minmax_element(xx.begin(), xx.end());
			auto m2 = minmax_element(yy.begin(), yy.end());
			if (*m1.second - *m1.first + 2>*m2.second - *m2.first + 2)
				res.push_back(*m1.second - *m1.first + 2);
			else
				res.push_back(*m2.second - *m2.first + 2);
		}
	}
	return (int)pow(*min_element(res.begin(), res.end()), 2);
}
int main()
{


	vector<int>x{ -1, -1, 0, 2, 0 };
	vector<int>y{ -2, -1, 0, -1, -2 };
	cout << minArea(x, y) << "\n";
}