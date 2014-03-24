#include<stdlib.h>
#include<stdio.h>
#define NO_OF_CHARS 256

/* Returns an array of size 256 containg count
of characters in the passed char array */
int *getCharCountArray(char *str)
{
	int *count = (int *)calloc(sizeof(int), NO_OF_CHARS);
	int i;
	for (i = 0; *(str + i); i++)
		count[*(str + i)]++;
	return count;
}

/* The function returns index of first non-repeating
character in a string. If all characters are repeating
then returns -1 */
//这里重新扫描原数组而不是HashMap
int firstNonRepeating(char *str)
{
	int *count = getCharCountArray(str);
	int index = -1, i;

	for (i = 0; *(str + i); i++)
	{
		if (count[*(str + i)] == 1)
		{
			index = i;
			break;
		}
	}

	free(count); // To avoid memory leak
	return index;
}

/* Driver program to test above function */
int main()
{
	char str[] = "bbkccadd";
	int index = firstNonRepeating(str);
	if (index == -1)
		printf("Either all characters are repeating or string is empty");
	else
		printf("First non-repeating character is %c", str[index]);
	getchar();
	return 0;
}
/*The above approach takes O(n) time, but in practice it can be improved.
 The first part of the algorithm runs through the string to construct the 
 count array (in O(n) time). This is reasonable. But the second part about 
 running through the string again just to find the first non-repeater is not 
 good in practice   如果原数组太长的话，浪费。
*/

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#define NO_OF_CHARS 256

// Structure to store count of a character and index of the first
// occurrence in the input string
struct countIndex {
	int count;
	int index;
};

/* Returns an array of above structure type. The size of
   array is NO_OF_CHARS */
struct countIndex *getCharCountArray(char *str)
{
	struct countIndex *count =
		(struct countIndex *)calloc(sizeof(countIndex), NO_OF_CHARS);
	int i;
	for (i = 0; *(str + i); i++)
	{
		(count[*(str + i)].count)++;

		// If it's first occurrence, then store the index
		if (count[*(str + i)].count == 1)
			count[*(str + i)].index = i;//存储第一次出现位置
	}
	return count;
}

/* The function returns index of first non-repeating
   character in a string. If all characters are repeating
      then reurns INT_MAX */
int firstNonRepeating(char *str)
{
	struct countIndex *count = getCharCountArray(str);
	int result = INT_MAX, i;

	for (i = 0; i < NO_OF_CHARS; i++)
	{
		// If this character occurs only once and appears
		// before the current result, then update the result
		//添加一个index解决了不能直接遍历hashMap的问题。
		if (count[*(str + i)].count == 1 &&
			result > count[*(str + i)].index)
			result = i;
	}

	free(count); // To avoid memory leak
	return result;
}

/* Driver program to test above function */
int main()
{
	char str[] = "eeksasapk";
	int index = firstNonRepeating(str);
	if (index == INT_MAX)
		printf("Either all characters are repeating or string is empty");
	else
		printf("First non-repeating character is %c", str[index]);
	getchar();
	return 0;
}