#include<iostream>
#include<string>
using namespace std;

class Student{
public:
	Student(int n,string nam,double s):num(n),name(nam),score(s){}
	~Student(){}
	virtual void display()				//virtual function
	{
		cout<<"num="<<num<<endl;
		cout<<"name="<<name<<endl;
		cout<<"score="<<score<<endl;
	}
protected:		//not private,protected
	int num;
	string name;
	double score;
};
class Gradute:public Student{
public:
	Gradute(int n,string nam,double s,int w):Student(n,nam,s),wage(w){}
	void display()
	{
		cout<<"num="<<num<<endl;
		cout<<"name="<<name<<endl;
		cout<<"score="<<score<<endl;
	//	display();
		cout<<"wage="<<wage<<endl;
	}
private:
	int wage;
};
int main()
{
	Student stud1(1001,"li",87.5);
	Gradute grad1(2001,"wang",98.5,1200);
	Student *pt=&stud1;
	pt->display();
	cout<<endl;
	pt=&grad1;
	pt->display();
	return 0;
}