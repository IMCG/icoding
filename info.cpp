//信息到二进制
#include <iostream>
#include <bitset>
#pragma warning(disable:4996)
using namespace std;
int main()
{
	freopen("E:\\in.txt", "r", stdin);
	freopen("E:\\out.txt", "w", stdout);
	char ch;
	while (cin >> ch)
		cout << bitset<8>(ch);
	fclose(stdin);
	fclose(stdout);
	system("E:\\out.txt");
}