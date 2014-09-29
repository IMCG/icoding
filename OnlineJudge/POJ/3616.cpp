//dp  简单的递推关系好似最长递增子序列
//Wa了好几次.(从M = 0开始，还是从1开始)
//AC
#include <iostream>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)
#define MAX_N 1000005
#define MAX_M 1005
typedef pair<int, int> p2;
typedef pair<p2, int> p3;
p3 vec[MAX_M];
int N, M, R;
//d[i]选到当前最大值
int d[MAX_M];
void solve(){
	sort(vec + 1, vec + M + 1);
	d[0] = 0;
	//int ans = 0;
	for (int i = 1; i <= M; ++i){
		d[i] = vec[i].second;//默认值
		for (int j = 1; j < i; ++j){
			if (vec[j].first.second + R <= vec[i].first.first)
				d[i] = max(d[i],d[j] + vec[i].second);
		}
		//ans = max(ans, d[i]);
	}
	//max_element?必须的.
	cout << *max_element(d + 1, d + M + 1) << "\n";
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	scanf("%d%d%d", &N, &M, &R);
	for (int i = 1; i <= M; ++i)
		scanf("%d%d%d", &vec[i].first.first, 
		&vec[i].first.second, &vec[i].second);
	//
	solve();

	return 0;
}