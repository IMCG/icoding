//快速幂  取模运算
#include <iostream>
using namespace std;
typedef long long ll;

//1
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
//2
ll mod_pow1(ll x, ll n, ll mod){
	if (n == 0)return 1;
	ll res = mod_pow1(x*x%mod, n / 2, mod);
	if (n & 1)res = res*x%mod;
	return res;
}
