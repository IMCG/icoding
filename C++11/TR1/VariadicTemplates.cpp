//Date:2014/04/12
//不确定参数个数
#include <iostream>
#include <bitset>
using namespace std;

//template<typename T>
//void print(const T&arg)
//{
//	cout << arg << endl;
//}

//必要的重载
void print(){}

template<typename T,typename...Types>
void print(const T&firstArg, const Types&...args)
{
	cout << firstArg << endl;
	print(args...);//call print() for remaining argumengs
}
int main()
{
	print(7.5, "hello", std::bitset<8>(64), 42);

}