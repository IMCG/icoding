//QuickSort
#include<iostream>
using namespace std;
void QSort(int *a, int left, int right)
{
	int i = left - 1;
	int j = right;
	int piovt = a[right];
	if(left<right){
		for (;;)
		{
			while (a[++i] < piovt){}
			while (a[--j] > piovt){}
			if (i < j)
				swap(a[i], a[j]);
			else
				break;
		}
		swap(a[i], a[right]);
		QSort(a, 0, i - 1);
		QSort(a, i + 1, right);
	}
}

//select a[left] be the pivot
int partition(int *a, int left, int right)
{
	int i = left;
	int j = right + 1;
	int p = a[left];
	for (;;)
	{
		while (a[++i] < p){}
		while (a[--j] > p){}
		if (i < j)
			swap(a[i], a[j]);
		else
			break;
	}
	swap(a[left], a[j]);
	return j;
}
void quicksort(int *a, int left, int right)
{
	int q;
	if (right > left)
	{
		q = partition(a, left, right);
		quicksort(a, 0, q-1);
		quicksort(a, q + 1, right);
	}
}

void QuickSort(int *a, int n)
{
	QSort(a, 0, n - 1);
}
int main()
{
	const int N = 7;
	int a[N] = { 3, 7, 4, 9, 5, 8, 6 };
	for (auto& i : a)
	{
		cout << i << " ";
	}
	cout << endl;
	QuickSort(a, N);
	for (auto& i : a)
	{
		cout << i << " ";
	}
	cout << endl;
}


//这里解释了为什么先前为什么不成功。
//两种partition方法。分别是用一个或两个指针。。。
//http://hi.baidu.com/anker/item/47dbaf25c1ff68cba4275a2d
void partition(int *a, int left, int right)
{
	int p = a[right];
	int i = left - 1;
	int j = right;
	if (left < right){
		for (;;)
		{
			while (a[++i] < p){}
			while (a[--j] > p){}
			if (i < j)
				swap(a[i], a[j]);
			else
				break;
		}
		swap(a[i], a[right]);
		//return i;
		partition(a, left, i - 1);
		partition(a, i + 1, right);
	}
}
int partition(int *a, int left, int right)
{
	int p = a[right];
	int i = left - 1;
	for (int j = left; j < right;j++)
	{
		if (a[j] < p)
		{
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[right]);
	return i + 1;
}
void QSort(int *a, int left, int right)
{
	/*int p;
	if (left < right)
	{
		p = partition(a, left, right);
		QSort(a, left, p - 1);
		QSort(a, p + 1, right);
	}*/
	return;
}