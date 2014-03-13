//concurrency/thread1.cpp
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>
using namespace std;

void doSomething(int num, char c)
{
	try{
		//random-number generator
		default_random_engine dre(c);
		uniform_int_distribution<int> id(10, 1000);
		for (int i = 0; i < num; ++i){
			this_thread::sleep_for(chrono::milliseconds(id(dre)));
			cout.put(c).flush();
		}
	}
	//make sure no exception leaves the thread and terminates
	catch (const exception&e){
		cout << "THREAD-EXCEPTION(thread"
			<< this_thread::get_id() << "): " << e.what() << endl;
	}
}
int main()
{
	try{
		thread t1(doSomething, 5, '.');//print 5 dots
		cout << "-started fg thread" << t1.get_id() << endl;

		//print other chars in other background threads
		for (int i = 0; i < 5; ++i){
			thread t(doSomething, 10, 'a' + i);
			cout << "-detach started bg thread" << t.get_id() << endl;
			t.detach();//detach thread into the background
		}

		cin.get();//wait for any input getchar()
		cout << "-join fg thread " << t1.get_id() << endl;
		t1.join();//wait for t1 to finish
	}
	catch (const exception&e){
		cerr << "EXCEPTION: " << e.what() << endl;
	}
}