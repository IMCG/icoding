/*Implement a MyQueue class which 
implements a queue using two stacks.
Data:2013/12/15
*/
#include<stack>
#include<vector>
#include<iostream>
using namespace std;

template<typename T>
class myqueue{
public:
	myqueue(){}
	~myqueue(){}
	void push(T val){
		queue_en.push(val);
	}
	void pop(){
		move(queue_en, queue_de);
		queue_de.pop();
	}
	T front(){
		move(queue_en, queue_de);
		return queue_de.top();
	}
	T back(){
		move(queue_de, queue_en);
		return queue_en.top();
	}
	int size(){
		return queue_en.size() + queue_de.size();
	}
	bool empty(){
		return queue_en.empty() && queue_de.empty();
	}
	void move(stack<T> &src,stack<T> &dst){
		if (dst.empty()){
			while (!src.empty()){
				dst.push(src.top());
				src.pop();
			}
		}
	}
private:
	stack<T> queue_en, queue_de;
};
int main()
{
	myqueue<int> coll;
	for (int i = 0; i < 10; i++)
	{
		coll.push(i);
	}
	cout << coll.front() << " " << coll.back() << endl;
	coll.pop();
	coll.push(10);
	cout << coll.front() << " " << coll.back() << endl;
	cout << coll.size() << " " << coll.empty() << endl;
	return 0;
}
