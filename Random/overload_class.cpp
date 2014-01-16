#include<iostream>
using namespace std;

class Base{
private:
	int a_;
	int b_;
public:
	Base(int a, int b) :a_(a), b_(b){};
	friend ostream&operator << (ostream&out, const Base&b);
};
//this the key.
ostream&operator<<(ostream&out, const Base&b)
{
	out << b.b_ << " " << b.a_;
	return out;
}
int main()
{
	Base test(2,4);
	cout << test;
}