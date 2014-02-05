/*上下排：根据上排的数字，对应下排出现次数
012345678
6210001000
:不停的循环尝试，直到下排没有数据可修改*/
#include<iostream>
#include<iomanip>
#include<array>
using namespace std;
int main()
{
	array<int, 10>a = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	array<int, 10>b = a;//下排初始化为上排
	bool success = false;

	while (!success)
	{
		bool tmp = true;
		for (int i = 0; i < 10; i++)
		{
			int count = 0; //count
			for (int j = 0; j < 10; j++)
			{
				if (b[j] == a[i])//看下排有多少个和上排i位置相等的。累加
					count++;
			}

			//
			if (count != b[i])
			{
				b[i] = count;
				tmp = false;	//表示下排还在调整
			}
		}
		success = tmp;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}

