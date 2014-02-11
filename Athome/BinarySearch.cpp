//自己练习。注意边缘条件的测试
#include<iostream>
using namespace std;
int BinarySearch(int *a,int n,int target)
{
	int left = 0;
	int right = n - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] > target)
			right = mid - 1;
		else if (a[mid] < target)
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}
int main()
{
	int a[7] = { 1, 2, 3, 4, 5, 6, 7 };
	int b = BinarySearch(a, 7, 7);
	cout << b << endl;
}