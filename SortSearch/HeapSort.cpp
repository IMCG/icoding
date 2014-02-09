//HeapSort
//http://blog.csdn.net/morewindows/article/details/6709644
#include <iostream>
using namespace std;
#define LeftChild(i) (2*(i)+1)

void Heap_adjust(int *a, int i, int n)
{
	int Child;
	int temp;
	for (temp = a[i]; LeftChild(i) < n;i=Child)
	{
		//赋值应该在这里。 Child!=n-1
		Child = LeftChild(i);
		if (Child!=n-1 &&a[Child + 1]>a[Child])
			Child++;
		if (temp < a[Child])
			a[i] = a[Child];
		else
			break;
	}
	a[i] = temp;
}
void HeapSort(int *a, int n)
{
	int i;
	for (i = n / 2; i >= 0;i--)
	{
		Heap_adjust(a, i, n);
	}
	for (i = n - 1; i >= 0;i--)
	{
		swap(a[0], a[i]);
		Heap_adjust(a, 0, i);
	}
}
int main()
{
	int a[] = { 31, 41, 59, 26, 53, 58, 97 };
	for (auto& i : a)
	{
		cout << i << " ";
	}
	cout << endl;
	HeapSort(a, 7);
	cout << "Sorted.\n";
	for (auto& i : a)
	{
		cout << i << " ";
	}
	cout << endl;
}