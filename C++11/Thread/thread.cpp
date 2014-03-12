//C++11 多线程
//C++11提供了新头文件<thread>、<mutex>、<atomic>、<future>等用于支持多线程。
#include<thread>
#include<iostream>
using namespace std;
void hello()
{
	cout << "Hello from thread" << endl;
}
int main()
{
	/*通过thread 类直接申明一个线程t1,参数是这个线程执行的回调函数的地址，
	通过join()方法阻塞主线程，直到t1线程执行结束为止*/
	thread t1(hello);
	t1.join();
	cout << "Main Thread" << endl;
	return 0;
}