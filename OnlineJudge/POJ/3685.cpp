//POJ 3685 Matrix
//暴力搜索不行，找地方二分
//用ll代替所有int 免的精度麻烦
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
#pragma warning(disable:4996)
const int mx = 50006;
#define forn(i,n) for(int i=0;i<n;++i)

ll f(const ll& i, const ll& j){
	return i * i + 100000 * i + j * j - 100000 * j + i * j;
}
ll n, m, t;
//以mid为M-th是否合适，查看小于mid的个数
//矩阵中存在单调性
bool judge(ll mid){
	ll cnt = 0;
	//对每个纵列搜索
	for (ll j = 1; j < n + 1; ++j){
		ll l = 0, r = n + 1;
		while (l + 1 < r){
			ll i = (l + r) >> 1;
			f(i, j) < mid ? l = i : r = i;
		}
		cnt += l;
	}
	return cnt < m;
}
void solve(){
	ll l = -100000 * n, r = 3 * n*n + 100000 * n;
	while (l + 1 < r){
		ll k;
		judge(k = (l + r) >> 1) ? l = k : r = k;
	}
	printf("%lld\n", l);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	scanf("%d\n", &t);
	while (t--){
		scanf("%d %d\n", &n, &m);
		solve();
	}
	return 0;
}