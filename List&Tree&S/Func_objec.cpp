//函数对象。
#include<iostream>
#include<vector>
#include<functional>
#include<numeric>
using namespace std;
/*
	template<class InputIterator, class Type>
	Type accumulate(
	InputIterator _First,
	InputIterator _Last,
	Type _Val
	);
	template<class InputIterator, class Type, class BinaryOperation>
	Type accumulate(
	InputIterator _First,
	InputIterator _Last,
	Type _Val,
	BinaryOperation _Binary_op
	);
*/
int mult(int x, int y){ return x*y; };
//将函数对象作为一个参数传递给accumulate（）。函数对象是一个重载了
//operator（）方法的类的实例
class Mult{
public:
	int operator()(int x, int y)const { return x*y; };
};
int main()
{
	int A[10] = {1,2,3,5,7,11,13,17,19,23};
	vector<int> coll(A, A + 10);
	int num1 = accumulate(coll.begin(), coll.end(), 1, mult);//mult作为函数指针
	int num2 = accumulate(A, A + 10, 1, Mult());//函数对象的构造函数
	int num3 = accumulate(coll.begin(), coll.end(), 1, 
		[](int x, int y)
		{
			return x*y;
		}
	);
	int num4 = accumulate(coll.begin(), coll.end(), 1,multiplies<int>());
	cout << num1 << " " << num2 << " " << num3 << " " <<num4<< endl;
}
