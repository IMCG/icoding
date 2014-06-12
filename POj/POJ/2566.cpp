//尺取法 AC
//题意就是找一个连续的子区间，使它的和的绝对值最接近target
//前缀和的处理及其排序 添加(0,0)处理数据方便
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define forn(i,n) for(int i=0;i<n;++i)
#pragma warning(disable:4996)
const int mx = 100005;
int n, k;
int a[mx], q[mx];
//sum  index
pair<int, int> sum[mx + 1];
void init(){
	//为了对应下标
	sum[0] = make_pair(0, 0);
	forn(i, n)
		sum[i + 1] = make_pair(sum[i].first + a[i], i + 1);
	sort(sum, sum + n + 1);
}
int res, l, r;
void solve(int query){
	int s = 0, t = 1, gap = 0x3f3f3f3f;
	while (t <= n&&s <= n){
		int temp = sum[t].first - sum[s].first;
		if (abs(temp - query) <gap){
			gap = abs(temp - query);
			res = temp;
			l = sum[s].second;
			r = sum[t].second;
		}
		if (temp < query)t++;
		else if (temp>query)s++;
		else break;
		if (s == t)t++;
	}
	if (l>r)swap(l, r);
	printf("%d %d %d\n", res, l + 1, r);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	while (scanf("%d %d", &n, &k)){
		if (n == 0 && k == 0)
			return 0;
		forn(i, n)
			scanf("%d", &a[i]);
		forn(i, k)
			scanf("%d", &q[i]);
		init();
		forn(i, k)
			solve(q[i]);
	}
	return 0;
}