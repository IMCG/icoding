//把每一个都当成中位数，然后寻找两边(N-1)/2
//TLE 该成数组也不行 vector+priority_queue
// 好题 每次超时都想想能不能把一些  (重复)数据放到数组中
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#pragma warning(disable:4996)
using namespace std;
int N, C, F;
typedef pair<int, int>se;
vector<se>vec(C);

int solve(){
	sort(vec.begin(), vec.end(), greater<se>());
	int num = (N - 1) / 2, len = vec.size();
	priority_queue<int, vector<int>, greater<int> >lque, rque;
	for (int i = 0; i < len; ++i){
		if (i < num || len - i - 1 < num)
			continue;
		//left
		for (int j = 0; j < i; ++j)
			lque.push(vec[j].second);
		//right
		for (int j = i + 1; j < len; ++j)
			rque.push(vec[i].second);
		int ans = 0;
		while (num--){
			ans += lque.top() + rque.top();
			lque.pop();
			rque.pop();
		}
		//判断
		if (ans <= F)
			return vec[i].first;
	}
	return -1;	
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	cin >> N >> C >> F;
	int a, b;
	while (C--){
		cin >> a >> b;
		vec.push_back(make_pair(a, b));
	}
	cout << solve() << "\n";
	return 0;
}
//数组 每次循环清空queue  TLE
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#pragma warning(disable:4996)
using namespace std;
int N, C, F;
typedef pair<int, int>se;
se vec[100005];
void clean(priority_queue<int, vector<int>, greater<int> >&q){
	while (!q.empty())
		q.pop();
}
int solve(){
	sort(vec, vec + C, greater<se>());
	//N 等于1的情况
		if (N == 1){
		int ans = -1;
		for (int i = 0; i < C; i++)
			if (vec[i].second <= F)
				ans = vec[i].first;
		printf("%d\n", ans);
		return 0;
	}
	int num = (N - 1) / 2;
	priority_queue<int, vector<int>, greater<int> >que;
	for (int i = 0; i < C; ++i){
		if (i < num || C - i - 1 < num)
			continue;
		int ans = vec[i].second;
		//left
		clean(que);
		for (int j = 0; j < i; ++j)
			que.push(vec[j].second);
		for (int a = 0; a < num; ++a){
			ans += que.top();
			que.pop();
		}
		//right
		clean(que);
		for (int j = i + 1; j < C; ++j)
			que.push(vec[j].second);
		for (int a = 0; a < num;++a){
			ans += que.top();
			que.pop();
		}
		//判断
		if (ans <= F)
			return vec[i].first;
	}
	return -1;	
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	while (cin>>N>>C>>F){
		int a, b;
		for (int i = 0; i < C; i++){
			scanf("%d%d", &a, &b);
			vec[i] = make_pair(a, b);
		}
		cout << solve() << "\n";
	}
	return 0;
}
//hankcs 把数据都放到了lower[]和Upper[]保证了不TLE
#ifndef ONLINE_JUDGE
#pragma warning(disable : 4996)
#endif
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits>
#include <functional>
using namespace std;

#define MAX_COW 100000 + 16

int N, C, F;
pair<int, int> cow[MAX_COW];
// 牛i作为中位数时，lower[i]表示分数低于它的牛的学费总和
int lower[MAX_COW], upper[MAX_COW];

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif
	cin >> N >> C >> F;
	int half = N / 2;
	for (int i = 0; i < C; ++i)
	{
		cin >> cow[i].first >> cow[i].second;   // 分数 <-> 学费
	}
	sort(cow, cow + C);
	//看看大括号的作用
	{
		int total = 0;
		priority_queue<int> q;
		for (int i = 0; i < C; ++i)
		{
			lower[i] = q.size() == half ? total : 0x3f3f3f3f;
			q.push(cow[i].second);
			total += cow[i].second;
			if (q.size() > half)
			{
				// 然后踢掉一个学费最高的家伙
				total -= q.top(); q.pop();
			}
		}
	}

	{
		int total = 0;
		priority_queue<int> q;
		for (int i = C - 1; i >= 0; --i)
		{
			upper[i] = q.size() == half ? total : 0x3f3f3f3f;
			q.push(cow[i].second);
			total += cow[i].second;
			if (q.size() > half)
			{
				// 然后踢掉一个学费最高的家伙
				total -= q.top(); q.pop();
			}
		}
	}

	int result;
	for (int i = C - 1; i >= 0; --i)
	{
		if (lower[i] + cow[i].second + upper[i] <= F)
		{
			result = cow[i].first;
			break;
		}
	}

	cout << result << endl;
	return 0;
}