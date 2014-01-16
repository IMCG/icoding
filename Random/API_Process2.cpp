// 02ProcessContorl.cpp :使用windows API进行进程管理的实验程序
/*
Auther:tweety

time: 2010-3-3
功能：
1.列出所有进程
2. 选择一个进程，用户可以选择结束它
3.用户输入参数，可以启动一个新的进程
*/
#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <TlHelp32.h>

int getProcess();//列出所有进程
int createProc();//用户输入参数，可以启动一个新的进程
int killprocess();//选择一个进程，用户可以选择结束它

int getProcess()
{
	PROCESSENTRY32 pe32;//Describes an entry from a list of the processes residing in the system address space when a snapshot was taken.
	pe32.dwSize = sizeof(pe32);
	HANDLE hprocessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);//给系统进程拍一个快照
	if (hprocessSnap == INVALID_HANDLE_VALUE)
	{
		printf("failed to snap processes!\n");
		return -1;
	}
	BOOL more = ::Process32First(hprocessSnap, &pe32);
	int numOfProcess = 0;
	while (more)
	{
		printf("进程名称：%s\t", pe32.szExeFile);
		printf("进程id： %u\t", pe32.th32ProcessID);
		printf("父进程id： %u\t\n", pe32.th32ParentProcessID);
		numOfProcess++;
		more = ::Process32Next(hprocessSnap, &pe32);
	}
	printf("共%u个进程\n", numOfProcess);
	::CloseHandle(hprocessSnap);//清除句柄对象
	return 1;
}
int createProc()
{
	LPSTR commandline = (LPSTR)malloc(100);
	printf("新建任务：\t");
	gets(commandline);
	if (strlen(commandline) >= 99)
	{
		::MessageBoxA(NULL, "your commandline is too long!", "error", MB_OK);
		return -1;
	}

	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = TRUE;

	BOOL ret = ::CreateProcess(NULL, commandline, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
	if (ret)
	{
		::CloseHandle(pi.hThread);//必须在父进程中关闭返回的进程和线程id号
		::CloseHandle(pi.hProcess);
	}
	return 1;
}
int killprocess()
{
	printf("输入要结束的进程id号：\n");
	BOOL bRet = FALSE;
	DWORD dwid;
	scanf("%u", &dwid);
	HANDLE hprocess = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwid);
	if (hprocess != NULL)
	{
		bRet = ::TerminateProcess(hprocess, 0);
		printf("进程%u已经结束：\n", dwid);
	}
	return bRet;
}

int _tmain(int argc, _TCHAR* argv[])
{
	createProc();
	getProcess();
	killprocess();
	system("pause");
	return 0;
