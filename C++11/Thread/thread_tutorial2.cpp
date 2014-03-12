#include <iostream>
#include <thread>
#include <vector>
using namespace std;

void func(int tid){
	cout << "Launched by thread " << tid << endl;
}
//push threads int a vector
int main()
{
	vector<thread>th;
	int nr_threads = 10;
	//launch a group of threads
	for (int i = 0; i < nr_threads; ++i){
		th.push_back(thread(func, i));
	}
	for (auto& t : th){
		t.join();
	}
	return 0;
}

