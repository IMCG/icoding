//二分搜索
//Monthly Expense
//POJ 3273
//分成M份？，连续并使和最小
//积累和
bool C(int k){
	int sum = 0, cnt = 1;
	for (int i = 0; i<N; ++i){
		sum += cost[i];
		if (sum>k){
			sum = cost[i];
			++cnt;
		}
	}
	//分组大于M 说明k选小了要增大。
	//cnt<M时候说明k选大了要减小。还有cnt==M的情况，所以ub=mid.即可
	return cnt > M;
}
//max min  AC
//想清楚二分终止条件
void solve(int ub,int lb){
	//二分搜索,循环在ub==lb时结束,这是ub，lb都是答案..
	while (ub>lb){
		int mid = (ub + lb) / 2;
		//lb,ub的选取和上面C()函数返回值有关
		if (C(mid))lb = mid + 1;
		else ub = mid;
	}
	printf("%d\n", lb);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	cin >> N >> M;
	//low high 最好去给定区间
	int maxa = 0;
	int mina = 0;
	for (int i = 0; i < N; ++i){
		cin >> cost[i];
		maxa += cost[i];
		mina = max(mina, cost[i]);
	}
	solve(maxa, mina);
	
	return 0;
}

//Good来自endless 为何如此之简洁?
#include <stdio.h>
#pragma warning(disable:4996)
const int mx = 100005;
int n, mon, a[mx];
bool judge(int m){
	int sum = 0, cnt = 1;
	for (int i = 0; i < n; ++i){
		sum += a[i];
		if (sum>m){
			if (a[i] > m)return false;
			sum = a[i];
			++cnt;
		}
		//m取小了
		if (cnt > mon)return false;
	}
	return true;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	scanf("%d%d", &n, &mon);
	int sum = 0;
	for (int i = 0; i < n; ++i)scanf("%d", &a[i]), sum += a[i];
	int l = 0, r = sum, m;
	while (l + 1 < r)judge(m = (l + r) >> 1) ? r = m : l = m;
	printf("%d\n", l + 1);
}