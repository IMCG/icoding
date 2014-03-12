//创建了多个子线程，并使用了get_id()方法来获取当前线程的id。
#include<iostream>
#include<vector>
#include<thread>
using namespace std;
int main()
{
	vector<thread> threads;
	for (int  i = 0; i < 5; i++)
	{
		threads.push_back(thread([](){
			cout << "Hello from lambda thread" << this_thread::get_id() << endl;
		}));
	}
	for (auto& thread : threads)
	{
		thread.join();
	}
	cout << "Main Thread" << "\t" << this_thread::get_id() << endl;

	return 0;
}