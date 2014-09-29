//Poj 2456变形题
//关键是怎么抽象出来最大化最小值。。
//逆向考虑，不是删除M个而是  （point）使用N-M。。
//AC
#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
#define MAX_N 50005
int L, N, M;
int dist[MAX_N];
//C(d)N+2-M距离都不小于d
//如果下面没有N++操作的话(最好N++)方便
//每次用到N就的用N+2代替
bool C(int d){
	int k = N - M;//安排k个
	int last = 0;
	for (int i = 1; i < k; i++){
		int crt = last + 1;
		while (crt < N&&dist[crt] - dist[last] < d)
			crt++;
		if (crt == N)return false;
		last = crt;
	}
	return true;
}
void solve(){
	sort(dist, dist + N );
	//init
	int lb = 0, ub = 0x3f3f3f3f;
	while (ub - lb > 1){
		int mid = (ub + lb) / 2;
		if (C(mid))lb = mid;
		else ub = mid;
	}
	printf("%d\n", lb);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	cin >> L >> N >> M;
	for (int i = 1; i <= N; ++i)
		cin >> dist[i];
	++N;
	dist[N] = L;
	++N;
	solve();
	return 0;
}