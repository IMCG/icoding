/*BusinessTasks - SRM 236 Div 1:
N tasks are written down in the form of a circular list, so the first task 
is adjacent to the last one. A number n is also given. Starting with the first 
task, move clockwise (from element 1 in the list to element 2 in the list and 
so on), counting from 1 to n. When your count reaches n, remove that task from 
the list and start counting from the next available task. Repeat this procedure 
until one task remains. Return it. 

约瑟夫环
*/
//others code 
#include <string>
#include <vector>
#include <cmath>
#include <list>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define SZ(a)	(int)a.size()
#define For(i,a,b)	for(int i = (a);i < (b); ++i)
#define ForD(i,b,a)	 for(int i = (b-1);i >= (a); --i)

template<typename A,typename B>
A convert(B x)
{
	stringstream ss;
	ss << x;
	A res;
	ss >> res;
	return res;
}

typedef long long ll;

int next[50],prev[50];

class BusinessTasks{
public:
	string getTask(vector<string> list,int n)
	{
		int m = SZ(list);
		For(i,0,m)
			next[i]=(i+1)%m,prev[i]=(i-1+m)%m;
		bool f1[50];
		memset(f1,false,sizeof(f1));	
		int p=0;
		For(i,0,m-1)
		{
			For(i,0,n-1)
				p=next[p];
			f1[p]=true;
			next[prev[p]]=next[p];
			prev[next[p]]=prev[p];
			p=next[p];
		}
		For(i,0,m)
			if(!f1[i])
				return list[i];
		return "0_0";
	}
};
//直接用链表
string getTask(vector<string> list,int n)
{
	list<string>tasks(list.begin(), list.end());
	int pos=0;
	//int len=tasks.size();不可以这样
	while(tasks.size() >１)｛
		int remove=(pos + n - 1)%tasks.size();
		tasks.erase(tasks.begin() + remove);
		pos=(remove)%tasks.size();
	}
	return tasks[0];
}
//is ok..
string getTask(vector<string> list, int n)
{
	int pos = 0;
	while (list.size() > 1)
	{
		int rem = (pos + n - 1) % list.size();
		list.erase(list.begin() + rem);
		pos = rem%list.size();
	}
	return list[0];
}