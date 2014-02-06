#include<iostream>
using namespace std;
#define LeftChild(i) (2*(i)+1)

void PercDown(int A[], int i, int N)
{
	int Child;
	int temp;
	for (temp = A[i]; LeftChild(i) < N; i = Child)
	{
		/* code */
		Child = LeftChild(i);
		if (Child != N - 1 && A[Child + 1]>A[Child])
		{
			/* code */
			Child++;
		}
		if (temp<A[Child])
			A[i] = A[Child];
		else
			break;
	}
	A[i] = temp;		//移动空穴
}
void HeapSort(int a[], int N)
{
	int i;
	for (i = N / 2; i >= 0; i--)  //buildHeap
	{
		/* code */
		PercDown(a, i, N);
	}
	for (i = N - 1; i >= 0; i--)  //DeleteMax
	{
		/* code */
		swap(a[0], a[i]);
		PercDown(a, 0, i);
	}
}
int main()
{
	int a[] = { 3, 7, 4, 9, 5, 6 };
	HeapSort(a, 6);
	for (auto c : a)
		cout << c << " ";
	return 0;
}