//Write an efficient C program to find smallest and second smallest element in an array.
//
void printSmall(int arr[], int size)
{
	if (size < 2)
		return;
	int smallest = INT_MAX;
	int small = INT_MAX;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] <= smallest)
			smallest = arr[i];
		else {
			if (arr[i] < small)
				small = arr[i];
		}
	}
	cout << smallest << " " << small;
	return;
}

//geeks
/* Function to print first smallest and second smallest elements */
void print2Smallest(int arr[], int arr_size)
{
	int i, first, second;

	/* There should be atleast two elements */
	if (arr_size < 2)
	{
		printf(" Invalid Input ");
		return;
	}

	first = second = INT_MAX;
	for (i = 0; i < arr_size; i++)
	{
		/* If current element is smaller than first then update both
		first and second */
		if (arr[i] < first)
		{
			second = first;
			first = arr[i];
		}

		/* If arr[i] is in between first and second then update second  */
		else if (arr[i] < second && arr[i] != first)
			second = arr[i];
	}
	if (second == INT_MAX)
		printf("There is no second smallest element\n");
	else
		printf("The smallest element is %d and second Smallest element is %d\n",
		first, second);
}