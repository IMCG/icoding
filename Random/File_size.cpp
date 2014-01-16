
/* 头文件　*/
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
using namespace std;
/* ************************************
* DWORD ReadFileContent(LPSTR szFilePath)
* 功能	获取文件大小
*		读取文件内容，并以16进制的形式打印出来
* 参数	LPSTR szFilePath
*		文件路径
**************************************/
DWORD ReadFileContent(LPCWSTR szFilePath)
{
	//文件大小
	HANDLE hFileRead;
	//保存文件大小
	LARGE_INTEGER liFileSize;
	//打开已经存在的文件，读取内容。	
	hFileRead = CreateFile(szFilePath,// 要打开的文件名
		GENERIC_READ,			   // 以读方式打开
		FILE_SHARE_READ,           // 可共享读
		NULL,                      // 默认安全设置
		OPEN_EXISTING,             // 只打开已经存在的文件
		FILE_ATTRIBUTE_NORMAL,     // 常规文件属性
		NULL);                     // 无模板

	//打开文件是否成功。
	if (hFileRead == INVALID_HANDLE_VALUE)
	{
		printf("打开文件失败：%d", GetLastError());
	}

	if (!GetFileSizeEx(hFileRead, &liFileSize))
	{
		printf("获取文件大小失败：%d", GetLastError());
	}
	else
	{
		printf("文件大小为：%d\n", liFileSize.QuadPart);
	}
	CloseHandle(hFileRead);
	return 0;
}

int main(void)
{
	ReadFileContent(TEXT("E:\\test\\one.txt"));
	return 0;
}