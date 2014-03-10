//全排列
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 8

int N;

//记录每个点的颜色，0表示无染色
int history[MAXN];
int count;
/*dfs 第i个节点染色
*/
void dfs(int i){
	if (i == N){
		count++;
		for (int j = 0; j < N; j++){
			printf("%d", history[j]);
		}
		printf("\n");
		return;
	}
	for (int k = 1; k <= N; k++){
		int ok = 1;
		for (int j = 0; j < i; j++){
			if (history[j] == k){
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
	scanf_s("%d", &N);
	dfs(0);
	return 0;
}