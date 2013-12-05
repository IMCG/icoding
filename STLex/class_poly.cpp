#include<iostream>
#include<ostream>
using namespace std;
class Point{
protected:
	double x,y;
public:
	Point();
	Point(double a,double b):x(a),y(b){}
	~Point(){}
	void setPoint(double a,double b)
	{
		x=a;
		y=b;
	}
	double getX(){return x;}
	double getY(){return y;}
    friend ostream&operator << (ostream &,const Point &)
	{
		cout<<"["<<Point::x<<","<<Point::y<<"]"<<endl;
		return output;
	} 
};
Point::Point()
{
	x=0;
	y=0;
}
int main()
{
	Point p(3.5,6.4);
	cout<<p.getX()<<" "<<p.getY()<<endl;
	p.setPoint(8.5,6.8);
	cout<<"p(new)"<<p<<endl;
}

