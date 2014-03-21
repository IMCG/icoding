//Simple
/*Function to print leaders in an array */
void printLeaders(int arr[], int size)
{
  int i, j;
 
  for (i = 0; i < size; i++)
  {
    for (j = i+1; j < size; j++)
    {
        if(arr[i] <= arr[j])
          break;
    }    
    if(j == size) // the loop didn't break
    {
        printf("%d ", arr[i]);
    }
  }
}

//My func
void printLeaders(int arr[], int size){
	int max_cur = INT_MIN;
	for (int i = size - 1; i >= 0; --i){
		if (arr[i] > max_cur){
			cout << arr[i] << " ";
			max_cur = arr[i];
		}
	}
}
//Scan from right
/*Function to print leaders in an array */
void printLeaders(int arr[], int size)
{
  int max_from_right =  arr[size-1];
  int i;
 
  /* Rightmost element is always leader */
  printf("%d ", max_from_right);
     
  for(i = size-2; i >= 0; i--)
  {
    if(max_from_right < arr[i])
    {
       printf("%d ", arr[i]);
       max_from_right = arr[i];
    }
  }    
}
