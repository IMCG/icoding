//在使用多线程的程序中操作共享数据的时候一定要小心，由于线程的乱序执行，
//可能会得到意想不到的结果
#include<thread>
#include<iostream>
#include<vector>
#include<mutex>
using namespace std;
/*程序的意思是每个线程使counter中的value自加1000次，5个线程运行结束的时候应该是5000）
，当没有使用锁的时候自加的操作可能被其他线程打断，因此结果可能会小于5000。
*/
struct Counter{
	mutex mutex;
	int value;
	Counter() :value(0){}
	void increment(){
		//mutex.lock();			//没锁
		++value;
		//mutex.unlock();
	}
	void decrement()
	{
		mutex.lock();
		--value;
		mutex.unlock();
	}
};
int main()
{
	Counter counter;
	vector<thread> threads;

	for (int i = 0; i < 5; i++)
	{
		threads.push_back(thread([&](){
			for (int i = 0; i < 10000; i++)
			{
				counter.increment();
			}
		}));
	}
	for (auto& thread : threads)
	{
		thread.join();
	}
	cout << counter.value << endl;

	return 0;
}
