//CuttingBitString
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//@1
int getnum(string s, int b, int e){
	int num = 0;
	for (int i = b; i <= e; ++i){
		num = num * 2 + (s[i] - '0');
	}
	return num;
}
//powers of 5
bool isPower(int num){
	while (num > 1){
		if (num % 5)
			return false;
		num /= 5;
	}
	return num == 1;
}
//@2
bool check(string s) {
	//valid segment must not has a leading zero
	if (s[0] == '0') return false;

	long long t = 0;
	int sz = s.size();

	//calculate the value of s in decimal
	for (int i = 0; i < sz;++i)
		t = t * 2 + (s[i] == '1');

	//try to divide s by 5 when it is possible
	while ((t % 5) == 0) t /= 5;

	return t == 1;
}

int getmin(string S){
	int m = S.length();
	const int INF = 100;
	vector<int>dp(m + 1, INF);
	dp[0] = -1;
	//注意dp[n]的具体意思
	for (int i = 1; i <= m; ++i){
		for (int j = i - 1; j > 0; j--){
			if (check(S.substr(0, i))){
				dp[i] = 1;
				break;
			}
			//if (S[j-1] == '0')
				//continue;
			if (check(S.substr(j, i-j)))
				dp[i] = min(dp[i], dp[j] + 1);
		}
	}
	return dp[m] == INF ? -1 : dp[m];
}
int main()
{
	string test;
	while (cin >> test){
		cout << getmin(test) << "\n";
	}
}