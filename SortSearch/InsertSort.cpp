//InsertSort
#include <iostream>
#include <algorithm>
using namespace std;
//---The Point---
void InsertSort(int *a, int n)
{
	int tmp;
	int i, j;
	for ( i = 1; i < n; ++i)
	{
		/* code */
		tmp = a[i];
		//从后往前移动
		for (j = i; j > 0 && a[j - 1] > tmp; --j)
		{
			a[j] = a[j - 1];
			
		}
		a[j] = tmp;
	}
}
//先找位置再移动数据
void InsertSort1(int *a,int n)
{
	int i,j,k;
	for ( i = 1; i < n; ++i)
	{
		/* code */
		for (j = i-1; i >=0; --j)
			if (a[j]<a[i])
				break;

		if(j!=i-1)
		{
			int tmp=a[i];
			for(k=i-1;k>j;k--)
				a[k+1]=a[k];
			//a[i]放到正确位置
			a[j+1]=temp;
		}
	}
}
//用交换数据的方法
void InsertSort2(int *a,int n)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		for(j=i-1;i>=0 && a[j]>a[j+1];j--)
			swap(a[j],a[j+1]);
	}
}
int main()
{
	//int a[] = { 3, 7, 4, 9, 5 };
	int a[10];
	generate(a, a + 10, [](){return rand() % 100; });

	for (auto& i : a)
	{
		cout << i << ",";
	}
	cout << endl;
	InsertSort(a, 10);
	for (auto& i : a)
	{
		cout << i << ",";
	}
	cout << endl;
	return 0;
}