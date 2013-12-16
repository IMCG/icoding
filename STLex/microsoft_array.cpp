#include<iostream>
#include<algorithm>
using namespace std;

const int N=7;
void arrangeList(int A[], int N)
{
	//sort(A,A+N);						   //sort
	for(int i=1; i<N; i++)
	{
		//to define odd is big
		if(i%2 && A[i] < A[i-1])		   //define mid is the biger
			swap(A[i], A[i-1]);            //unsorted is ok..
		if(i%2==0 && A[i] > A[i-1])
			swap(A[i], A[i-1]);
	}
	return;
}
void arrangeList1(int A[], int N)
{
	sort(A,A+N);
	for(int i=2;i<N;i+=2)
	{
		swap(A[i],A[i-1]);
	}
	return ;
}
int main()
{
	int A[N]={3,5,7,8,4,9,10};
	for(auto i:A)
		cout<<i<<" ";
	cout<<endl;

	arrangeList(A,N);
	//arrangeList1(A,N);
	for(auto i:A)
		cout<<i<<" ";
	cout<<endl;
}
//Sample Input: 3 5 7 8 4 9 
//Sample Output: 3 < 5 > 4 < 8 >7 < 9
