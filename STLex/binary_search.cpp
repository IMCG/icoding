#include<iostream>
using namespace std;
int binary_search(int array[],int n,int value)
{
	int left=0;
	int right=n-1;
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(array[mid]>value)
		{
			right=mid-1;
		} 
		else if(array[mid]<value)
		{
			left=mid+1;
		} 
		else
		   return mid;
	}
	return -1;
}
int main()
{
	int array[]={
		1,4,5,7
	};
	cout<<binary_search(array,4,5)<<endl;
	
	return 0;
}
