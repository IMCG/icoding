//最大化最小值.二分搜索
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100005
#pragma warning(disable:4996)
int N, C;
int dist[MAX_N];
bool meet(int d){
	int last = 0;
	for (int i = 1; i < C; ++i){
		int crt = last + 1;
		while (crt < N&&dist[crt] - dist[last] < d)
			crt++;
		if (crt == N)return false;
		last = crt;
	}
	return true;
}
void solve(){
	sort(dist, dist + N);
	int lb = 0, ub = 0x3f3f3f3f;
	while (ub - lb>1){
		int mid = (ub + lb) / 2;
		if (meet(mid))lb = mid;
		else ub = mid;
	}
	printf("%d\n", lb);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	cin >> N >> C;
	for (int i = 0; i < N; ++i)
		cin >> dist[i];
	solve();
	return 0;
}