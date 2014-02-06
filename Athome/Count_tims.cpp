//打印第一次只出现一次的字符
#include <iostream>
#include <string>
#include <array>
using namespace std;
//遍历2遍。hash
void FindChar(string&str)
{
	array<int, 256> tmp = { 0 };
	//hash
	for (size_t i = 0; i < str.size();i++)
	{
		tmp[str[i]]++;
	}
	cout << endl;
	for (auto& i : tmp)
	{
		cout << i << " ";
	}
	for ( int i	= 0; i < 256; i++)
	{
		if (tmp[i] == 1){
			cout << (char)i << endl;
			return;
		}
	}
	//return;
}
int main()
{
	string str = "bddai2dsfl211dbfsdljowq";
	FindChar(str);
	return 0;
}