//最大化平均值
//最后再乘以100
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning(disable:4996)
#define forn(i,n) for(int i=0;i<n;++i)
#define eps 1e-7
const int mx = 1006;
int a[mx], b[mx];
int n, k;
double y[mx];
bool judge(double x){
	forn(i, n)
		y[i] = a[i] - x*b[i];
	sort(y, y + n,greater<double>());
	double sum = 0;
	forn(i, n - k)
		sum += y[i];
	//> >= 都可以
	return sum >= 0;
}
void solve(){
	double lb = 0.0, ub = 1.0;
	for (int i = 0; i < 100; ++i){
	// while (ub - lb > eps){
		double mid = (lb + ub) / 2;
		if (judge(mid))
			lb = mid;
		else
			ub = mid;
	}
	//4舍5入 输出方法
	printf("%.0f\n", ub*100);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	while (scanf("%d %d", &n, &k)){
		if (n == 0 && k == 0)
			return 0; 
		forn(i, n)
			cin >> a[i];
		forn(i, n)
			cin >> b[i];
		solve();
	}
	return 0;
}