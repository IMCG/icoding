//优先队列
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
const int MAX_N = 20005;
//注意条件限制
typedef long long ll;
int N, L[MAX_N];	

void solve(){
	int a, b;
	ll ans = 0;
	priority_queue<int, vector<int>, greater<int> > que;
	for (int i = 0; i<N; ++i)
		que.push(L[i]);
	while (que.size() > 1){
		a = que.top(); que.pop();
		b = que.top(); que.pop();
		ans += a + b;
		que.push(a + b);
	}
	//output
	printf("%lld\n", ans);
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> L[i];
	solve();
	return 0;
}


//贪心算法 
//其实也可以用两个vector模拟  
void solve(){
	ll ans = 0;

	//直到计算到木板为1块时为止
	while (N > 1){
		//找到最短和次短
		int mii1 = 0, mii2 = 1;
		if (L[mii1] > L[mii2])
			swap(mii1, mii2);
		for (int i = 2; i < N; ++i){
			if (L[i] < L[mii1]){
				mii2 = mii1;
				mii1 = i;
			}
			else if (L[i] < L[mii2]){
				mii2 = i;
			}
		}

		//将两块板拼合
		int t = L[mii1] + L[mii2];
		ans += t;

		//防止交换到N-1位置上
		if (mii1 == N - 1)
			swap(mii1, mii2);
		L[mii1] = t;
		L[mii2] = L[N - 1];
		N--;
	}
	printf("%lld\n", ans);
}