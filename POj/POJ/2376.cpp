//贪心算法
//不必覆盖，只要能连接就行了
//WA
#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
const int MAX_N = 25002;
pair<int, int>via[MAX_N];
int N, T;

void solve(){
	sort(via, via + N);
	if (via[N - 1].second < T){
		printf("%d\n", -1);
		return;
	}
	int ans = 0, t = 1 ,i = 1;
	//for while 避免了自加
	while (i < N){
		while (via[i].first == 1){
			//分界边界.second+1
			t = via[i].second + 1;
			i++;
		}
		//拼接并选择结束时间最大的一个
		if (t >= via[i].first){
			int temp = t;
			//在循环的过程中t在变化
			while (i < N&&temp >= via[i].first){
				t = max(t, via[i].second + 1);
				i++;
			}
			//t = max(t, via[i - 1].second + 1);
			ans++;
		}
		else{
			printf("%d\n", -1);
			return;
		}
	}
	printf("%d\n", ans);
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
	#endif // !ONLINE_JUDGE
	scanf("%d  %d", &N, &T);
	int a, b;
	for (int i = 0; i < N; ++i){
		scanf("%d  %d", &a, &b);
		via[i] = make_pair(a, b);
	}
	solve();
	fclose(stdin);
	return 0;
}
/*
input
10 10
1 3
2 4
3 5
4 6
5 7
6 8
7 9
8 10
9 10
10 10

output
4

1 3
4 6
7 9
9 10
*/
