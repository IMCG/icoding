//最大M子段和
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int mmss(int S[], int n, int m)
{
	int max_sum, i, j;
	/*d[i]现阶段最大值，prev[i]上阶段最大值*/
	int *d = (int*)calloc(n + 1, sizeof(int));
	int *prev = (int*)calloc(n + 1, sizeof(int));
	S--;//j是从1开始，S是从0开始的

	for (i = 1; i <= m; ++i){
		max_sum = INT_MIN;
		for (j = i; j <= n; ++j){
			//状态转移
			if (d[j - 1] < prev[j - 1])
				d[j] = prev[j - 1] + S[j];
			else
				d[j] = d[j - 1] + S[j];
			prev[j - 1] = max_sum;
			if (max_sum < d[j])
				max_sum = d[j];
		}
		prev[j - 1] = max_sum;
	}
	free(d);
	free(prev);
	return max_sum;
}
int main()
{
	int n, m, i, *S;
	while (scanf_s("%d%d", &m, &n) == 2){
		S = (int*)malloc(sizeof(int)* n);
		for (i = 0; i < n; ++i)
			scanf_s("%d", &S[i]);
		printf("%d\n", mmss(S, n, m));
		free(S);
	}
	return 0;
}