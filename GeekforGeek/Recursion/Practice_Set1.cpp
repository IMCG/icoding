int fun1(int x, int y) 
{
  if(x == 0)
    return y;
  else
    return fun1(x - 1,  x + y);
}
// Answer: The function fun() calculates and returns ((1 + 2 … + x-1 + x) +y) 
// which is x(x+1)/2 + y. For example if x is 5 and y is 2, then fun should 
// return 15 + 2 = 17.

//思想。
void fun2(int arr[], int start_index, int end_index)
{
  if(start_index >= end_index)   
     return;
  int min_index; 
  int temp; 
 
  /* Assume that minIndex() returns index of minimum value in 
    array arr[start_index...end_index] */
  min_index = minIndex(arr, start_index, end_index);
 
  temp = arr[start_index];
  arr[start_index] = arr[min_index];
  arr[min_index] = temp;        
 
  fun2(arr, start_index + 1, end_index);
}     
// Answer: The function fun2() is a recursive implementation of Selection Sort.