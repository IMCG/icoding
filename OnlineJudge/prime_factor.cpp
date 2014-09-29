#include <iostream>
#include <vector>
#include <map>
using namespace std;
//素数测试
bool is_prime(int n){
	for (int i = 2; i*i <= n; ++i)
		if (n%i == 0)
			return false;
	return n != 1;//1例外
}
//约数枚举
vector<int> divisor(int n){
	vector<int>res;
	for (int i = 1; i*i <= n; ++i){
		if (n%i == 0){
			res.push_back(i);
			if (i !=  n / i)res.push_back(n / i);
		}
	}
	return res;
}
//素因子分解
//每个合数都可以写成几个质数相乘的形式，这几个质数就都叫做这个合数的质因数
map<int, int>prime_factor(int n){
	map<int, int>res;
	for (int i = 2; i*i <= n; ++i){
		while (n%i == 0){
			++res[i];
			n /= i;
		}
	}
	if (n != 1)res[n] = 1;
	return res;
}
//艾氏筛法
//......
int main()
{
	auto m = prime_factor(24);
	//cout << m.size() << "\n";
	for (auto& i : m){
		cout << i.first << " " << i.second << "\n";
	}
	return 0;
}