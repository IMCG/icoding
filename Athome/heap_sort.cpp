//最大堆排序:任意一个下标i，它的值大于i*2和i*2+1的值(i从1开始) 
#include<iostream>
using namespace std;

//堆调整函数
void heap_adjust(int *a, int i, int size)
{
	int lchild = 2 * i;
	int rchild = 2 * i + 1;
	int max = i;

	if (i <= size / 2)//非叶子节点
	{
		if (lchild <= size && a[lchild] > a[max])
			max = lchild;
		if (rchild <= size && a[rchild] > a[max])
			max = rchild;
		if (max != i)
		{
			swap(a[i], a[max]);
			heap_adjust(a, max, size);//调整子树
		}
	}
}
//创建堆就是调整堆的过程
void create_heap(int*a, int size)
{
	int i = 0;
	for(i = size/2; i>=1; i--)
	{
		heap_adjust(a, i, size);
	}
}
//堆排序，数据放在数组中，下标1
void heap_sort(int*a, int size)
{
	int i = 0;
	int temp = 0;

	create_heap(a, size);

	for ( i = size; i >= 1; i--)
	{
		swap(a[i], a[1]);
		heap_adjust(a, 1, i - 1);
	}
}

int main()
{
	int a[100];
	int size = 0;
	cout << "count: ";

	while (cin >> size && size > 0)
	{
		int i = 0;
		for ( i = 0; i <=size; i++)
		{
			cin >> a[i];
		}
		heap_sort(a, size);
		for ( i = 0; i <=size; i++)
		{
			cout << a[i] << " ";
		}
	}
	return 0;
}
