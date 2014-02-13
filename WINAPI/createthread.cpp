#include <iostream>
#include <Windows.h>
using namespace std;
//子线程
DWORD WINAPI ThreadFun(LPVOID pM)
{
	printf("PID: %d\n", GetCurrentThreadId());
	return 0;
}
//主函数，其实就是主函数执行的函数
int main()
{
	HANDLE handle = CreateThread(NULL, 0, ThreadFun, NULL, 0, NULL);
	WaitForSingleObject(handle, INFINITE);
	return 0;
}