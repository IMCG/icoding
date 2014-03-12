//通过sleep_for 来使线程睡眠一定的时间
#include<thread>
#include<iostream>
#include<mutex>
using namespace std;
//由于t1睡眠时间长，t2先执行了
//延时有这几种类型：nanoseconds、microseconds、milliseconds、seconds、minutes、hours。
int main()
{
	mutex m;
	thread t1([&m]()
	{
		this_thread::sleep_for(chrono::seconds(10));
		for (int  i = 0; i < 10; i++)
		{
			m.lock();
			cout << "In t1 ThreadID:" << this_thread::get_id() << ":" << i << endl;
			m.unlock();
		}
	});
	thread t2([&m]()
	{
		this_thread::sleep_for(chrono::seconds(1));
		for (int i = 0; i < 10; i++)
		{
			m.lock();
			cout << "In t2 ThreadID: " << this_thread::get_id() << ":" << i << endl;
			m.unlock();
		}
	});
	t1.join();
	t2.join();

	cout << "Main Thread" << endl;
	return 0;
}