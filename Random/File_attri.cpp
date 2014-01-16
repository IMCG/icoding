/* ************************************
*《精通Windows API》
* 示例代码
* attr.c
* 4.3.7  获取、设置文件属性和时间
**************************************/

/* 头文件　*/
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
/* 函数申明　*/
DWORD ShowFileTime(PFILETIME lptime);
DWORD ShowFileSize(DWORD dwFileSizeHigh, DWORD dwFileSizeLow);
DWORD ShowFileAttrInfo(DWORD dwAttribute);

/* ************************************
* DWORD ShowFileAttributes(LPSTR szPath)
* 功能	获取并显示文件属性，
*		调用ShowFileTime、ShowFileSize和
*		ShowFileAttrInfo函数
*
* 参数	LPTSTR szPath，获取并显示此文件的属性
*
* 返回值	0代表执行完成，1代码发生错误
**************************************/
DWORD ShowFileAttributes(LPSTR szPath)
{
	//文件属性结构
	WIN32_FILE_ATTRIBUTE_DATA wfad;
	printf("文件：%s\n", szPath);
	//获取文件属性
	if (!GetFileAttributesEx(TEXT("szPath"),
		GetFileExInfoStandard,
		&wfad))
	{
		printf("获取文件属性错误：%d\n", GetLastError());
		return 1;
	}
	//显示相关时间
	printf("创建时间：\t");
	ShowFileTime(&(wfad.ftCreationTime));
	printf("最后访问时间：\t");
	ShowFileTime(&(wfad.ftLastAccessTime));
	printf("最后修改时间：\t");
	ShowFileTime(&(wfad.ftLastWriteTime));
	//显示文件大小
	ShowFileSize(wfad.nFileSizeHigh, wfad.nFileSizeLow);
	//显示文件属性
	ShowFileAttrInfo(wfad.dwFileAttributes);

	return 0;
}

/* ************************************
* DWORD ShowFileAttrInfo(DWORD dwAttribute)
* 功能	打印将文件属性
*
* 参数	DWORD dwAttribute，文件属性
*
* 返回值 0
**************************************/
DWORD ShowFileAttrInfo(DWORD dwAttribute)
{
	//依次判断属性，并显示。
	printf("文件属性：\t");
	if (dwAttribute&FILE_ATTRIBUTE_ARCHIVE)
		printf("<ARCHIVE> ");
	if (dwAttribute&FILE_ATTRIBUTE_COMPRESSED)
		printf("<压缩> ");
	if (dwAttribute&FILE_ATTRIBUTE_DIRECTORY)
		printf("<目录> ");
	if (dwAttribute&FILE_ATTRIBUTE_ENCRYPTED)
		printf("<加密> ");
	if (dwAttribute&FILE_ATTRIBUTE_HIDDEN)
		printf("<隐藏> ");
	if (dwAttribute&FILE_ATTRIBUTE_NORMAL)
		printf("<NORMAL> ");
	if (dwAttribute&FILE_ATTRIBUTE_OFFLINE)
		printf("<OFFLINE> ");
	if (dwAttribute&FILE_ATTRIBUTE_READONLY)
		printf("<只读> ");
	if (dwAttribute&FILE_ATTRIBUTE_SPARSE_FILE)
		printf("<SPARSE> ");
	if (dwAttribute&FILE_ATTRIBUTE_SYSTEM)
		printf("<系统文件> ");
	if (dwAttribute&FILE_ATTRIBUTE_TEMPORARY)
		printf("<临时文件> ");

	printf("\n");

	return 0;
}
/* ************************************
* DWORD ShowFileSize(DWORD dwFileSizeHigh, DWORD dwFileSizeLow)
* 功能	打印文件大小信息
*
* 参数	DWORD dwFileSizeHigh，文件大小高32位
*		DWORD dwFileSizeLow，文件大小低32位
*
* 返回值 0
**************************************/
DWORD ShowFileSize(DWORD dwFileSizeHigh, DWORD dwFileSizeLow)
{
	ULONGLONG liFileSize;
	liFileSize = dwFileSizeHigh;

	//高们移动32位
	liFileSize <<= sizeof(DWORD)* 8;
	liFileSize += dwFileSizeLow;
	printf("文件大小：\t%I64u 字节\n", liFileSize);
	return 0;
}

/* ************************************
*DWORD ShowFileTime(PFILETIME lptime)
* 功能	轮换文件时间，将打印
*
* 参数	PFILETIME lptime，指向文件时间的指针
*
* 返回值 0
**************************************/
DWORD ShowFileTime(PFILETIME lptime)
{
	//文件时间结构
	FILETIME ftLocal;
	//系统时间结构
	SYSTEMTIME st;
	//调整为系统所在时区的时间
	FileTimeToLocalFileTime(
		lptime,
		&ftLocal
		);
	//将文件时间转换为SYSTEMTIME格式，便于显示。
	FileTimeToSystemTime(
		&ftLocal,
		&st
		);
	//显示时间信息字符串
	printf("%4d年%.2d月%#02d日，%.2d:%.2d:%.2d\n",
		st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);

	return 0;
}
/* ************************************
* int main(int argc, PCHAR argv[])
* 功能	设置和获取文件属性等
*
* 参数	显示第一个参数指定文件的属性、时间、大小
*
* 返回值	0代表执行完成，1代码发生错误
**************************************/
int main(int argc, PCHAR argv[])
{
	if (argc != 3)
	{
		printf("请输入参数\n");
		printf("显示第一个参数指定文件的属性、时间、大小；\n");
		return 1;
	}
	ShowFileAttributes(argv[1]);
	return 0;
}