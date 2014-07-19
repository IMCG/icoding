#include <iostream>
#include <memory>
using namespace std;
//如果内存资源需要共享
void foo(int* p){
	std::cout << *p << std::endl;
}
void bar(std::shared_ptr<int> p){
	++(*p);
}
int main(){
	std::shared_ptr<int> p1(new int(42));
	std::shared_ptr<int> p2 = p1;

	bar(p1);
	foo(p1.get());
	foo(p2.get());
}