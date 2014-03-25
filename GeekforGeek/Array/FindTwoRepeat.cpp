//暴力枚举 也可以排序然后遍历
void printRepeating(int arr[], int size)
{
	int i, j;
	printf(" Repeating elements are ");
	for (i = 0; i < size; i++)
	for (j = i + 1; j < size; j++)
	if (arr[i] == arr[j])
		printf(" %d ", arr[i]);
}
//哈希表
void printRepeating(int arr[], int size)
{
	int *count = (int *)calloc(sizeof(int), (size - 2));
	int i;

	printf(" Repeating elements are ");
	for (i = 0; i < size; i++)
	{
		//hashMap的这种用法 而不是两次遍历
		if (count[arr[i]] == 1)
			printf(" %d ", arr[i]);
		else
			count[arr[i]]++;
	}
}
//能求出来 a+b  a*b
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* function to get factorial of n */
int fact(int n);

void printRepeating(int arr[], int size)
{
	int S = 0;  /* S is for sum of elements in arr[] */
	int P = 1;  /* P is for product of elements in arr[] */
	int x, y;   /* x and y are two repeating elements */
	int D;      /* D is for difference of x and y, i.e., x-y*/
	int n = size - 2, i;

	/* Calculate Sum and Product of all elements in arr[] */
	for (i = 0; i < size; i++)
	{
		S = S + arr[i];
		P = P*arr[i];
	}

	S = S - n*(n + 1) / 2;  /* S is x + y now */
	P = P / fact(n);         /* P is x*y now */

	D = sqrt(double(S*S - 4 * P)); /* D is x - y now */

	x = (D + S) / 2;
	y = (S - D) / 2;

	printf("The two Repeating elements are %d & %d", x, y);
}

int fact(int n)
{
	return (n == 0) ? 1 : n*fact(n - 1);
}

int main()
{
	int arr[] = { 4, 2, 4, 5, 2, 3, 1 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	printRepeating(arr, arr_size);
	getchar();
	return 0;
}

// Method 5 (Use array elements as index) 想想原理

void printRepeating(int arr[], int size)
{
	int i;

	printf("\n The repeating elements are");

	for (i = 0; i < size; i++)
	{
		if (arr[abs(arr[i])] > 0)
			arr[abs(arr[i])] = -arr[abs(arr[i])];
		else
			printf(" %d ", abs(arr[i]));
	}
}

int main()
{
	int arr[] = { 1, 3, 2, 2, 1 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	printRepeating(arr, arr_size);
	getchar();
	return 0;
}