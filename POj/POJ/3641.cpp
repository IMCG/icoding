//快速幂，并且是素数
//用反复平方法做快速幂运算判断条件②，条件①嘛，朴素的素性测试就行了。
#include <iostream>
using namespace std;
typedef long long ll;

ll mod_pow(ll x, ll n, ll mod){
	ll res = 1;
	while (n > 0){
		if (n & 1)
			res = res*x%mod;
		x = x*x%mod;
		n >>= 1;
	}
	return res;
}

bool is_prime(const int& n){
	for (int i = 2; i * i <= n; ++i){
		if (n % i == 0)
			return false;
	}
	return n != 1;   // 1是例外
}
int main()
{
	int p, a;
	while (cin >> p >> a){
		if (!p&&!a)
			return 0;
		if (!is_prime(p) && mod_pow(a, p, p) == a)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}