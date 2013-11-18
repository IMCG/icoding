//auto lambda[Functionan Programming]
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	auto name="hello.\n";			//1  type-specifier ex.int ,float

	cout<<"hello. "<<name<<endl;
	auto girls=3;
	auto boys=4;

    //1.capture;2.parameters;3.->return-type;4.statement;

	auto totalchild= [](int x,int y)->int{return x+y;}; //lambda
	auto totalchild1=[girls,boys]()->int{return girls+boys;};
	//some lambda
	[] {};    //do nothing
	int a=3;
	int b=4;
	int c=3;
	[=] {return a+b;};    // left the parameters and ->return-type
	auto fun1=[&](int c) {b=a+c;};
	auto fun2=[=,&b](int c) ->int{return b+=a+c;};
	
	//cout<<fun1(c)<<endl;
	cout<<fun2(c)<<endl;

	cout<<totalchild(girls,boys)<<endl;
	cout<<totalchild1()<<endl;
}
