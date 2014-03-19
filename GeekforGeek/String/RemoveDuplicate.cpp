# include <stdio.h>
# include <stdlib.h>
 
/* Function to remove duplicates in a sorted array */
char *removeDupsSorted(char *str);
 
/* Utitlity function to sort array A[] */
void quickSort(char A[], int si, int ei);
 
/* Function removes duplicate characters from the string
   This function work in-place and fills null characters
   in the extra space left */
char *removeDups(char *str)
{
  int len = strlen(str);
  quickSort(str, 0, len-1);
  return removeDupsSorted(str);
}     
 
/* Function to remove duplicates in a sorted array */
char *removeDupsSorted(char *str)
{
  int res_ind = 1, ip_ind = 1;
 
  /* In place removal of duplicate characters*/
  while(*(str + ip_ind))
  {
    if(*(str + ip_ind) != *(str + ip_ind - 1))
    {
      *(str + res_ind) = *(str + ip_ind);
      res_ind++;
    }
    ip_ind++;
  }      
 
  /* After above step string is stringiittg.
     Removing extra iittg after string*/
  *(str + res_ind) = '\0';
   
  return str;
}
 
/* Driver program to test removeDups */
int main()
{
  char str[] = "eeeefggkkosss";
  printf("%s", removeDups(str));
  getchar();
  return 0;
}
 
/* FOLLOWING FUNCTIONS ARE ONLY FOR SORTING
    PURPOSE */
void exchange(char *a, char *b)
{
  char temp;
  temp = *a;
  *a   = *b;
  *b   = temp;
}
 
int partition(char A[], int si, int ei)
{
  char x = A[ei];
  int i = (si - 1);
  int j;
 
  for (j = si; j <= ei - 1; j++)
  {
    if(A[j] <= x)
    {
      i++;
      exchange(&A[i], &A[j]);
    }
  }
  exchange (&A[i + 1], &A[ei]);
  return (i + 1);
}
 
/* Implementation of Quick Sort
A[] --> Array to be sorted
si  --> Starting index
ei  --> Ending index
*/
void quickSort(char A[], int si, int ei)
{
  int pi;    /* Partitioning index */
  if(si < ei)
  {
    pi = partition(A, si, ei);
    quickSort(A, si, pi - 1);
    quickSort(A, pi + 1, ei);
  }
}