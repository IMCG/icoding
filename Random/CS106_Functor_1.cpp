/*Author:xuesen
*@Data:12/24
*@CS106_Functors
*/
#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
bool IsEven(int val){
	return val % 2 == 0;
}
bool LengthIsLessThanFive(const string& str){
	return str.length() < 5;
}
//The more generic function,but useless
bool LengthIsLessThan(const string&str, size_t length){
	return str.length() < length;
}
size_t gMaxLength;//value to compare
bool LengthIsLessThan1(const string&str){
	return str.length() < gMaxLength;
}

/*Functiors to the Rescue
 A functor OR function object(is an C++ class that acts like a function)
 To crate a functor,wo create an object the overloads the operator().
 cout<<myFunctor(13);is equivalent to cout<<myFunctor.operator()(13);
*/
class MyFunctor{
public:
	void operator()(const string&str){
		cout << str << endl;
	}

	/*you can:	MyFunctor functor;
				functor("Functor power!");
	*/
};
class StringAppender{
public:
	/*Constructor tates and stores a string*/
	explicit StringAppender(const string&str) :toAppend(str){}
	/*operator() prints out a string,plus the stored suffix*/
	void operator()(const string&str){
		cout << str << ' ' << toAppend << endl;
	}
	/*	Stored the string"is awesome"and "C++"as a parameter to the function

		StringAppender myFunctor("is awesome");
		myFunctor("C++");
	*/
private:
	const string toAppend;
};
class ShorterThan{
public:
	/*Accept and store an int parameter*/
	explicit ShorterThan(size_t maxLength) :length(maxLength){}
	/*return whether the string length.....*/
	bool operator()(const string&str){
		return str.length() < length;
	}
	/*	Make a compare::
		ShorterThan st(length);
		count_if(coll.begin(), coll.end(), st);
		:equal to=>
		count_if(coll.begin(),coll.end(),ShorterThan(length);
	*/
private:
	const size_t length;
};
int main()
{
	//count the length < 5:Using STL count_if
	vector<string>coll(9, "string");
	int numLessFive = count_if(coll.begin(), coll.end(), LengthIsLessThanFive);
	
}
