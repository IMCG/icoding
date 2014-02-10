//http://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array/

/*Program to find the smallest positive missing number*/
#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/*Utility function that puts all non_positive numbers on left side of array*/
//跟QuickSort的partition函数差不多
int segregate(int arr[], int size)
{
	int j = 0, i;
	for (i = 0; i < size; i++)
	{
		if (arr[i] <= 0)
		{
			swap(&arr[i], &arr[j]);
			j++;
		}
	}
	return j;
}
/*Find the smallest positive missing number in an array that contains all
positive integers*/
int findMissingPositive(int arr[], int size)
{
	int i;
	//Mark arr[i] as visited by making arr[arr[i]-1]negative.
	// 1 is subtracted because index start from 0 and positive numbers start from 1
	// To mark presence of an element x, we change the value at the index x to negative
	for (i = 0; i < size; i++)
	{
		if (abs(arr[i]) - 1 < size && arr[abs(arr[i]) - 1] > 0)
			arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
	}
	//Return the first index value at which is positive
	for (i = 0; i < size; i++)
	{
		if (arr[i]>0)
			return i + 1;//1 is added because indexed start from 0
	}
	return size + 1;
}
int findMising(int arr[], int size)
{
	int shift = segregate(arr, size);
	return findMissingPositive(arr + shift, size - shift);
}
int main()
{
	int arr[] = { 0, 10, 2, 1, -10, -20 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	int missing = findMising(arr, arr_size);
	printf("The smallest positive missing number %d", missing);
	return 0;
}