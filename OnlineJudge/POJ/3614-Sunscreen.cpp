//没什么区别时候，用G++
//优先队列	WA
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

const int MAX_N = 2502;
int C, L;
typedef pair<int, int>Point;
Point lot[MAX_N], cov[MAX_N];

void solve()
{
	priority_queue<Point>cow;
	priority_queue<Point>cover;
	for (int i = 0; i < C; ++i)cow.push(lot[i]);
	for (int i = 0; i < L; ++i)cover.push(cov[i]);

	int ans = 0;
	/*while (!cover.empty()){
		auto cur = cover.top(); cover.pop();
		int a = cur.first, b = cur.second;
		while (!cow.empty()&&b--){
			auto match = cow.top(); cow.pop();
			if (match.first <= a&&match.second >= a)
				ans++;
		}
	}*/
	while (!cow.empty()){
		//C++11 auto cur;
		Point cur = cow.top(); cow.pop();
		while (!cover.empty()){
			Point match = cover.top(); cover.pop();
			int a = match.first, b = match.second;
			if (cur.first <= a&&a <= cur.second){
				ans++;
				b--;
				if (b != 0)
					cover.push(Point(a, b));
				break;
			}
			else
				break;
		}
	}
	printf("%d\n", ans);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	scanf("%d %d", &C, &L);
	for (int i = 0; i < C; ++i)
		scanf("%d %d", &lot[i].first, &lot[i].second);
	for (int i = 0; i < L; ++i)
		scanf("%d %d", &cov[i].first, &cov[i].second);

	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif // !ONLINE_JUDGE
	return 0;
}

//AC
//首先得确定一个贪心策略，在满足minSPF的条件下，尽量把SPF小的防晒霜
//用在maxSPF小的奶牛身上，因为maxSPF大的奶牛有更大的选择空间
priority_queue<int, vector<int>, greater<int> >q;
//////////////////////////////////////////////////
int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	scanf("%d %d", &C, &L);
	for (int i = 0; i < C; ++i)
		scanf("%d %d", &lot[i].first, &lot[i].second);
	for (int i = 0; i < L; ++i)
		scanf("%d %d", &cov[i].first, &cov[i].second);
	sort(lot, lot + C);
	sort(cov, cov + L);

	int result = 0, cur = 0;//奶牛index
	//选瓶子
	for (int i = 0; i < L; ++i){
		while (cur < C&&lot[cur].first <= cov[i].first){
			//把符合要求的都弄到queue里面
			q.push(lot[cur].second);
			++cur;
		}
		while (!q.empty() && cov[i].second){
			int maxSPF = q.top(); q.pop();
			// “奶牛上限”比这一瓶的上限大，说明这头奶牛可以被涂上防晒霜
			if (maxSPF >= cov[i].first){
				++result;
				--cov[i].second;
			}
		}
	}
	printf("%d\n", result);

#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif // !ONLINE_JUDGE
	return 0;
}