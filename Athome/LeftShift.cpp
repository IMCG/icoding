//旋转字符串
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//暴力移位法
void LeftShiftone(string&str)
{
	char t = str[0];
	for (size_t i = 1; i < str.length();i++)
	{
		str[i - 1] = str[i];
	}
	str[str.length() - 1] = t;
}
void LeftShift(string&str, int m)
{
	while (m--){
		LeftShiftone(str);
	}
}
//指针翻转法
void Rotate(string&str, int m)
{
	int n = str.length();
	if (n == 0 || m <= 0)
		return;
	int p1 = 0, p2 = m;
	int k = n - m - n%m;
	while (k--){
		swap(str[p1++], str[p2++]);
	}
	//重点处理尾部
	int r = n - p2;
	while (r--){
		int i = p2;
		while (i > p1){
			swap(str[i], str[i - 1]);
			i--;
		}
		p1++;
		p2++;
	}
}
//三步翻转法
void Rotate1(string&str, int m)
{
	reverse(str.begin(), str.begin() + m);
	reverse(str.begin() + m, str.end());
	reverse(str.begin(), str.end());
}
int main()
{
	string str = "abcdefg";
	cout << str << endl;
	rotate(str.begin(), str.begin() + 4, str.end());
	cout << str << endl;
}