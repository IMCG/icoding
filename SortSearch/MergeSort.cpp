//MergeSort
#include <iostream>
using namespace std;

void Merge(int *a, int *tmp, int Lpos, int Rpos, int RightEnd)
{
	int i, LeftEnd, Num, TmpPos;
	LeftEnd = Rpos - 1;
	TmpPos = Lpos;
	Num = RightEnd - Lpos + 1;

	/*main loop*/
	while (Lpos <= LeftEnd && Rpos <= RightEnd)
	{
		if (a[Lpos] < a[Rpos])
			tmp[TmpPos++] = a[Lpos++];
		else
			tmp[TmpPos++] = a[Rpos++];
	}

	while (Lpos <= LeftEnd)		//copy rest of first half
		tmp[TmpPos++] = a[Lpos++];
	while (Rpos <= RightEnd)	//copy rest of second half
		tmp[TmpPos++] = a[Rpos++];

	//copy *tmp back
	for (i = 0; i < Num; i++, RightEnd--)
		a[RightEnd] = tmp[RightEnd];
}
void MSort(int *a, int *tmp, int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		MSort(a, tmp, left, mid);			//左边有序
		MSort(a, tmp, mid + 1, right);		//右边有序
		Merge(a, tmp, left, mid + 1, right);
	}
}
int main()
{
	int a[8] = { 1, 5, 3, 7, 8, 2, 4, 6 };
	int tmp[8] = { 0 };
	for (auto& i : a)
	{
		cout << i << " ";
	}
	cout << endl;
	MSort(a, tmp, 0, 7);
	for (auto& i : a)
	{
		cout << i << " ";
	}
	cout << endl;

	return 0;
}

//MSort的驱动方程
void MergeSort(int *a,int n)
{
	int *tmp;
	tmp = malloc(n*sizeof(int));
	MSort(a,tmp,0,n-1);
	free(tmp);
}
void MergeSort(int *a,int n)
{
	int *tmp=new int[n];
	if(tmp!=nullptr)
	{
		MSort(a,tmp,0,n-1);
		delete[] tmp;
	}
	else
	{
		cout<<"No space for tmp array[]";
		return;
	}
}

//MergeArray
void MergeArray(int *a, int *b, int n, int m, int *c)
{
	int i, j, k;
	i = j = k = 0;
	while (i < n&&j < m)
	{
		if (a[i] < b[j])
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	}
	while (i < n)
		c[k++] = a[i++];
	while (j < m)
		c[k++] = b[j++];
}