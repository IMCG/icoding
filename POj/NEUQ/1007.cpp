//2位精度的使用
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
int num;
int sum;
int ave;
int main()
{
	//ifstream input(R"(E:\in.txt)");
	for (int i = 0; i < 20; ++i){
		cin >> num;
		if (num < 0)
			sum++;
		else
			ave += num;
	}
	cout << sum << "\n";
	cout << setiosflags(ios::fixed) 
		<< setprecision(2) << double(ave) / (20 - sum);
	return 0;
}