#include <iostream>
#include <list>
using namespace std;
ostream&operator<<(ostream&os, list<int>list)
{
	for (auto& i : list)
	{
		os << " " << i;
	}
	return os;
}
int main()
{
	list<int>list1{ 1, 2, 3, 4, 5 };
	list<int>list2{ 10, 20, 30, 40, 50 };
	auto it = list1.begin();
	advance(it, 2);
	
	list1.splice(it, list2);
	cout << "list1:" << list1 << endl;
	cout << "list2:" << list2 << endl;

	list2.splice(list2.begin(), list1, it, list1.end());
	cout << "list1:" << list1 << endl;
	cout << "list2:" << list2 << endl;
	
	return 0;
}