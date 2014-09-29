//Palindrome
//POJ 1159  POJ 3280加强版
//AC
#include <iostream>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
#define MAX 5005
int N;
//memory limit 了
// string str;
char str[MAX];
//一直内存不够。把int-->short int 就行了
short int dp[MAX][MAX];
int main(){
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt","r",stdin);
#endif // !ONLINE_JUDGE
	cin >> N;
	cin >> str; //这样输入字符数组也行
	// for (int i = 0; i < N; ++i)
		// cin >> str[i];
	//dp[i][j]-->dp[i+1][j]弄清了，另外i,j的++--想清楚
	//palindrome一般都是从中间往两边推
	for (int i = N - 1; i >= 0; --i){
		for (int j = i + 1; j < N; ++j){
			dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
			if (str[i] == str[j])
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
		}
	}
	cout << dp[0][N - 1] << "\n";
	return 0;
}
//AC
#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
#define MAX 5005
int N;
char str[MAX];
short int dp[MAX][MAX];
int main(){
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt","r",stdin);
#endif // !ONLINE_JUDGE
	cin >> N;
	cin >> str;
	for (int i = N - 1; i >= 0; --i){
		for (int j = i + 1; j < N; ++j){
			if (str[i] == str[j])
				dp[i][j] = dp[i + 1][j - 1];
			else
				dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
		}
	}
	cout << dp[0][N - 1] << "\n";
	return 0;
}