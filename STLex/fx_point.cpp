#include<iostream>
using namespace std;

void add(int a,int b)
{cout<<a+b<<endl;}

void subtract(int a,int b)
{cout<<a-b<<endl;}

void printvalue(void (*func)(int,int),int a,int b)
{
	func(a,b);
}
int main()
{
    void (*pFunc) (int, int);
    pFunc=add;//给函数指针赋值，使其指向add函数
    pFunc(2,1);//赋值之后调用
    pFunc=subtract;
    pFunc(2,1);
}