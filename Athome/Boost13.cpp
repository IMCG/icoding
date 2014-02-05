/*Boost_13_14_15绑定器与函数对象
*Date:2014/01/19
*要把两个参数变成一个参数，bind1st &bind2nd变成函数对象的方式。
*/
#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
void Fun(int x, int y)
{
	cout << "Fun: " << x - y << endl;
}
/*ptr_fun是获取函数的指针，并转化为合适的指针为绑定器使用。
这里有一个参数重排的特性*/
void TestCase()
{
	//绑定第一个参数
	cout << "bind1st(ptr_fun(Fun),10)(1)" << endl;
	bind1st(ptr_fun(Fun), 10)(1);
	//绑定第二个参数
	cout << "bind2nd(ptr_fun(Fun),10)(1)" << endl;
	bind2nd(ptr_fun(Fun), 10)(1);
}
void TestCase2()
{
	vector<int> vStudent{ 50, 60, 30, 80, 90 };
	//计算数据平均分
	int nAvg = accumulate(vStudent.begin(), vStudent.end(), 0) / vStudent.size();
	cout << "nAvg=" << nAvg << endl;
	//计算每个学生与平均分的差距
	for_each(vStudent.begin(), vStudent.end(), bind2nd(ptr_fun(Fun), nAvg));
}
//bind1st调用类的成员函数
class CObj{
public:
	void Test()
	{
		vector<int> vRect{ 1, 2, 3, 10 };
		//mem_fun获取成员函数的指针。
		for_each(vRect.begin(), vRect.end(), bind1st(mem_fun(CObj::Fun), this));
	}
private:
	void Fun(int x)
	{
		cout << "CObj::Fun" << x << endl;
	}
};
//调用类成员函数，但参数两个以上。
class CObjBind{
public:
	void Test()
	{
		vector<int> vRect{ 1, 2, 3, 10 };
		cout << "First" << endl;
		//使用绑定器调用类成员函数
		//for_each(vRect.begin(), vRect.end(), bind(&CObjBind::Fun, this,_1, 1, 2));

		cout << "Second:" << endl;
		//_1绑定器的占位符
		for_each(vRect.begin(), vRect.end(),bind(&CObjBind::Fun,1,1,2));
	}
private:
	void Fun(int x, int y, int z)
	{
		cout << "CObjBind::Fun" << x << "," << y << "," << z << endl;
	}
};
int main()
{
	TestCase();
	TestCase2();
	system("pause");
	return 0;
}
