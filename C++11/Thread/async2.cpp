/*concurrency/sync2.cpp
let’s start a background task with an endless loop 
allocating memory to insert a new list element*/
#include <future>
#include <list>
#include <iostream>
#include <exception>
using namespace std;

void task1()
{
	//endless inserting and memory allocation
	//-will sooner or later raise an exception
	//::this is bad practive
	list<int> v;
	while (true){
		for (int i = 0; i < 1000000; ++i){
			v.push_back(i);
		}
		cout.put('.').flush();
	}
}

int main()
{
	cout << "starting 2 tasks" << endl;
	cout << "-task1: process endless loop" << endl;
	cout << "-task2: wait for <return> and then for task1" << endl;

	auto f1 = async(task1);//异步

	cin.get();//read a character like getchar()
	cout << "\nwait for the end of task1: " << endl;
	try{
		f1.get(); //wait for task1 to finish
	}
	catch (const exception&e){
		cerr << "EXCEPTION:" << e.what() << endl;
	}
}
