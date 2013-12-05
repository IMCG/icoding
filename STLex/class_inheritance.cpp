#include<iostream>
#include<string>
using namespace std;

class Student{
public:
	//Student(){cout<<"constructor"<<endl;}
	//~Student(){cout<<"destructor"<<endl;}
	void getvalue()
	{
		cin>>num>>name>>sex;
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
class Student1:private Student{
public:
	void getvalue_1()
	{
		getvalue();
		cin>>age>>address;
	}
	void display_1()
	{   display();
		cout<<"age="<<age<<endl;
		cout<<"address="<<address<<endl;
	}
private:
	int age;
	string address;
};
int main()
{
	Student1  stud;
	//stud.getvalue();
	stud.getvalue_1();

	//stud.display();
	stud.display_1();
	return 0;
}