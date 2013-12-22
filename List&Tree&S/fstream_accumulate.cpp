/*Chapter 7:STL Algorithms
*Data:12/22
*/
#include<iostream>
#include<fstream>
#include<tchar.h>
#include<algorithm>
#include<numeric>	//accumulate
#include<set>
using namespace std;
int main()
{
	ifstream input(_TEXT("E:\\1.txt"));
	multiset<int> values;

	//Read the data from the file
	int currValue;
	while (input >> currValue)
		values.insert(currValue);
	double total = 0.0;
	//for (auto itr = values.begin(); itr != values.end(); itr++)
		//total += *itr;

	cout << accumulate(values.begin(), values.end(), 0.0);
	//you can thus...
	cout << accumulate(values.lower_bound(7), values.upper_bound(9), 0.0);
}