/*Given an array arr[] of integers, find out the difference between any two 
elements such that larger element appears after the smaller number in arr[].

Examples: If array is [2, 3, 10, 6, 4, 8, 1] then returned value should be 
8 (Diff between 10 and 2). If array is [ 7, 9, 5, 6, 3, 2 ] then returned 
value should be 2 (Diff between 7 and 9)
*/

//Simple  暴力枚举   
/* The function assumes that there are at least two
elements in array.
The function returns a negative value if the array is
sorted in decreasing order.
Returns 0 if elements are equal */
int maxDiff(int arr[], int arr_size)
{
	int max_diff = arr[1] - arr[0];
	int i, j;
	for (i = 0; i < arr_size; i++)
	{
		for (j = i + 1; j < arr_size; j++)
		{
			if (arr[j] - arr[i] > max_diff)
				max_diff = arr[j] - arr[i];
		}
	}
	return max_diff;
}

//Tricky and Efficient   维护一个最小下标
int maxDiff(int arr[], int size)
{
	//min_index=arr[1]-arr[0];
	int min_index = 0;
	int max_diff = 0;
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < arr[min_index]){
			min_index = i;
		}
		else if (arr[i]>arr[min_index]){
			max_diff = max(max_diff, arr[i] - arr[min_index]);
		}
	}
	return max_diff;
}

//Another Tricky Solution  把连续的diff先求出来  Tricky
int maxDiff(int arr[], int n)
{
	// Create a diff array of size n-1. The array will hold
	//  the difference of adjacent elements
	int diff[n - 1];
	for (int i = 0; i < n - 1; i++)
		diff[i] = arr[i + 1] - arr[i];

	// Now find the maximum sum subarray in diff array
	//最大字数组问题
	int max_diff = diff[0];
	for (int i = 1; i<n - 1; i++)
	{
		if (diff[i - 1] > 0)
			diff[i] += diff[i - 1];
		if (max_diff < diff[i])
			max_diff = diff[i];
	}
	return max_diff;
}