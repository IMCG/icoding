//4色问题
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 8

int N;
int g[MAXN][MAXN];

//记录每个点的颜色，0表示无染色
int history[MAXN];
int count;

/*dfs 第i个节点染色
*/
void dfs(int i){
	if (i == N){
		count++;
		return;
	}
	for (int k = 1; k <= 4; k++){
		int ok = 1;
		for (int j = 0; j < i; j++){
			if (g[i][j] && history[j] == k){
				ok = 0;
			}
		}
		if (ok){
			history[i] = k;
			dfs(i + 1);
		}
	}
}
int main()
{
	int i, j;
	scanf_s("%d", &N);
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			scanf_s("%d", &g[i][j]);
		}
	}
	dfs(0);
	printf("%d\n", count);
	return 0;
}