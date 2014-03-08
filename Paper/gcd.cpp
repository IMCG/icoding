//greates common divisor最大公约数
//least common multiple 最小公倍数 gcd*lcm=a*b;
#include <iostream>
using namespace std;
//辗转相除法 递归版本
unsigned int gcd(unsigned int a, unsigned int b){
	if (b == 0)return a;
	else return (b, a%b);
}
//迭代版本
unsigned int gcd1(unsigned int a, unsigned int b){
	while (b != 0){
		unsigned int tmp = b;
		b = a%b;
		a = tmp;
	}
	return a;
}
//基于减法
unsigned int gcd2(unsigned int a, unsigned int b){
	while (a != b){
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}
int main()
{
	unsigned int a = 2;
	unsigned int b = 4;
	cout << gcd2(2, 4) << endl;
	cout << gcd1(2, 4) << endl;
	return 0;
}