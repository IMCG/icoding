//B Serja and Mirroring
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
int n, m, i, k, p;
string a[1000];
int main()
{
	//为什么有无cin会影响输入。。
	cin >> n >> m; p = true;
	for (i = 0; i <= n; i++){
		//最后需要多输入一行。。。
		getline(cin, a[i]);
	}
	//偶数
	while (n % 2 == 0){
		//一个变量标识减小
		k = n;
		for (i = 1; i <= n / 2; i++){

			if (a[i] == a[k]) k--;
			else { p = false; break; }
		}
		if (p == false) break; n = n / 2;
	}
	cout << n;
}
//@2
#include <cstring>
#include <cstdio>
using namespace std;
char arr[105][105];
int main()
{
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j)
			scanf("%d", &arr[i][j]);
	//isEven
	while (!(n & 1)){
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
				if (arr[i][j] != arr[n - i + 1][j]){
					printf("%d", n);
					return 0;
				}
		//the point
		n /= 2;
	}
	printf("%d", n);
	return 0;
}
//

int n, m; bool A[103][103];
//递归
int f(int k){
    if(k%2!=0) return k;
    for(int i=1; i<=(k/2); i++)
      for(int j=1; j<=m; j++)
        if(A[i][j]!=A[k+1-i][j]) return k;
    return f(k/2);
}
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++)
      for(int j=1; j<=m; j++) cin>>A[i][j];
    cout<<f(n)<<endl;
}