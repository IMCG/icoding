//暴力枚举
# include <stdio.h>
# include <stdlib.h> /* for abs() */
# include <math.h>
void minAbsSumPair(int arr[], int arr_size)
{
	int inv_count = 0;
	int l, r, min_sum, sum, min_l, min_r;

	/* Array should have at least two elements*/
	if (arr_size < 2)
	{
		printf("Invalid Input");
		return;
	}

	/* Initialization of values */
	min_l = 0;
	min_r = 1;
	min_sum = arr[0] + arr[1];

	for (l = 0; l < arr_size - 1; l++)
	{
		for (r = l + 1; r < arr_size; r++)
		{
			sum = arr[l] + arr[r];
			if (abs(min_sum) > abs(sum))
			{
				min_sum = sum;
				min_l = l;
				min_r = r;
			}
		}
	}

	printf(" The two elements whose sum is minimum are %d and %d",
		arr[min_l], arr[min_r]);
}

/* Driver program to test above function */
int main()
{
	int arr[] = { 1, 60, -10, 70, -80, 85 };
	minAbsSumPair(arr, 6);
	getchar();
	return 0;
}

//Sorting 双指针  假设已经排序过
/* Function to print pair of elements having minimum sum */
void minAbsSumPair(int arr[], int n)
{
	// Variables to keep track of current sum and minimum sum
	int sum, min_sum = INT_MAX;

	// left and right index variables
	int l = 0, r = n - 1;

	// variable to keep track of the left and right pair for min_sum
	int min_l = l, min_r = n - 1;

	/* Array should have at least two elements*/
	if (n < 2)
	{
		printf("Invalid Input");
		return;
	}

	/* Sort the elements */
	quickSort(arr, l, r);

	while (l < r)
	{
		sum = arr[l] + arr[r];

		/*If abs(sum) is less then update the result items*/
		if (abs(sum) < abs(min_sum))
		{
			min_sum = sum;
			min_l = l;
			min_r = r;
		}
		if (sum < 0)
			l++;
		else
			r--;
	}

	printf(" The two elements whose sum is minimum are %d and %d",
		arr[min_l], arr[min_r]);
}

