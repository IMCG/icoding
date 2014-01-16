#include<iostream>
#include<Windows.h>
#include<Psapi.h>
#include<windef.h>
#include <tchar.h>
#pragma comment(lib,"psapi.lib")
using namespace std;

#define DIV 1024
#define WIDTH 7
int cpuUsed;
int cpuIdle;
void Cputimes()
{
	static FILETIME idleTime, kernelTime, userTime,
		last_idleTime, last_kernelTime, last_userTime;
	int idle, kernel, user, sys;

	last_idleTime = idleTime;
	last_kernelTime = kernelTime;
	last_userTime = userTime;
	BOOL res = GetSystemTimes(&idleTime, &kernelTime, &userTime);
	idle = (idleTime.dwLowDateTime - last_idleTime.dwLowDateTime) / 100;
	kernel = (kernelTime.dwLowDateTime - last_kernelTime.dwLowDateTime) / 100;
	user = (userTime.dwLowDateTime - last_userTime.dwLowDateTime) / 100;

	sys = kernel + user;
	//cpuIdle = (int)((idle)* 100 / sys);
	if (sys != 0){
		cpuUsed = (int)((sys - idle) * 100 / sys);
		cout << cpuUsed << "%使用" << endl;
	}
}
void cputimes()
{
	static FILETIME idletime, coretime, usertime,
		preidletime, precoretime, preusertime;
	int idle, core, user;
	preidletime = idletime;
	precoretime = coretime;
	preusertime = usertime;
	GetSystemTimes(&idletime, &coretime, &usertime);
	idle = (idletime.dwLowDateTime - precoretime.dwLowDateTime) / 100;
	core = (coretime.dwLowDateTime - precoretime.dwLowDateTime) / 100;
	user = (usertime.dwLowDateTime - precoretime.dwLowDateTime) / 100;
	if ((core + user) != 0)
	{
		cpuIdle = (idle)* 100 / (core + user);
		cpuUsed = (core + user - idle) * 100 / (core + user);
	}
	cout << cpuUsed << "%使用" << endl;
}
void globalmem()
{
	MEMORYSTATUSEX statex;

	statex.dwLength = sizeof (statex);

	GlobalMemoryStatusEx(&statex);

	_tprintf(TEXT("There is  %*ld percent of memory in use.\n"),
		WIDTH, statex.dwMemoryLoad);
	_tprintf(TEXT("There are %*I64d total MB of physical memory.\n"),
		WIDTH, statex.ullTotalPhys / DIV/DIV);
	_tprintf(TEXT("There are %*I64d used  MB of physical memory.\n"),
		WIDTH, (statex.ullTotalPhys-statex.ullAvailPhys) / DIV/DIV);
}
int main()
{
	Cputimes();
	cputimes();
	//cout << cpuUsed << "%使用" << endl;
	//cout << cpuIdle << "%空闲" << endl;
	return 0;
}