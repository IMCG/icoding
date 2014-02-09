#include <windows.h>
#include <tchar.h> 
#include <stdio.h>
#include <strsafe.h>
#pragma comment(lib, "User32.lib")

void DisplayErrorBox(LPTSTR lpszFunction);
DWORD ShowFileTime(PFILETIME lptime);

int _tmain(int argc, TCHAR *argv[])
{
	//Contains information about the file that is found by the 		FindFirstFile,FindNextFile function.
	WIN32_FIND_DATA ffd;
	//filesize   LONGLONG QuadPart
	LARGE_INTEGER filesize;
	//typedef char TCHAR
	TCHAR szDir[MAX_PATH];
	size_t length_of_arg;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	DWORD dwError = 0;

	// If the directory is not specified as a command-line argument,
	// print usage.

	if (argc != 2)
	{
		_tprintf(TEXT("\nUsage: %s <directory name>\n"), argv[0]);
		return (-1);
	}

	// Check that the input path plus 3 is not longer than MAX_PATH.
	// Three characters are for the "\*" plus NULL appended below.

	StringCchLength(argv[1], MAX_PATH, &length_of_arg);

	if (length_of_arg > (MAX_PATH - 3))
	{
		_tprintf(TEXT("\nDirectory path is too long.\n"));
		return (-1);
	}
	
	//there input the directory------------------------->>>
	_tprintf(TEXT("\nTarget directory is %s\n\n"), argv[1]);

	// Prepare string for use with FindFile functions.  First, copy the
	// string to a buffer, then append '\*' to the directory name.
	
	StringCchCopy(szDir, MAX_PATH, argv[1]);
	StringCchCat(szDir, MAX_PATH, TEXT("\\*"));

	// Find the first file in the directory.
	//_In_   LPCTSTR lpFileName,
  	//_Out_  LPWIN32_FIND_DATA lpFindFileData
	hFind = FindFirstFile(szDir, &ffd);

	if (INVALID_HANDLE_VALUE == hFind)
	{	
		//printf(""FindFirstFile_error");
		DisplayErrorBox(TEXT("FindFirstFile"));
		return dwError;
	}

	// List all the files in the directory with some info about them.

	do
	{	
		//if directory
		if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			_tprintf(TEXT("  %s   <DIR>\n"), ffd.cFileName);
		}
		else
		{
			filesize.LowPart = ffd.nFileSizeLow;
			filesize.HighPart = ffd.nFileSizeHigh;
			_tprintf(TEXT("  %s   %ld bytes\n"), ffd.cFileName, filesize.QuadPart);
			printf("创建时间：\t");
			ShowFileTime(&ffd.ftCreationTime);
			printf("上次访问时间：\t");
			ShowFileTime(&ffd.ftLastWriteTime);
			printf("\n");
		}
	} while (FindNextFile(hFind, &ffd) != 0);
	//Retrieves the calling thread's last-error code value
	dwError = GetLastError();
	//ERROR_NO_MORE_FILES::No more files have been found.
	if (dwError != ERROR_NO_MORE_FILES)
	{	//error
		DisplayErrorBox(TEXT("FindFirstFile"));
	}

	FindClose(hFind);
	return dwError;
}
DWORD ShowFileTime(PFILETIME lptime)
{
	//文件时间结构
	FILETIME ftLocal;
	//系统时间结构
	SYSTEMTIME st;
	//调整为系统所在时区的时间
	FileTimeToLocalFileTime(lptime, &ftLocal);
	//将文件时间转换为SYSTEMTIME格式，便于显示
	FileTimeToSystemTime(&ftLocal, &st);
	printf("%4d年%#02d月%#02d日，%#02d：%#02d：%#02d\n",st.wYear,st.wMonth,st.wDay,st.wHour,st.wMinute,st.wSecond);
	return 0;
}
void DisplayErrorBox(LPTSTR lpszFunction)
{
	// Retrieve the system error message for the last-error code

	LPVOID lpMsgBuf;
	LPVOID lpDisplayBuf;
	DWORD dw = GetLastError();

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dw,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf,
		0, NULL);

	// Display the error message and clean up

	lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT,
		(lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40)*sizeof(TCHAR));
	StringCchPrintf((LPTSTR)lpDisplayBuf,
		LocalSize(lpDisplayBuf) / sizeof(TCHAR),
		TEXT("%s failed with error %d: %s"),
		lpszFunction, dw, lpMsgBuf);
	MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);

	LocalFree(lpMsgBuf);
	LocalFree(lpDisplayBuf);
}