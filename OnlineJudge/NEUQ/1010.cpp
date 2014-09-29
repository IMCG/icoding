//科学计数法
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;
int res[35];
long long sum;
int main()
{
	res[1] = 1;
	for (int i = 2; i <= 30; ++i){
		res[i] = i*res[i - 1];
	}
	for (int i = 1; i <= 30; ++i){
		sum += res[i];
	}
	//cout.setf(ios::scientific, ios::floatfield);
	//sum 只能是计数法表示时候才能输出
	cout << setiosflags(ios::scientific) 
	<< setprecision(2) << sum << "\n";
	return 0;
}