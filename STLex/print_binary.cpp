#include<iostream>
#include<stack>
using namespace std;

template<typename T>
void fun(T data)
{
	stack<T> coll;
	while(data)
	{
		coll.push(data%2);
		data/=2;
	}
	while(!coll.empty())
	{
		cout<<coll.top();
		coll.pop();
	}
}
void bin(unsigned n)
{
	unsigned i;
	for(i=1<<31;i>0;i/=2)
		(n&i)?printf("1"):printf("0");
}
void bin1(unsigned n)
{
	if(n>1)
		bin1(n/2);
	printf("%d",n%2);
}
int main()
{	bin1(7);
	printf("\n");
	bin1(14);
	//fun<int>(14);
}