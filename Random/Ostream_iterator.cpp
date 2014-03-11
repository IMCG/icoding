#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
	//create ostream iterator
	ostream_iterator<int> intwrite(cout, "\n");
	//write elements
	*intwrite = 42;
	intwrite++;
	*intwrite = 77;
	intwrite++;
	*intwrite = -5;

	//create coll 
	vector<int>coll{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//write all elements whth "<"
	copy(begin(coll), end(coll),
		ostream_iterator<int>(cout, "<"));
	return 0;
}