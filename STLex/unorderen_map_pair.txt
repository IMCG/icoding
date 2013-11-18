#include<unordered_map>
#include<iostream>

using namespace std;

typedef unordered_map<char,int> Mymap;
int main()
{
	Mymap c1;
	c1.insert(Mymap::value_type('a',1));
	c1.insert(Mymap::value_type('b',2));
	c1.insert(make_pair('c',3));

	//displany contents "[c,3] [b,2] [a,1]"
	for(const auto& c:c1)
	{
		cout<<"["<<c.first<<","<<c.second<<"]";
	}
	cout<<endl;

	Mymap c2(8,
		tr1::hash<char>(),
	equal_to<char>(),
	allocator<pair<const char,int> >());

	c2.insert(make_pair('d',4));
	c2.insert(make_pair('h',5));
	c2.insert(make_pair('f',6));

	for(const auto& c:c2)
		cout<<"["<<c.first<<","<<c.second<<"]";
	cout<<endl;

}
