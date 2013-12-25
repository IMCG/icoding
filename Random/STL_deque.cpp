/*Author:xuesen
*@Data:12/24
*@deque汇总
*/
#include<iostream>
#include<deque>
using namespace std;
int main()
{
	/*构造，析构*/
	deque<Elem>c;		
	deque<Elem>c1(c2);
	deque<Elem>c(n);
	deque<Elem>c(n, elem);
	deque<Elem>c(beg, end);
	/*赋值*/
	c.assign(begin, end);	//区间
	c.assign(n, elem);		//n个elem
	/*数据访问*/
	c.at(index);			//返回index所指向的值
	operate[];				//指定位置的引用
	c.front();				//返回数据
	c.back();
	c.begin();				//迭代器
	c.end();
	c.rbegin();				//反向迭代器
	c.rend();
	/*加入数据*/
	c.push_back();
	c.pop_back();
	c.erase(pos);			//删除数据，返回下一位置
	c.erase(begin, end);
	/*实用操作*/
	c.empty();
	c.max_size();			//返回容器中最大的数据的数量
	c.resize();
	c.size();
	swap(c1, c2);
	c1.swap(c2);
}
/*Author:xuesen
*@Data:12/24
*@stack
*/
#include<iostream>
#include<stack>
using namespace std;
int main()
{
	/*构造析构*/
	stack<Elem>c;
	stack<Elem>c1(c2);
	/*数据操作*/
	c.top();
	c.push(elem);
	c.pop();
	c.empty();
	c.size();
}