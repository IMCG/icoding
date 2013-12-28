/*Author:xuesen
*@Date:12/28
*@Effiective C++ 
*/
#include<iostream>
using namespace std;
/*初始化“给予对象初值”，对于用户自定义类型的对象而言，初始化由
*@构造函数执行，
*/
class A{
public:
	A();					//default构造函数
};
/*classes中的构造函数被声明为explicit,这可阻止它们被用来执行隐式类型转换。
*它们禁止编译器执行非预期的类型转换。
*/
class B{
public:
	explicit B(int x = 0, bool b = true);//default构造函数
};
class C{
public:
	explicit C(int x);		//不是default构造函数
};
void doSomething(B bObject);	//定义一个函数

/*copy构造函数::以同型对象初始化自我对象，copy assignment::从另一个同型对象中拷贝其值到自我对象*/
class Widget{
public:
	Widget();							//default构造函数
	Widget(const Widget& rhs);			//copy构造函数
	Widget&operator=(const Widget& rhs);//copy assignment操作符
};
bool hasAcceptableQuality(Widget w);
int main()
{
	Widget w1;				//调用default构造函数
	Widget w2(w1);			//调用copy构造函数
	w1 = w2;				//copy assignment操作符			没有新对象定义&copy assignment

	Widget w3 = w2;			//"="也可以调用copy构造函数		有新对象定义&copy 构造
	/*copy构造函数，它定义一个对象如何passed by value;所以aWidget 被复制到w体内。这个复制对象
	*由Widget的copy构造函数执行。Pass-by-reference-to-const往往是比较好的选择；
	*/
	Widget aWidget;
	if (hasAcceptableQuality(aWidget))
	{
	}

	B bObj1;
	doSomething(bObj1);		
	B bObj2(28);

	doSomething(28);		//error!应该接受一个B;
	doSomething(B(28));
}