#include<iostream>
using namespace std;

class Time{
private:
	int hour;
	int minute;
	int sec;
public:
	Time()
	{
		hour=0;
		minute=0;
		sec=0;
	}
	void set_time();
	void show_time();
};
void Time::set_time()
{
	cin>>hour>>minute>>sec;
}
void Time::show_time()
{
	cout<<hour<<":"<<minute<<":"<<sec;
}
int main()
{
	Time t1;
	t1.set_time();
	t1.show_time();
	cout<<endl;

	Time t2;
	t2.show_time();
	
	return 0;
}
#include<iostream>
using namespace std;

class Box{
public:
	Box(int,int,int);
	int volume();
private:
	int height;
	int width;
	int length;
};
Box::Box(int h,int w,int len):height(h),width(w),length(len)
{
	/*height=h;
	width=w;
	length=len;*/
}
int Box::volume()
{
	return height*width*length;
}
int main()
{
	Box box1(12,25,30);
	cout<<"volume of box1 is"<<box1.volume()<<endl;

	Box box2(15,30,21);
	cout<<"volume of box2 is"<<box2.volume()<<endl;

}