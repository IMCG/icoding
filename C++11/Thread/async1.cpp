//concurrency/async1.cpp
#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>
using namespace std;

int doSomething(char c)
{
	//random-number generator
	default_random_engine dre(c);
	uniform_int_distribution<int> id(10, 1000);

	//loop to print 
	for (int i = 0; i < 10; ++i){
		this_thread::sleep_for(chrono::milliseconds(id(dre)));
		cout.put(c).flush();
	}
	return c;
}
int func1(){
	return doSomething('.');
}
int func2(){
	return doSomething('+');
}
int main()
{
	//async 异步 (中间参数可以使lambda)
	cout << "starting func1() in background"
		<< " and func2() in foreground: " << endl;
	//start func1() a-synchronously(异步的) in background
	//now or later or never
	auto result1(async(func1));
	//future<int> result1(async(func1));
	//int result1 = func1();
	int result2 = func2();//call func2() 同步 (here and now)

	//print result(wait for fun1() finish and add 
	//its result to result2)   调用get()方法是必须的（async--get()）
	//result1.get() might be called before func2()
	int result = result1.get() + result2;
	cout << "\nresult of func1()+func2(): " << result
		<< endl;
	return 0;
}