#include<iostream>
using namespace std;
class Time{
public:					//public interface
	
	void set()
	{
		cin>>hour>>minute>>sec;
	}
private:
	int hour;
	int minute;
	int sec;
};
int main()
{
	Time time;
	time.set();

	Time t,*p;
	p=&t;
	t.set();

	Time &b=time;     //通过指针，引用，成员运算符访问对象。
	b.set();
	
	cout<<sizeof(Time)<<endl;			//12取决于数据成员所占的空间，无关函数
}
//引用
//int a;
//int &b=a; 它的作用是为一个变量起一个别名
//类型名后出现的&是引用符，其他的是地址符
//
