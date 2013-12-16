#include<iostream>
using namespace std;

int *hello=new int[15];
void merge(int a[],int b[],int n,int m)
{
	int k=n+m-1;
	int i=n-1;
	int j=m-1;
	while(i>=0 && j>=0)
	{
		if(a[i]>a[j])
			a[k--]=a[i--];
		else
			a[k--]=b[j--];
	}
	while(j>=0)
		a[k--]=b[j--];
}
void merge1(int a[],int b[],int n,int m)
{
	int i=0,j=0,k=0;
	while(i<n&&j<m)
	{
		if(a[i]>b[j])
			hello[k++]=b[j++];
		else
			hello[k++]=a[i++];
	}
	while(i<n)
		hello[k++]=a[i++];
	while(j<m)
		hello[k++]=b[j++];
}
int main(){
    int a[15] = {
        1, 3, 7, 8, 9
    };
    int b[] = {
        2, 4, 5, 6, 10
    };
    int n = 5, m = 5;
    merge1(a, b, 5, 5);
    for(int i=0; i<m+n; ++i)
        //helloout<<a[i]<<" ";
	    cout<<hello[i]<<" ";
    return 0;
}

//merge two-mid sorted array.
//
#include<iostream>
using namespace std;

void merge(int a[],int begin,int mid,int last)
{
	for(int i=begin;i<=mid;i++)
	{
		if(a[i]>a[mid+1]){
			swap(a[i],a[mid+1]);
			for(int j=mid+1;j<last;j++){
				if(a[j]<a[j+1]) break;
				swap(a[j],a[j+1]);
		}
	  }
	}
}
int main()
{
	int a[10] = {
        8, 9, 11, 15, 17, 1, 3, 5, 12, 18
    };
	merge(a,0,4,9);
	for(int i=0; i<10; ++i)
        cout<<a[i]<<" ";
    return 0;
}