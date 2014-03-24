//@1
//Output: 0 1 2 0 3 0 1
#include<stdio.h>
void fun(int x)
{
	if (x > 0)
	{
		fun(--x);
		printf("%d ", x);
		fun(--x);
	}
}

int main()
{
	int a = 4;
	fun(a);
	getchar();
	return 0;
}
//@2
//fun() returns the maximum value 
int fun(int a[], int n)
{
	int x;
	if (n == 1)
		return a[0];
	else
		x = fun(a, n - 1);
	if (x > a[n - 1])
		return x;
	else
		return a[n - 1];
}
//return Maximum  
int fun(int a[], int n)
{
	return n == 1 ? a[0] : max(a[n - 1], fun(a, n - 1));
}

int main()
{
	int arr[] = { 12, 10, 30, 50, 100 };
	printf(" %d ", fun(arr, 5));
	getchar();
	return 0;
}

//@3
int fun(int i)
{
	if (i % 2) return (i++);
	else return fun(fun(i - 1));
}

int main()
{
	printf(" %d ", fun(200));
	getchar();
	return 0;
}
//Output: 199