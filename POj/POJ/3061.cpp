//尺取法:反复推进区间的开头和末尾,来求取满足条件的最小区间
#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

const int MAX_N = 100005;
int n, S;
int a[MAX_N];

/*
 做边界有边界[s,t] sum更新的方式[point]
 然后一个sum用于积累大小和已知S比较并且更新res(注意res的初值)
*/
int solve(){
	int s = 0, t = 0, sum = 0;
	int res = n + 1;
	for (;;){
		while (t < n&&sum < S)
			sum += a[t++];
		if (sum < S)
			break;
		res = min(res, t - s);
		sum -= a[s++];
	}
	return  res>n ? 0 : res;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	int T;
	cin >> T;
	while (T--){
		cin >> n >> S;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		cout << solve() << "\n";
	}
	return 0;
}

/*naive answer*/
/*存储sum[i] && 二分技巧*/
int n, S;
int a[MAX_N];
int sum[MAX_N + 1];

void solve(){
	//accu sum
	for (int i = 0; i < n; ++i){
		sum[i + 1] = sum[i] + a[i];
	}
	//不存在解
	if (sum[n]<S){
		printf("0\n");
		return;
	}
	int res = n;
	for (int s = 0; sum[s] + S <= sum[n]; s++){
		//二分查找
		int t = lower_bound(sum + s, sum + n, sum[s] + S) - sum;
		res = min(res, t - s);
	}
	printf("%d\n", res);
}