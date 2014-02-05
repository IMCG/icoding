#include<iostream>
#include<array>
using namespace std;
//执行效率比<vector>高，几乎和int array[5]效率一样
int main()
{
	array<int, 5> myarray = { 1, 2, 3, 4, 5 };
	//一维数组
	cout << "myarray=" << endl;

	for (size_t i = 0; i < myarray.size(); i++)
	{
		cout << myarray[i] << " ";
	}
	cout << endl;

	//二维数组
	array<array<int, 2>, 3> myarray2 = { 1, 2, 3, 4, 5, 6 };
	for (size_t i = 0; i < myarray2.size(); i++)
	{
		for (size_t j = 0; j < myarray2[i].size(); j++)
		{
			cout << myarray2[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}