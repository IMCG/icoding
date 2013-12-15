/*author:xuesen
Data:2013/12/13
Sort the stack
use queue & heap
*/
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
//use vector practise priority_queue
class priority_queue{
private:
	vector<int> data;
public:
	void push(int t)
	{
		data.push_back(t);
		push_heap(data.begin(),data.end());
	}
	void pop()
	{
		pop_heap(data.begin(), data.end());
		data.pop_back();
	}
	int top(){ return data.front(); }
	int size(){ return data.size(); }
	bool empty(){ return data.empty(); }
};
//template
template<typename T>
class Priority_queue{
public:
	void push(T val)
	{
		data.push_back(val);
		push_heap(data.begin(), data.end());
	}
	void pop()
	{
		pop_heap(data.begin(), data.end());
		data.pop_back();
	}
	int top(){ return data.back(); }
	bool empty(){ return data.empty(); }
	int size(){ return data.size(); }
private:
	vector<T> data;
};
void SortStack(stack<int> &stk)
{
	//can also pop data to vector then sort
	priority_queue<int> coll;
	while (!stk.empty())
	{
		coll.push(stk.top());
		stk.pop();
	}
	while (!coll.empty())
	{
		stk.push(coll.top());
		coll.pop();
	}
}
stack<int> SortStack1(stack<int> &stk)
{
	stack<int> cur;
	while (!stk.empty())
	{
		int data = stk.top();
		stk.pop();
		while(!cur.empty() && data > cur.top())
		{
			stk.push(cur.top());
			cur.pop();
		}
		cur.push(data);
	}
	return cur;
}
int main()
{
	stack<int> st;
	for (int i = 0; i < 10; i++)
	{
		st.push(rand() % 100);
	}
	//SortStack(st);
	st = SortStack1(st);
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
}
