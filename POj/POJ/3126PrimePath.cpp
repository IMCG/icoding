// http://blog.csdn.net/wmn_wmn/article/details/7837723
// 要求最短距离 ,就用bfs  并且用dp[]存储距离
#include <iostream>
#include <queue>
using namespace std;

#pragma warning(disable:4996)
#define MAX_N 9999+16
#define INF 0x3f3f3f3f

bool isPrime[MAX_N];

void prime(int n){
	fill(isPrime, isPrime + n, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < n; ++i)
		if (isPrime[i])
			for (int j = 2 * i; j < n; j += i)
				isPrime[j] = false;
}

//把a的倒数第i位转变为j
int change(int a, int i, int j){
	switch (i)
	{
	case 0:
		return a / 10 * 10 + j;
	case 1:
		return a / 100 * 100 + 10 * j + a % 10;
	case 2:
		return a / 1000 * 1000 + 100 * j + a % 100;
	case 3:
		return j * 1000 + a % 1000;
	}
	return 0;
}

int dp[MAX_N];
int bfs(int&from, int&to){
	fill(dp, dp + MAX_N, INF);
	queue<int>que;
	que.push(from);
	dp[from] = 0;
	while (!que.empty()){
		int t = que.front(); que.pop();
		for (int i = 0; i < 4; ++i){
			//每个数字可以9种变化
			for (int j = 0; j < 10; ++j){
				//前导0
				if (i == 3 && j == 0){
					continue;
				}
				int gen = change(t, i, j);
				if (!isPrime[gen] || dp[gen] <= dp[t])
					continue;
				//距离的处理
				dp[gen] = dp[t] + 1;
				que.push(gen);
			}
		}
	}
	return dp[to];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	prime(MAX_N);

	int T, A, B;
	cin >> T;
	while (T--){
		cin >> A >> B;
		cout << bfs(A, B) << "\n";
	}
	return 0;
}

//数字转换函数
void fun(int x){
	q = x / 1000;
	b = x % 1000 / 100;
	s = x % 100 / 10;
	g = x % 10;
}
int fun2(int x, int y, int z, int w){
	return x * 1000 + y * 100 + z * 10 + w;
}
//这样也可以转换,4个分开
fun(x);
for (int i = 1; i <= 9; ++i){
	int y = fun2(i, b, s, g);
	if (!flag[y] && !isqueue[y]){
		qq.push(y);
		isqueue[y] = 1;
		step[y] = step[x] + 1;
	}
}