//pure virtual function
#include <iostream>
#include <string>
using namespace std;

//纯虚函数不能被实例化
class Pet{
public:
	virtual string sound() = 0;
};

class Dog :public Pet{
public:
	string sound(){ return "Woof"; }
};

class Cat :public Pet{
public:
	string sound(){ return "Meow"; }
};

int main(){
	Pet *p;
	p = new Dog();
	cout << p->sound() << "\n";
	delete p;
	
	p = new Cat();
	cout << p->sound() << "\n";

	return 0;
}