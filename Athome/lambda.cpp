#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Functor
{
public:
	Functor(int i, int step)
		:_i(i), _step(step){}
	int operator()()
	{
		return _i += _step; 
	}
private:
	int _i;
	int _step;
};
int main()
{
	vector<int> numbers(10);
	generate(numbers.begin(), numbers.end(),
	for (auto& a : numbers)
		[](){return rand() % 100; });
	{
		cout << a << " ";
	}
	cout << endl;
	int odd_count = 0;
	for_each(numbers.begin(), numbers.end(),
		[&](int value){if (value % 2 == 1) odd_count++; });
	cout << odd_count << endl;

	/*生成等差数列*/
	int step = 2;
	int i = -step;
	vector<int> seq(10);
	//generate(seq.begin(), seq.end(),
		//[&i, step](){return i += step; });
	generate(seq.begin(), seq.end(), Functor(i, step));
	for (auto& a : seq)
	{
		cout << a << " ";
	}
	cout << endl;


	return 0;
}