//destructor
#include<iostream>
#include<string>
using namespace std;

//first constructor last destructor as a stack

class Student{
public:
	Student(int n,string s,char c):num(n),name(s),sex(c)
	{
		cout<<"Constructor called"<<endl;
	}
	~Student()
	{
		cout<<"Destructor called"<<num<<endl;
	}
	void display()
	{
		cout<<"num="<<num<<endl;
		cout<<"name="<<name<<endl;
		cout<<"sex="<<sex<<endl;
	}
private:
	int num;
	string name;
	char sex;
};

int main()
{
	Student stud1(10010,"wang_li",'f');
	stud1.display();
	Student stud2(10011,"zhang_fang",'m');
	stud2.display();
	return 0;
}