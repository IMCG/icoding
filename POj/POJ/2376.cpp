//贪心算法
//不必覆盖，只要能连接就行了
//WA
#include <iostream>
#include <algorithm>
#include <stdio.h>
#pragma warning(disable:4996)
using namespace std;
const int MAX_N = 25002;
pair<int, int>via[MAX_N];
typedef pair<int, int>Point;
int N, T;
bool is_greater(Point&a, Point&b){
	return a.first<b.first ||
		(a.first == b.first&&a.second>b.second);
}
void solve(){
	int ans = 0, t = 1, i = 0;
	while (i < N){
		if (via[i].first <= t){
			int temp = t;
			while (i < N&&temp >= via[i].first){
				t = max(t, via[i].second + 1);
				i++;
			}
			ans++;
		}
		else{
			printf("%d\n", -1);
			return;
		}
	}
	if (t > T)
		printf("%d\n", ans);
	else
		printf("%d\n", -1);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	cin >> N >> T;
	int a, b;
	for (int i = 0; i < N; ++i){
		cin >> a >> b;
		via[i] = make_pair(a, b);
	}
	sort(via, via + N, is_greater);
	solve();
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
//好牛逼 思想跟我一样呀。
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#define REP(i,a,b) for(int i=a; i<b; ++i)
#define rep(i, n) REP(i, 0, n)

using namespace std;

typedef pair<int,int> se;


int main(){
  int N,T;
  vector<se> t;

  cin>>N>>T;
  rep(i,N){ int s,e; cin>>s>>e; t.push_back(se(s,e)); }	
  sort(t.begin(),t.end());

  int ti=0,ci=0,ans=0;
  while( ci<N && ti<T ){
    int mx=0;
    for(;ci<N && t[ci].first<=ti+1; ci++) mx=max(mx,t[ci].second);
    if(mx==0) break;
    ti=mx; ans++;
  }

  cout<<(ti==T?ans:-1)<<endl;
  
  return 0;
}
