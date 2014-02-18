#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	int atoi(const char *str) {
		if (!str)return 0;
		long long result = 0;
		int sign = 1;
		while (*str == ' ')
			str++;
		if (*str == '-' || *str == '+')
			sign = (*str++ == '+') ? 1 : -1;
		while (isdigit(*str))
		{
			result = result * 10 + *str - '0';
			str++;
		}
		result = result*sign;
		if (result > INT_MAX)
			return INT_MAX;
		else if (result < INT_MIN)
			return INT_MIN;
		else
			return (int)result;
	}
};
int main()
{
	Solution s;
	const char *str = "2147483648";
	cout << s.atoi(str);
	return 0;
}