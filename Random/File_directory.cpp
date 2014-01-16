#include<Windows.h>
#include<tchar.h>
#include<stdio.h>
using namespace std;
int main()
{

	LPCWSTR szDirPath = TEXT("E:\\example_dir");
	if (!CreateDirectory(szDirPath, NULL))
	{
		printf("创建目录 %s 错误。\n", szDirPath);
		return 1;
	}
	printf("成功\n");
	return 0;
}