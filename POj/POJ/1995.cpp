//快速幂
#include <iostream>
using namespace std;
#pragma warning(disable:4996)
typedef long long ll;
//重点
ll high_pow(ll a, ll n, ll mod){
	ll res = 1;
	while (n>0){
		if (n & 1)
			res = res*a%mod;
		a = a*a%mod;
		n >>= 1;
	}
	return res;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("E:\\in.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	int Z, M, H;
	cin >> Z;
	while (Z--){
		cin >> M;
		cin >> H;
		ll sum = 0;
		int a, b;
		while (H--){
			cin >> a >> b;
			sum += high_pow(a, b, M);
		}
		cout << sum%M << "\n";
	}
	return 0;

}