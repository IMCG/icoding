//Drying POJ 3104
//二分 &找meet关系
#include <iostream>
#include <algorithm>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;
const int mx = 100005;
int n, k;
int a[mx];
//x mins 能不能完事儿
bool meet(int x){
	int ans = 0;
	for (int i = 0; i < n; ++i){
		//一定要减去k再判断
		if (a[i] > x)ans += ceil((double)(a[i]-x) / k);
		if (ans > x)return false;
	}
	return true;
}
void solve(int a,int b){
	int m;
	while (a + 1 < b){
		meet(m = (a + b)>>1) ? b = m : a = m;
	}
	printf("%d\n", a + 1);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	cin >> n;
	//取max
	int r = 0;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		r = max(r, a[i]);
	}
	cin >> k;
	if (k == 1)return printf("%d\n", r), 0;
	//因为自己还会减少所以--k
	--k;
	solve(0, r);
	return 0;
}