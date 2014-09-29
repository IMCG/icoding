//第k个全排列
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, m, i;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		int a[1005];
		for (i = 1; i <= n; i++)
			a[i] = i;
		for (i = 1; i<m; i++)
			next_permutation(a + 1, a + n + 1);
		for (i = 1; i <= n; i++)
			printf(i == n ? "%d\n" : "%d ", a[i]);
	}
	return 0;
}
//康拓编码
#include <iostream>
#include <algorithm>
const int fac[]{1, 1, 2, 6, 24, 120, 720, 5040, 40320};
using namespace std;

int kt(int s[], int n){
	int sum = 0;
	for (int i = 0; i < n; ++i){
		int cnt = 0;
		for (int j = i + 1; i < n; ++j)
			if (s[i]>s[j])
				cnt++;
		sum += cnt*fac[n - i - 1];
	}
	return sum;//+1
}
bool vis[10];

int vkt(int ans[], int n, int k){
	memset(ans, 0, sizeof(ans));
	--k;
	for (int i = 0; i < n; ++i){
		int t = k / fac[n - i - 1];
		//这里从1开始
		for (int j = 1; j <= n; ++j){
			if (!vis[j]){
				if (t == 0)
					break;
				t--;
			}
		}
		ans[i] = j, vis[j] = true;
		k %= fac[n - i - 1];
	}
}
