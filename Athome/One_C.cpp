#include<iostream>  
using namespace std;
class Base{
public:
	virtual void show(int i = 10){
		cout << "Base show i=" << i << endl;
	}
	virtual ~Base(){}
};
class Derived :public Base{
public:
	virtual void show(int i = 20){
		cout << "Derived show i=" << i << endl;
	}
	virtual ~Derived(){}
};

int main(){
	Base* bp = new Derived();
	bp->show();
}
//Derived show i=10???