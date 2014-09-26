//模式匹配
//update 2014/9/23
//1.暴力匹配

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//注意k的作用
//#include<string>
int index(string&str, string substr){
	int i = 0, j = 0, k = 0;
	//小优化
	int strlen = str.length();
	int sublen = substr.length();
	while (i < strlen && j < sublen){
		if (str[i] == substr[j]){
			++i;
			++j;
		}
		else{
			//当然不用k也可以(用i,j计算k):
			//i = i - j + 1; j = 0; 最后return i - j;
			j = 0;
			i = ++k;
		}
	}
	return j == substr.length() ? k : -1;
}
//KMP1
void preKmp(char *x, int m, int kmpNext[]) {
   int i, j;

   i = 0;
   j = kmpNext[0] = -1;
   while (i < m) {
      while (j > -1 && x[i] != x[j])
         j = kmpNext[j];
      i++;
      j++;
      if (x[i] == x[j])
         kmpNext[i] = kmpNext[j];
      else
         kmpNext[i] = j;
   }
}


void KMP(char *x, int m, char *y, int n) {
   int i, j, kmpNext[XSIZE];

   /* Preprocessing */
   preKmp(x, m, kmpNext);

   /* Searching */
   i = j = 0;
   while (j < n) {
      while (i > -1 && x[i] != y[j])
         i = kmpNext[i];
      i++;
      j++;
      if (i >= m) {
         OUTPUT(j - i);
         i = kmpNext[i];
      }
   }
}




//KMP2
/*计算部分匹配表，即next数组。*/
void compute_prefix(const char*pattern, int next[])
{
	int i;
	int j = -1;
	const int m = strlen(pattern);
	next[0] = j;
	for (i = 1; i < m; i++)
	{
		while (j>-1 && pattern[j + 1] != pattern[i])
			j = next[j];
		if (pattern[i] == pattern[j + 1])
			j++;
		next[i] = j;
	}
}
/*KMP：成功返回第一次匹配位置，失败返回-1*/
int kmp(const char *text, const char *pattern)
{
	int i;
	int j = -1;
	const int n = strlen(text);
	const int m = strlen(pattern);
	if (n == 0 && m == 0)return 0;
	if (m == 0)return 0;
	int *next = (int*)malloc(sizeof(int)*m);
	compute_prefix(pattern, next);

	for (i = 0; i < n; i++){
		while (j>-1 && pattern[j + 1] != text[i])
			j = next[j];
		if (text[i] == pattern[j + 1])j++;
		if (j == m - 1){
			free(next);
			return i - j;
		}
	}
	free(next);
	return -1;
}
char *strStr(const char *haystack, const char *needle)
{
	int pos = kmp(haystack, needle);
	if (pos == -1)return nullptr;
	else return (char*)haystack + pos;
}
int main()
{
	char text[] = "ABC ABCDAB ABCDABCDABDE";
	char pattern[] = "ABCDABCD";
	char *ch = text;
	int i = kmp(text, pattern);
	if (i >= 0)printf("matched @:%s\n", ch + i);
	return 0;
}
