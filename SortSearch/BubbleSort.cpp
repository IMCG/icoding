//BubbleSort 
#include <iostream>
using namespace std;

//myself
void BubbleSort(int *a, int n)
{
	int i;
	while(n)
	{
		for(i=0;i<n-1;i++)
		{
			if(a[i]>a[i+1])
				swap(a[i],a[i+1]);
		}
		n--;
	}
}

void BubbleSort1(int *a,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=1;j<n-i;j++)
		{
			if(a[j-1]>a[j])
				swap(a[j-1],a[j]);
		}
	}
}