
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
#define MAX 201

#define max(a,b) ((a>b)?(a):(b))
int d[MAX][MAX];//序列长度
int b[MAX][MAX];//记录由哪个子问题得到。
void LCS(string x,string y)
{
	const int m = x.length();
	const int n = y.length();
	int i, j;
	//边界初始化
	for (i = 0; i <= m; i++)
		d[m][0] = 0;
	for (j = 0; j <= n; j++)
		d[0][j] = 0;
	for (i = 1; i <= m; i++){
		for (j = 1; j <= n; j++){
			if (x[i - 1] == y[j - 1]){
				d[i][j] = d[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
			else{
				if (d[i - 1][j] >= d[i][j - 1])
				{
					d[i][j] = d[i - 1][j];
					b[i][j] = 2;
				}
				else
				{
					d[i][j] = d[i][j - 1];
					b[i][j] = 3;
				}
			}
		}
	}
}
void Print(int b[MAX][MAX], string x, int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 1){
		Print(b, x, i - 1, j - 1);
		cout << x[i - 1];
	}
	else if (b[i][j] == 2){
		Print(b, x, i - 1, j);
	}
	else
		Print(b, x, i, j - 1);
}
int main()
{
	string str1 = "bdcaba";
	string str2 = "abcbdab";
	LCS(str1, str2);
	cout <<"The longth= "<< d[6][7] << endl;
	int i = str1.length();
	int j = str2.length();
	Print(b, str1, i, j);

	return 0;
}