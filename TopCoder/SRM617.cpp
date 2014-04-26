//SRM 617
#include <iostream>
#include <vector>
using namespace std;
bool isComposite(int x)
{
	// Return true if x is a composite number, this is trial division over
	// for p <= sqrt(x), (we know that if x is composite, at least one divisor
	// should be <= sqrt(x))
	//Other: 先判断偶数。 x/2 也行
	for (int p = 2; p <= x / p; p++) {
		if (x % p == 0) {
			return true;
		}
	}
	return false;
}

vector<int> solve(int n)
{
	// Try each value of a, from 4 to n - 1
	for (int a = 4; a < n; a++) {
		int b = n - a;
		// is composite
		if (isComposite(a) && isComposite(b)) {
			return{ a, b };
		}
	}
	return{};
}

