#include<iostream>
using namespace std;

class Parent{
public:
	Parent(){}
	~Parent(){}
	Parent(int value){this->value=value;}
	Parent(Parent&){}
	void move()
	{cout<<"Parent moves"<<value<<"step"<<endl;}
	void move(int n)
	{cout<<"Parent move"<<n<<"step"<<endl;}
protected:
	int value;
};
class Child:public Parent
{
public:
	Child(){}
	Child(int value,int special):
		Parent(value),
		special(special)
	{}
	void move()
	{cout<<"Child move"<<value<<"step"<<endl;}
private:
	int special;

};
int main()
{
	Child *c=new Child(2,3);
	//c->move(2);//error
	Parent *p;
	p->move(3);//right
}