//search in rotated sorted array.
//what if duplicates are allowed;
#include<iostream>
using namespace std;

int search(int a[],int n,int x)
{
	int low=0,high=n;
	while(low!=high)
	{
		int mid=(low+high)/2;
		if(a[mid]==x) return mid;
		if(a[low]<a[mid]){   //omit =
		     if(a[low]<=x && x<a[mid])
				 high=mid;
			 else
				 low=mid+1;
		}
		else if(a[low]>a[mid]){
	         if(x>=a[mid] && x<a[low])
				 low=mid+1;
			 else
				 high=mid;
		}
		else
			low++;
	}
	return -1;
}
int main()
{
    int a[12] = {
        15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14
    };
    int b[19] = {
        2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,2,2
    };
    cout<<search(b,18,3)<<endl;
    return 0;
}