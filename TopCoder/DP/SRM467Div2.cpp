//ShorterSuperSum
#include <iostream>
using namespace std;
int calculate(int k, int n){
	if (k == 0)
		return n;
	int res = 0;
	for (int i = 1; i <= n; i++)
		res += calculate(k - 1, i);
	return res;
}
//dp
int cal(int k, int n){
	int i, j, a[100][19], sum;
	memset(a, 0, sizeof(a));
	for (i = 1; i <= n; i++)
		a[0][i] = i;
	for (i = 1; i <= k; i++){
		sum = 0;
		for (j = 1; j <= n; j++){
			sum += a[i - 1][j];
			a[i][j] = sum;
		}
	}
	return a[k][n];
}
int main()
{
	int k, d;
	while (scanf("%d%d", &k, &d)){
		//cout << calculate(k, d) << "\n";
		cout << cal(k, d) << "\n";
	}
}