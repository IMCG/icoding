//ShellSort
#include <iostream>
using namespace std;
//diminishing increment sort(缩小增量排序)
//Increment==n/2

//http://blog.csdn.net/morewindows/article/details/6668714
//---The Point---
void ShellSort(int *a,int n)
{
	int i,j,Increment;
	int tmp;
	for(Increment=n/2;Increment>0;Increment/=2)
	{
		//插入排序也是从下标【1】开始的。
		for(i=Increment;i<n;i++)
		{
			tmp=a[i];
			// >=Increment 是因为 前Increment已经是各自有序。。
			for(j=i;j>=Increment;j-=Increment)
				if(tmp<a[j-Increment])
					a[j]=a[j-Increment];
				else
					break;
			// for (j = i; j >= Increment && tmp<a[j-Increment]; j -= Increment)
			// 	a[j] = a[j - Increment];
			a[j]=tmp;
		}
	}
}
//组能插入排序
void ShellSort1(int *a,int n)
{
	int j,gap;
	for(gap=n/2;gap>0;gap/=2)
	{
		for(j=gap;j<n;j++)
		{
			if(a[j]<a[j-gap])
			{
				int temp=a[j];
				int k=j-gap;
				while(k>=0 && a[k]>temp)
				{
					a[k+gap]=a[k];
					k-=gap;
				}
				a[k+gap]=temp;
			}
		}
	}
}

void ShellSort2(int *a,int n)
{
	int i,j,gap;
	for(gap=n/2;gap>0;gap/=2)
		for(i=gap;i<n;i++)
			for(j=i-gap;j>=0 && a[j]>a[j+gap];j-=gap)
				swap(a[j],a[j+gap]);
}

