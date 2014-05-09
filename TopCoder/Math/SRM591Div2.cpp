//TheArithmeticProgression 等差数列
#include <algorithm>
#include <iostream>
using namespace std;
double minimumChange(int a, int b, int c){
	int m1 = b - a;
	int m2 = c - b;
	if (m1 == m2)
		return double(0);
	else
		return static_cast<double>(abs(m2 - m1) / 2.0);
}
int main()
{
	int a, b, c;
	while (cin >> a >> b >> c){
		cout << minimumChange(a, b, c) << "\n";
	}
	return 0;
}