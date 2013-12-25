/*Author:xuesen
*@Date:12/25
*@CS106_Functors
*/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<numeric>	//for accumulate
#include<functional>
using namespace std;
class Reciprocal{
public:
	double operator()(double val)const
	{
		return 1.0 / val;
	}
	/*TabulateFunctionValues(Reciprocal())
	error :is not a function -and so the above code will not compile
	Expecting a function pointer;
	But wo can rewrite the function;
	void TabulateFunctionValues(Reciprocal function)
	Now,if we call the function as
		TabulateFunctionValues(Peciprocal());
	The code is perfectly legal,because the argument has type Reciprocal;
	*/
};
class Arccos{
public:
	double operator()(double val){
		return acos(val);
	}
	/*Thera we can't TabulateFunctionValues(Arccos());
	Because the function is hardcoded to accept a Reciprocal,but we've tried 
	to provide it an object of type Arccos;
	*/
};
/*This suggests a rather elegant solution using templates.*/
template<typename UnaryFunction>
void TabulateFunctionValues(UnaryFunction function){
	cout << "This ok";
}

/*STl Algorithms Revisited*/
class LowerBoundHelper{
public:
	explicit LowerBoundHelper(int lower) :lowestValue(lower){}
	int operator()(int bestSoFar, int current){
		return current >= lowestValue && current < bestSoFar ?
		current : bestSoFar;
	}
private:
	const int lowestValue;
};
int UnsortedLowerBound(const vector<int>&input, int lowerBound)
{
	return accumulate(input.begin(), input.end(),
		numeric_limits<int>::max(),
		LowerBoundHelper(lowerBound));
}
/*If you need to transform a range of values into a single result (of any type you wish), 
use accumulate. Totransform a range of values into another range of values, use transform.*/
int main()
{
	int A[9] = {1,2,3,4,5,6,7,8,9};
	vector<int> coll(A,A+9);
	/*accumulate is a general-purpose function for transforming a collection
	of elements into a single value.*/
	//accumulate(coll.begin(), coll.end(), 0);
	/*template <typename InputIterator, typename Type, typename BinaryFn>
	inline Type accumulate(InputIterator start,
							InputIterator stop,
							Type accumulator,
							BinaryFn fn) {
			while(start != stop) {
				accumulator = fn(accumulator, *start);
				++start;
			}
			return initial;
	}*/
	random_shuffle(coll.begin(), coll.end());
	for (auto c : coll)
		cout << c << " ";
	cout << endl;
	int num = UnsortedLowerBound(coll, 4);
	cout << num;
}