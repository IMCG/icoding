#include <iostream>
#pragma warning(disable:4996)
using namespace std;
int main(){
	char arr[5];
	int i;
	char fname;
	for (i = 0; i<sizeof(arr); i++)
	{
		//%c前面必须添加一个空格，用于消耗末尾的\n....
		printf("enter name of your friend:");
		scanf(" %c", &fname);
		
	}
	return 0;
}