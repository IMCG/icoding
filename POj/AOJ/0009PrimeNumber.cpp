//艾氏筛法
#include <iostream>
using namespace std;
#define MAX_N 999999+16

int prime[MAX_N];//保存素数
bool is_prime[MAX_N + 1];//第几个数字是不是素数
int sieve(int n){
	int p = 0;
	fill(is_prime, is_prime + n + 1, true);
	is_prime[0] = is_prime[1] = false;
	//其实可以为sqrt(n)
	for (int i = 2; i <= n; ++i){
		if (is_prime[i]){
			prime[p++] = i;
			//必须是2*i
			for (int j = 2 * i; j <= n; j += i)
				is_prime[j] = false;
		}
	}
	return p;
}
int main(){
	
	int n;
	while (cin >> n){
		cout << sieve(n) << endl;
	}
	return 0;
}