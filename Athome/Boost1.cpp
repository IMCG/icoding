/*什么是Lambda表达式，其实就是一个匿名函数；
提供类型安全，提供更加局部化的作用域代码。
BOOST_1
Date:2014/01/19
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;

class CMul{
public:
	void operator()(const int &v)
	{
		cout << v * 3 << " ";
	}
};
int main()
{
	vector<int>test{ 1, 2, 3, 4 };
	for_each(test.begin(), test.end(), CMul());
	cout << endl;
	for_each(test.begin(), test.end(), [](int n){cout << n * 3 << " "; });
	return 0;
	//输入流
	typedef istream_iterator<int> in;
	for_each(in(cin),in(),CMUl());

}
