#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<functional>
#include<iterator>
#include<algorithm>
using namespace std;

void Sort(stack<int> &s)
{
	priority_queue<int,vector<int>,greater<int> > p;
	while(!s.empty())
	{
		p.push(s.top());
		s.pop();
	}
	while(!p.empty())
	{
		s.push(p.top());
		p.pop();
	}
}
//void Sort1(stack<int> &s)
//{
//	vector<int> v;
//	while(!s.empty())
//	{
//		v.push_back(s.top());
//		s.pop();
//	}
//	sort(v.begin(),v.end());
//	while(!v.empty())
//	{
//		s.push(v.pop_back());			//eror
//
//	}
//}
stack<int> priority_q(stack<int> s)                     //auto 
{
	vector<int> t;
	while(!s.empty())
	{
		t.push_back(s.top());
		s.pop();
	}
	sort(t.begin(),t.end());

	for(auto i:t)
		s.push(i);
	return s;
}
stack<int> Sort2(stack<int> &s)
{
	stack<int> t;
	while(!s.empty())
	{
		int data = s.top();
		s.pop();
		while(!t.empty() && t.top()> data)
		{
			s.push(t.top());
			t.pop();
		}
		t.push(data);
	}
	return t;
}

int main()
{
	stack<int> s;
	for(int i=0;i<10;i++)
		s.push(rand()%100);

	//Sort(s);
	//Sort1(s);

	//ostream_iterator<stack,char> out(cout," ");

	//cout<<"stack s";
	
	s=Sort2(s);
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}