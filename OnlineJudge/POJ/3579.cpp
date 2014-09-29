//POJ 3579 Median
#include <iostream>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)
#define fon(i,a,b)for(int i=a;i<b;++i)
#define forn(i,n) fon(i,0,n)
const int mx = 100006;
typedef long long ll;
int a[mx];
int n;
ll k;
//双二分 妙用 cnt即bigger_count
bool judge(int mid){
	ll cnt = 0;
	forn(i, n)
		cnt += a + n - lower_bound(a + i + 1, a + n, a[i] + mid);
	ll k = n*(n - 1) / 2;
	//bigger_count太大，要增加mid
	return cnt >= k / 2 + 1;
}
void solve(){
	int m2 = *max_element(a, a + n);
	int l = -1, r = m2;
	int m;
	while (l + 1 < r){
		judge(m = (l + r) >> 1) ? l = m : r = m;
	}
	printf("%d\n", l);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	while (cin >> n){
		forn(i, n)
			scanf("%d", a + i);
		sort(a, a + n);
		solve();
	}
	return 0;
}


//必然TLE？
vector<int>e;
int main(){
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	while (cin >> n){
		//clear
		e.clear();
		forn(i, n)
			cin >> a[i];
		forn(i, n)
			fon(j, i + 1, n)
			e.push_back(abs(a[i] - a[j]));
		sort(e.begin(), e.end());
		int num = e.size();
		printf("%d\n", num & 1 ? e[num / 2] : e[num / 2 - 1]);
	}
	return 0;
}

