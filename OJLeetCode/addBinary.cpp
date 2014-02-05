/*Add Binary:
a='11',b='1' return'100';*/
#include<iostream>
#include<string>
using namespace std;
string addBinary(string a, string b)
{
	string result;
	const size_t n = a.size() > b.size() ? a.size() : b.size();
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int carry = 0;
	for (size_t i = 0; i <n; i++)
	{
		//*str-'0';
		const int ai = i < a.size() ? a[i] - '0' : 0;
		const int bi = i < b.size() ? b[i] - '0' : 0;
		const int val = (ai + bi + carry) % 2;
		carry = (ai + bi + carry) / 2;
		result.insert(result.begin(), val+'0');
	}
	if (carry == 1)
		result.insert(result.begin(), '1');
	return result;
}
string addBinary1(string a, string b)
{
	int n = a.size(), m = b.size(), k = m > n ? m : n;
	int carry = 0;
	int i = n - 1, j = m - 1, r = k - 1;
	string result(k, ' ');
	while (i >= 0 || j >= 0){
		int sum = carry;
		if (i >= 0)sum += a[i--] - '0';
		if (j >= 0)sum += b[j--] - '0';
		carry = sum / 2;
		result[r--] = sum % 2 +'0';
	}
	if (carry == 1)
		result.insert(result.begin(), '1');
	return result;
}
int main()
{
	string a = "11";
	string b = "1";
	cout << addBinary(a, b) << "\n";
	cout << addBinary1(a, b);
}