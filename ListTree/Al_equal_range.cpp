// alg_equal_range.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <functional>      //For greater<int>( )
#include <iostream>

// Return whether modulus of elem1 is less than modulus of elem2
bool mod_lesser(int elem1, int elem2)
{
	if (elem1 < 0)
		elem1 = -elem1;
	if (elem2 < 0)
		elem2 = -elem2;
	return elem1 < elem2;
}

int main()
{
	using namespace std;
	vector <int> v1;
	vector <int>::iterator Iter1;
	pair < vector <int> ::iterator, vector <int> ::iterator > Result1, Result2, Result3;

	// Constructing vectors v1a & v1b with default less than ordering
	int i;
	for (i = -1; i <= 4; i++)
	{
		v1.push_back(i);
	}

	int ii;
	for (ii = -3; ii <= 0; ii++)
	{
		v1.push_back(ii);
	}

	sort(v1.begin(), v1.end());
	cout << "Original vector v1 with range sorted by the\n "
		<< "binary predicate less than is  v1 = ( ";
	for (Iter1 = v1.begin(); Iter1 != v1.end(); Iter1++)
		cout << *Iter1 << " ";
	cout << ")." << endl;

	// Constructing vectors v2 with range sorted by greater
	vector <int> v2(v1);
	vector <int>::iterator Iter2;
	sort(v2.begin(), v2.end(), greater<int>());

	cout << "Original vector v2 with range sorted by the\n "
		<< "binary predicate greater is    v2 = ( ";
	for (Iter2 = v2.begin(); Iter2 != v2.end(); Iter2++)
		cout << *Iter2 << " ";
	cout << ")." << endl;

	// Constructing vectors v3 with range sorted by mod_lesser
	vector <int> v3(v1);
	vector <int>::iterator Iter3;
	sort(v3.begin(), v3.end(), mod_lesser);

	cout << "Original vector v3 with range sorted by the\n "
		<< "binary predicate mod_lesser is v3 = ( ";
	for (Iter3 = v3.begin(); Iter3 != v3.end(); Iter3++)
		cout << *Iter3 << " ";
	cout << ")." << endl << endl;

	// equal_range of 3 in v1 with default binary predicate less <int> ( )
	Result1 = equal_range(v1.begin(), v1.end(), 3);
	cout << "The lower_bound in v1 for the element with a value of 3 is: "
		<< *Result1.first << "." << endl;
	cout << "The upper_bound in v1 for the element with a value of 3 is: "
		<< *Result1.second << "." << endl;
	cout << "The equivalence class for the element with a value of 3 in"
		<< "\n v1 includes the elements: ( ";
	for (Iter1 = Result1.first; Iter1 != Result1.second; Iter1++)
		cout << *Iter1 << " ";
	cout << ")." << endl << endl;

	// equal_range of 3 in v2 with the binary predicate greater <int> ( )
	Result2 = equal_range(v2.begin(), v2.end(), 3, greater <int>());
	cout << "The lower_bound in v2 for the element with a value of 3 is: "
		<< *Result2.first << "." << endl;
	cout << "The upper_bound in v2 for the element with a value of 3 is: "
		<< *Result2.second << "." << endl;
	cout << "The equivalence class for the element with a value of 3 in"
		<< "\n v2 includes the elements: ( ";
	for (Iter2 = Result2.first; Iter2 != Result2.second; Iter2++)
		cout << *Iter2 << " ";
	cout << ")." << endl << endl;

	// equal_range of 3 in v3 with the binary predicate mod_lesser
	Result3 = equal_range(v3.begin(), v3.end(), 3, mod_lesser);
	cout << "The lower_bound in v3 for the element with a value of 3 is: "
		<< *Result3.first << "." << endl;
	cout << "The upper_bound in v3 for the element with a value of 3 is: "
		<< *Result3.second << "." << endl;
	cout << "The equivalence class for the element with a value of 3 in"
		<< "\n v3 includes the elements: ( ";
	for (Iter3 = Result3.first; Iter3 != Result3.second; Iter3++)
		cout << *Iter3 << " ";
	cout << ")." << endl << endl;
}


