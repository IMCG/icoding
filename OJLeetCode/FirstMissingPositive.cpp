/*Given an unsorted integer array, 
find the first missing positive integer.
should run in O(n) time
For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.*/
#include<iostream>
using namespace std;
class Solution{
public:
	int firstMisingPosition(int A[], int n)
	{
		int *B = {};
		int *C = {};
		int i;
		for (i = 0; i < n; i++){
			if (A[i]>0)
				B[A[i]]++;
			else
				B[0]++;
		}
		for (i = 1; i < sizeof(B) / sizeof(B[0]); i++){
			C[i] += B[i];
		}
		for (i = 0; i < sizeof(C) / sizeof(C[0]); i++){
			if (C[i] != i)
				return i;
		}
		return 0;
	}
};
class Solution1{
public:
	int firstMissingPositive(int A[], int n)
	{
		bucket_sort(A, n);
		for (int i = 0; i < n; i++)
		{
			if (A[i] != i + 1)
				return i + 1;
		}
		return n + 1;
	}
private:
	static void bucket_sort(int A[], int n)
	{
		for (int  i = 0; i < n; i++)
		{
			while (A[i] != i + 1)
			{
				if (A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1])
					break;
				swap(A[i], A[A[i] - 1]);
			}
		}
	/*	for (int i = 0; i < n;i++)
		{
			cout << A[i] << " ";
		}
		cout << endl;*/
	}
};
int main()
{
	int A[] = { 1, 2, 0 };
	int B[8] = { 2, 3, 7, 6, 8, -1, -10, 15 };
	Solution1 s;
	int a = s.firstMissingPositive(B, 8);
	cout << a << endl;
}
