#include<iostream>
#include<string>
using namespace std;

class Student{
public:
	Student(int n,char s):num(n),sex(s){
	cout<<"hello"<<endl;
	cout<<"bye"<<endl;
	}
	~Student(){}
	void show()
	{
		cout<<"num="<<num<<endl;
		cout<<"sex="<<sex<<endl;
	}
private:
	int num;
	char sex;
};
class Student1:public Student{
public:
	Student1(int n,char s,int a):Student(n,s)			//is point
	{
		age=a;
		cout<<"hello1"<<endl;
	}~Student1(){cout<<"bye1"<<endl;}
	void show1()
	{
		show();
		//cout<<"num"<<num<<endl;
		//cout<<"sex"<<sex<<endl;
		cout<<"age="<<age<<endl;
	}
private:
	int age;
};
int main()
{
	Student1 stud1(12,'m',13);
	stud1.show1();
	return 0;
}