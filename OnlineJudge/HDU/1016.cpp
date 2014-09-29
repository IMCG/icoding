//AC
#include <iostream>
#include <vector>
using namespace std;
int prime[100];
bool isPrime[100];
void sieve(int n){
	int p = 0;
	fill(isPrime, isPrime + 100, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < 100; ++i){
		if (isPrime[i]){
			prime[p++] = i;
			for (int j = 2 * i; j < 100; j += i)
				isPrime[j] = false;
		}
	}
}
//vector<int> res;
//用数组
int a[30];
bool vis[30];
void init(){
	memset(vis, false, sizeof(vis));
	vis[0] = true;
	a[0] = 1;
	//res.clear();
	//res.push_back(1);
}
int n;
void output(){
	//输出格式
	for (int i = 0; i < n; ++i){
		if (i>0)cout << " ";
		cout << a[i];
	}
	cout << "\n";
}
void dfs(int step){
	//满足条件。
	if (step == n&&isPrime[a[0] + a[n - 1]]){
		output();
		return;
	}
	for (int j = 2; j <= n; ++j){
		a[step] = j;
		if (!vis[j] && isPrime[a[step] + a[step - 1]]){
			vis[j] = 1;
			dfs(step + 1);
			vis[j] = 0;
		}
	}
}
int main()
{
	sieve(60);
	int index = 0;
	while (cin >> n){
		printf("Case %d:\n", ++index);
		init();
		dfs(1);
		cout << "\n";
	}
	return 0;
}