//整数分解。。注意分解方式
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
typedef unsigned long long ull;
//整数分解的因子的幂
vector<int>prime_factor_time(int n){
	vector<int>res;
	for (int i = 2; i*i <= n; ++i){
		int time = 0;
		while (n%i==0){
			++time;
			n /= i;
		}
		res.push_back(time);
	}
	if (n != 1)res.push_back(1);
	return res;
}
//n!
ull factor(int n){
	ull res = 1;
	for (int i = 1; i <= n; ++i)
		res *= i;
	return res;
}
int main()
{
	int T;
	while (cin >> T){
		vector<int>f = prime_factor_time(T);
		int len = accumulate(f.begin(), f.end(), 0);
		ull num = factor(len);
		for (vector<int>::iterator it = f.begin(); it != f.end(); ++it)
			num /= factor(*it);
		cout << len << " " << num << "\n";
	}
	return 0;
}