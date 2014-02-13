#include <iostream>
#include <Windows.h>
#include <process.h>
using namespace std;
int g_nCount;
//
unsigned int __stdcall ThreadFun(PVOID pM)
{
	g_nCount++;
	printf("PID: %4d say%d\n", GetCurrentThreadId, g_nCount);
	return 0;
}
int main()
{
	const int THREAD_NUM = 10;
	HANDLE handle[THREAD_NUM];

	g_nCount = 0;
	for (int i = 0; i < THREAD_NUM; i++)
	{
		handle[i] = (HANDLE)_beginthreadex(NULL, 0, ThreadFun, NULL, 0, NULL);
	}
	WaitForMultipleObjects(THREAD_NUM, handle, TRUE, INFINITE);
	return 0;
}