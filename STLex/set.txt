//cout/set2.cpp
#include<iostream>
#include<set>
using namespace std;

int main ()
{
	set<int> c;
	c.insert(1);
	c.insert(2);
	c.insert(4);
	c.insert(5);
	c.insert(6);

	cout<<"lower_bound(4):"<<*c.lower_bound(4)<<endl;
	cout<<"upper_bound(4):"<<*c.upper_bound(4)<<endl;
	cout<<"equal_range(4):"<<*c.equal_range(4).first<<" "
		<<*c.equal_range(4).second<<endl;
	cout<<endl;
}