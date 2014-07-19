#include <iostream>
#include <string>
using namespace std;

class Base{
private:
	string value = "base";
public:
	string function(){ return value; }
	//virtual 很重要.否则输出就变了
	//the “virtual” directive lets the compiler know that the 
	//Base function is going to be overridden by a new function 
	//in the Derived class.
	//virtual string function(){ return value; }
};
class Derived : public Base{
private:
	string othervalue = "derived";
public:
	string function(){ return othervalue; }
};

int main(){
	Base *b = new Base();
	cout << b->function() << "\n";
	b = new Derived();
	cout << b->function() << "\n";

	return 0;
}