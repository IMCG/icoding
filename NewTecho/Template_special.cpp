//编译器总会找一个最匹配的模板
//一个方法 typeid
#include "algo.h"
#include <typeinfo>
using namespace std;
struct t1{};
struct t2{};
struct t3{};

template<class A,class B,class C>
void func(A a1, B a2, C a3){
	//for typename
	cout << "A: " << typeid(a1).name() << endl;
	cout << "B: " << typeid(a2).name() << endl;
	cout << "C: " << typeid(a3).name() << endl;
}

template<class A,int I>
struct container{
	void callMe(){
		cout << "primary A: " << typeid(A).name() 
			<< " I: " << I << endl;
	}
};
//部分特化
template<class a1>
struct container < a1, 25 > {
	void callMe(){
		cout << "partial specialization" << typeid(a1).name() 
			<< " and 25 " << endl;
	}
};
//全特化
template<>
struct container < t3, 99 > {
	void callMe(){
		cout << "complete specialization t3,99" << endl;
	}
};

int main(){
	container<t2, 10> test1;
	test1.callMe();
	container<t3, 99> test2;
	test2.callMe();
	container<t2, 25> test3;
	test3.callMe();
	container<t3, 25> test4;
	test4.callMe();

	return 0;
}