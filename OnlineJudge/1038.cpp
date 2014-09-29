//求圆面积。。。
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
#define PI (3.14)
int main()
{
	double r = 0.0;
	int h = 0;
	cin >> r;
	cin >> h;
	cout.setf(ios::fixed);
	cout << "C1="<<setprecision(2) << 2 * PI*r << endl;
	cout << "Sa="<<setprecision(2) << PI*r*r << endl;
	cout << "Sb="<<setprecision(2) << 4 * PI*r*r << endl;
    cout << "Va="<<setprecision(2) << 4*PI*r*r*r/3 << endl;
    cout << "Vb="<<setprecision(2) << PI*r*r*h<< endl;	
}
