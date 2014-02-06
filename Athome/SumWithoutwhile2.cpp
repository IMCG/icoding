//通过全局变量（或者静态类变量）来记录累加的和，以及累加到的数字 
//通过构造函数来实现累加
#include<iostream>
using namespace std;
#define N 100

class Base
{
public:
	Base() //构造一次完成一次累加
	{
		n++;
		nSum += n;
	}
    static int gets_sum()
	{ return nSum; }
private:
	static int n;
	static int nSum;
};
int Base::n = 0;
int Base::nSum = 0;

int main()
{
	Base *p = new Base[N];

	cout << Base::gets_sum() << endl;

	delete[] p;
	p = nullptr;
	return 0;
}