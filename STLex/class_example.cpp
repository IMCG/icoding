#include<iostream>
using namespace std;
class Time{
private:
	int hour;
	int minute;
	int sec;
public:
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
	Time time;
	time.set_time();
	time.show_time();
	return 0;
}
#include<iostream>
using namespace std;

class Array_max{
private:
	int array[10];
	int max;
public:
	void set_value();
	void find_max();
	void show_max();
};
void Array_max::set_value()
{
	for(int i=0;i<10;i++)
		cin>>array[i];
}
void Array_max::find_max()
{
	max=array[0];
	for(int i=0;i<10;i++)
	{
		if(array[i]>max) max=array[i];
	}
}
void Array_max::show_max()
{
	cout<<"max="<<max<<endl;
}

int main()
{
	Array_max arrmax;
	arrmax.set_value();
	arrmax.find_max();
	arrmax.show_max();
	return 0;
}
