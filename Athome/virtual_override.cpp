//http://blog.jobbole.com/44015/  C++11  good features
//加入override final 的原因

//为了增加可读性，我总是在派生类里也写上virtual
//关键字，并且也鼓励大家都这么做
#include <iostream>
using namespace std;

//一些微妙的错误
//理应重写f() 声明不同，所以是重载。  输出也不同
class B{
public:
	virtual void f(short) { std::cout << "B::f" << std::endl; }
};

class D : public B{
public:
	virtual void f(int) { std::cout << "D::f" << std::endl; }
};

//也不是重写, 基类多一个const
class B{
public:
	virtual void f(int) const { std::cout << "B::f " << std::endl; }
};

class D : public B{
public:
	virtual void f(int) { std::cout << "D::f" << std::endl; }
};

//加入两个标识符
//1.override  表示函数应当重写基类中的虚函数。
//2.final 表示派生类不应当重写这个虚函数。

//@1
class B{
public:
	virtual void f(short) { std::cout << "B::f" << std::endl; }
};

class D : public B{
public:
	//如果short 为int 会报错.因为(override) 
	virtual void f(short) override{ std::cout << "D::f" << std::endl; }
};

//@2
class B{
public:
	virtual void f(int) { std::cout << "B::f" << std::endl; }
};

class D : public B{
public:
	//可以同时使用 override final
	virtual void f(int) override final { std::cout << "D::f" << std::endl; }
};

class F : public D{
public:
	//error。 不能重写 因为 final
	virtual void f(int) override{ std::cout << "F::f" << std::endl; }
};

