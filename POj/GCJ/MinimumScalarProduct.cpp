/*
GCJ Minimum Scalar Product
来自：挑战程序设计2.7
eg.1 v1{1,3,-5}
	 v2{-2,4,1}      min = -25;
eg.2 v1{1,2,3,4,5}
	 v2{1,0,1,0,1}   min = 6;
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <functional>
using namespace std;
#define all(a)	a.begin(),a.end()
//暴力搜索 small
int solve(vector<int>&a, vector<int>&b){
	int res = numeric_limits<int>::max();
	int temp;
	do{
		do{
			temp = inner_product(a.begin(), a.end(), b.begin(), 0);
			res = min(temp, res);

		} while (next_permutation(b.begin(), b.end()));
	} while (next_permutation(a.begin(), a.end()));
	return res;
}
//large  v1 增序   v2 降序
//all(a) 宏
typedef long long ll;
ll solve1(vector<int>&a, vector<int>&b){
	sort(all(a));
	sort(all(b), greater<int>());
	return inner_product(all(a), b.begin(), 0);
}

int main()
{
	vector<int>a{ 1, 2, 3, 4, 5 };
	vector<int>b{ 1, 0, 1, 0, 1 };
	printf("%d\n", solve1(a, b));
	return 0;
}