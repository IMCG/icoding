//部分和问题dfs
#include <cstdio>
using namespace std;
#define MAX_N 100
//input
int a[MAX_N];
int n, k;
//已经从前i项得到了和sum
bool dfs(int i, int sum)
{
	if (i == n)return sum == k;
	//不加a[i]
	if (dfs(i + 1, sum))return true;
	//加a[i]
	if (dfs(i + 1, sum + a[i]))return true;

	return false;
}
void solve()
{
	if (dfs(0, 0))printf("Yes\n");
	else printf("No\n");
}
int main()
{
	int T;//共几组测试数据
	scanf_s("%d", &T);
	while (T--)
	{
		scanf_s("%d", &n);//数组长度
		for (int i = 0; i < n; i++)
			scanf_s("%d", &a[i]);
		scanf_s("%d", &k);//部分和
		solve();
	}
	return 0;
}