//一样尺取法
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#pragma warning(disable:4996)
//input
#define forn(i,n) for(int i=0;i<(int)n;++i)
const int MAX_P = 1000006;
int P;
int a[MAX_P];

/*[s,t] S num res
 sum更新的方式[point]
*/
void solve(){
	//计算S
	set<int>all;
	forn(i, P)
		all.insert(a[i]);
	int n = all.size();

	//尺取法
	int s = 0, t = 0, num = 0;
	map<int, int>count;//知识点出现次数
	int res = P;//初始化结果
	for (;;){
		//更新数据
		while (t < P&&num<n){
			if (count[a[t++]]++ == 0){
				num++;
			}
		}
		if (num < n)
			break;
		res = min(res, t - s);
		//某个知识点出现次数为0
		if (--count[a[s++]] == 0)
			num--;
	}
	printf("%d\n", res);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt","r",stdin);
#endif // !ONLINE_JUDGE
	cin >> P;
	forn(i, P)
		cin >> a[i];
	solve();
	return 0;
}