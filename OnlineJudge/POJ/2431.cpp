//优先队列
//油站不一定是按递增序给出的，一定要Qsort
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

const int MAX_N = 1000000;
//input
int L, P, N;
//因为需要排序
//int A[MAX_N + 1], B[MAX_N + 1];
typedef pair<int, int>Point;
Point via[MAX_N];

void solve(){
	via[N].first = L;
	via[N].second = 0;
	N++;

	priority_queue<int>que;
	//init
	int ans = 0, pos = 0, tank = P;
	for (int i = 0; i < N; ++i){
		//接下来要前进的距离
		int d = via[i].first - pos;

		//行进不到下一站再加油
		while (tank - d < 0){
			if (que.empty()){
				puts("-1");
				return;
			}
			tank += que.top();
			que.pop();
			ans++;
		}
		tank -= d;
		pos = via[i].first;
		que.push(via[i].second);
	}
	printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	scanf("%d", &N);
	for (int i = N - 1; i >= 0; --i)
		scanf("%d  %d", &via[i].first, &via[i].second);
	scanf("%d  %d", &L, &P);
	//把距离转化为距离开始的距离
	for (int i = 0; i < N; ++i)
		via[i].first = L - via[i].first;
	sort(via, via + N);

	solve();
	//for (int i = 0; i < N; ++i)
		//printf("%d %d\n", via[i].first, via[i].second);

#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif // !ONLINE_JUDGE

	return 0;
}
