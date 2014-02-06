//Fibonacci
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int Fib1(int n)
{
	if (n == 1 || n == 0)
		return 1;
	else if (n > 1)
		return Fib1(n - 1) + Fib1(n - 2);
	else
		return 0;
}

int Fib2(int n)
{
	unordered_map<int, int> cache;
	cache.insert(make_pair(0, 1));
	cache.insert(make_pair(1, 1));
	if (cache.find(n) != cache.end())
		return cache.at(n);
	else
	{
		int tmp = Fib2(n - 1) + Fib2(n - 2);
		cache.insert(make_pair(n, tmp));
		return tmp;
	}
}

int Fib3(int n)
{
	int result = 0;
	int nFirst = 1, nLast = 1;
	if (n<2)
	{
		return 1;
	}
	for (int i = 1; i < n;i++)
	{
		result = nFirst + nLast;
		nFirst = nLast;
		nLast = result;
	}
	return result;
}
int main()
{
	cout << "Please input a integer: ";
	int n;
	cin >> n;
	cout << endl;
	cout << Fib1(n)<<" ";
	cout << Fib2(n)<< " ";
	cout << Fib3(n)<< " ";
}