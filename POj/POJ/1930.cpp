//没啥意思
#include <iostream>
#include <string>
#include <limits>
using namespace std;

typedef unsigned long long ULL;

ULL gcd(ULL a, ULL b)
{
	if (b == 0)return a;
	return gcd(b, a%b);
}

ULL ten_pow(unsigned int x)
{
	ULL result = 1;
	for (unsigned int i = 0; i < x; ++i)
	{
		result *= 10;
	}
	return result;
}
int main(int argc, char *argv[])
{
	string line;
	while (cin >> line)
	{
		if (line == "0")
		{
			break;
		}
		string digit = line.substr(2, line.length() - 5);
		unsigned int length = digit.length();
		const ULL n = atoi(digit.c_str());
		if (n == 0)
		{
			cout << "0/1" << endl;
			continue;
		}
		ULL min_x = numeric_limits<ULL>::max();
		ULL min_y = 0;
		for (int i = 1; i <= length; ++i)
		{
			string first = digit.substr(0, length - i);
			ULL x = ten_pow(length) - ten_pow(length - i);
			ULL y = n - atoi(first.c_str());
			ULL d = gcd(x, y);
			x /= d;
			y /= d;
			if (min_x > x)
			{
				min_x = x;
				min_y = y;
			}
		}
		cout << min_y << '/' << min_x << endl;
	}
	return 0;
}