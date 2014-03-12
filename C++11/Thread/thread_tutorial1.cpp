//http://solarianprogrammer.com/2011/12/16/cpp-11-thread-tutorial/
//笔记 1
#include <iostream>
#include <thread>
using namespace std;
void call_from_thread()
{
	cout << "Hello,world" << endl;
}
int main1()
{
	//thread t1(call_from_thread);
	thread t1([]{cout << "hello" << endl; });
	t1.join();

	return 0;
}
int main2()
{
	thread t[num_threads];
	//launch a gruop of threads
	for (int i = 0; i < num_threads; ++i){
		t[i] = thread(call_from_thread);
	}
	cout << "Launched from the main\n";
	//Join the threads with the main thread
	for (int i = 0; i < num_threads; ++i){
		t[i].join();
	}
	
	//Remember that the main function is also a thread,
	//usually named the main thread
	return 0;
}

void call_from_thread1(int tid)
{
	cout << "Launched by thread " << tid << endl;
}
int main3()
{
	thread t[num_threads];
	//launch a gruop of threads
	for (int i = 0; i < num_threads; ++i){
		t[i] = thread(call_from_thread1,i);
	}
	cout << "Launched from the main\n";
	//Join the threads with the main thread
	for (int i = 0; i < num_threads; ++i){
		t[i].join();
	}
	//异步运行的线程，用mutex 改善
	return 0;
}

