/*Author:xuesen
 *@Data:12/23
 Efficient C++:Ch1 跟踪实例
 1.可以更改构造函数中的string为char或者是一个字符串指针
 从而提高性能
 2.在某些方面，这与内联相似。内联对大块头函数的影响是无足轻重
 的，只有在小型函数中，内联对性能的改善才有较大的影响。
 3.完美适合内联的函数就恰好是非常不适合跟踪的。
 4.避免对象的复制有利于提高性能。
*/
#include<iostream>
#include<string>
using namespace std;
class Trace{
public:
	Trace(const string &name);
	~Trace();
	void debug(const string &msg);

	static bool traceIsActive;
private:
	string theFunctionName;
};
//构造函数保存了函数的名字
inline
Trace::Trace(const string &name) :theFunctionName(name)
{
	if (traceIsActive){
		cout << " Enter function" << name << endl;
	}
}
//附加信息通过debug方法记录到日志中
inline
void Trace::debug(const string&msg)
{
	if (traceIsActive){
		cout << msg << endl;
	}
}
inline
Trace::~Trace()
{
	if (traceIsActive){
		cout << "Exit function" << theFunctionName << endl;
	}
}
int myFunction(int x)
{
	string name = "myFunction";
	Trace t(name);
	string moreInfo = "more interesting info";
	t.debug(moreInfo);
	return x + x + x;
}
int main()
{
	Trace::traceIsActive = false;//关闭跟踪
}
