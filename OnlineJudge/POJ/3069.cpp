//贪心算法
#include <algorithm>
#include <iostream>
#pragma warning(disable:4996)
using namespace std;
const int MAX_N = 1000;
int N, R;
int X[MAX_N];

//贪心选择性质，
void solve(){
	sort(X, X + N);

	int i = 0, ans = 0;
	while (i < N){
		int s = X[i++];
		//一直向右走直到据s距离大于R的点
		while (i < N&&X[i] <= s + R)i++;
		//p新进加入的标记位置
		int p = X[i - 1];
		//一直向右走直到据R距离大于R的点
		while (i < N&&X[i] <= p + R)i++;
		ans++;
	}
	printf("%d\n", ans);
}
int main()
{	
	//OJ已经定义好了宏
	#ifndef ONLINE_JUDGE
		freopen("E:\\in.txt", "r", stdin);
	#endif // !ONLINE_JUDGE
	while (scanf("%d%d", &R, &N)==2){
		if (R == -1 && N == -1)
			break;
		for (int i = 0; i < N; ++i){
			cin >> X[i];
		}
		solve();
	}
	fclose(stdin);
	return 0;
}