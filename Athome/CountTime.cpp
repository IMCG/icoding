//Windows系统下time()，clock()，timeGetTime()，GetTickCount()，QueryPerformanceCounter()来计时
#include <stdio.h>
#include <windows.h>
#include <time.h> //time_t time()  clock_t clock()
#include <Mmsystem.h>             //timeGetTime()
#pragma comment(lib, "Winmm.lib")   //timeGetTime()

int main()
{
	//用time()来计时  秒
	time_t timeBegin, timeEnd;
	timeBegin = time(NULL);
	Sleep(1000);
	timeEnd = time(NULL);
	printf("%d\n", timeEnd - timeBegin);


	//用clock()来计时  毫秒
	clock_t  clockBegin, clockEnd;
	clockBegin = clock();
	Sleep(800);
	clockEnd = clock();
	printf("%d\n", clockEnd - clockBegin);


	//用timeGetTime()来计时  毫秒
	DWORD  dwBegin, dwEnd;
	dwBegin = timeGetTime();
	Sleep(800);
	dwEnd = timeGetTime();
	printf("%d\n", dwEnd - dwBegin);


	//用GetTickCount()来计时  毫秒
	DWORD  dwGTCBegin, dwGTCEnd;
	dwGTCBegin = GetTickCount();
	Sleep(800);
	dwGTCEnd = GetTickCount();
	printf("%d\n", dwGTCEnd - dwGTCBegin);


	//用QueryPerformanceCounter()来计时  微秒
	LARGE_INTEGER  large_interger;
	double dff;
	__int64  c1, c2;
	QueryPerformanceFrequency(&large_interger);
	dff = large_interger.QuadPart;
	QueryPerformanceCounter(&large_interger);
	c1 = large_interger.QuadPart;
	Sleep(800);
	QueryPerformanceCounter(&large_interger);
	c2 = large_interger.QuadPart;
	printf("本机高精度计时器频率%lf\n", dff);
	printf("第一次计时器值%I64d 第二次计时器值%I64d 计时器差%I64d\n", c1, c2, c2 - c1);
	printf("计时%lf毫秒\n", (c2 - c1) * 1000 / dff);

	return 0;
}