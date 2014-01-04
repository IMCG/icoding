/*Author:xuesen
*@Date:2014/1/2
*@Effective_33
*/
#include<iostream>
using namespace std;
/*1.内层作用域的名称会遮掩外围作用域的名称*/
int x;				//global var
void someFunc{
	double x;		//local var
	std::cin>>x;	//assign to local var
}

/*2.同理，derived class 作用域被嵌套在base class作用域中*/
class Base{
private:
	int x;
public:
	virtual void mf1()=0;
	virtual void mf2();							-----------------							
	void mf3();									|Base作用域		|
	...											|				|				
};												|	x	|-------|	
class Derived:public Base{						|	f1	|Derived|
public:												
	/*using Base::mf1*/							|				|
	/*using Base::mf3*/							|	f2	|	f1	|
	virtual void mf1();							|	f3	|	f4	|
	void mf4();									|		|		|
	...											-----------------
};
Derived d;
int x;

d.mf1();	//yes,::mf1
d.mf1(x);	//no,::mf1掩盖了Base::mf1
d.mf2();	//yes,调用Base::mf2
d.mf3(x);	//no,掩盖Base::mf3

/*可以使用using声明达成目标*/
d.mf1(x);	//yes.Base::mf1;

/*1.derived classes 内的名称会遮盖base classes 内的名称。
2.为了让掩盖的名称再见天日，可以用using声明式或转交函数。*/