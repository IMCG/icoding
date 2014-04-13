//Date:2014/4/12
#include <iostream>
#include <boost/thread.hpp>
using namespace std;
void mythread()
{
	cout << "Hello,thread!" << endl;
}
int main()
{
	boost::function<void()>f(mythread);
	boost::thread t(f);
	t.join();
	cout << "thread is over!" << endl;

	//don't nessesary
	return 0;
}