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
    pFunc=add;//������ָ�븳ֵ��ʹ��ָ��add����
    pFunc(2,1);//��ֵ֮�����
    pFunc=subtract;
    pFunc(2,1);
}