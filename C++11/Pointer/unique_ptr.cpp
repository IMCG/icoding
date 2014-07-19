#include <iostream>
#include <memory>
using namespace std;
void foo(int* p)
{
	std::cout << *p << std::endl;
}
//如果内存资源的所有权不需要共享，就应当使用这个（它没有拷贝构造函数），
//但是它可以转让给另一个unique_ptr（存在move构造函数）
int main(){
	//auto p3 = std::make_shared<int>(42);   等效并且推荐
	std::unique_ptr<int> p1(new int(42));
	std::unique_ptr<int> p2 = std::move(p1); // transfer ownership
	//return nullptr
	if (p1)
		foo(p1.get());
	(*p2)++;
	if (p2)
		foo(p2.get());
	return 0;
}
