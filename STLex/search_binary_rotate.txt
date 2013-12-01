#include<iostream>
using namespace std;
int search(int a[],int n,int target)
{
	int first=0;
	int last=n;
	while(first!=n)
	{
		const int mid=(first+last)/2;
		if(a[mid]==target)
			return mid;
		if(a[first]<=a[mid])
		{
			if(a[first]<=target && target<=a[mid])
				last=mid-1;
			else
				first=mid+1;
		}else{
			if(a[mid]<target && target<=a[last-1])
				first=mid+1;
			else
				last=mid-1;
		}
	}
	return -1;
}
int search_duplicate(int a[],int n,int target)
{
	int first=0;
	int last=n;
	while(first!=last)
	{
		int mid=(first+last)/2;
		if(a[mid]==target)
			return mid;
		if(a[first]<a[mid])
		{
			if(a[first]<=target&&target<=a[mid])
				last=mid-1;
			else
				first=mid+1;
		}else if(a[first]>a[mid]){
			if(a[mid]<=target&&target<=a[last])
				first=mid+1;
			else
				last=mid-1;
		}else
			first++;
	}
}
int main()
{
	int a[]={4,5,6,1,2,3};
	cout<<search(a,6,2)<<endl;
}