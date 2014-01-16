#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <stdio.h>
#include <Psapi.h>
#include <windef.h>
#include <iostream>
using namespace std;
/*变量声明*/
int i = 0;//item index
HANDLE Snapshot;
BOOL return_value;
PROCESSENTRY32 processListStr;
PROCESS_MEMORY_COUNTERS pmc;
int memory;
int psPid;
int cpuidle, cpuused;
int memusedprecent;
DWORDLONG memused, memunused;
void pslist(void)
{
	memory = processListStr.cntThreads;
	Snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	//获得某一时刻系统的进程、堆（heap）、模块（module）或线程的快照信息
	processListStr.dwSize = sizeof(PROCESSENTRY32);
	return_value = Process32First(Snapshot, &processListStr);
	while (return_value)
	{
		_tprintf(TEXT("%-28s"), processListStr.szExeFile);
		printf("%-13d%d\t",processListStr.th32ProcessID, processListStr.pcPriClassBase);
		//m_ProcessIndex[i]=processListStr.th32ProcessID;//save ID into array to teminate 
		//内存使用
		HANDLE temp = OpenProcess(PROCESS_QUERY_INFORMATION, TRUE,
			processListStr.th32ProcessID);
		if (GetProcessMemoryInfo(temp, &pmc, sizeof(pmc)))
		{
			//tempprocess.memuse = pmc.WorkingSetSize / 1024;
			_tprintf(TEXT("%d\n"), pmc.WorkingSetSize / 1024);
		}
		else
			cout << "\n";
		CloseHandle(temp);
		return_value = Process32Next(Snapshot, &processListStr);
		//获得系统进程链表中下一个进程的信息
		i++;
	}
}

void printhead()/*打印头信息*/
{
	printf("    %-20s   %-8s   %s\t   %s\n", "进程名", "PID", "优先级","内存使用");
}
void Cputimes()
{
	static FILETIME idletime, kerneltime, usertime, preidletime,
		prekerneltime, preusertime;
	int idle, kernel, user;
	preidletime = idletime;
	prekerneltime = kerneltime;
	preusertime = usertime;

	GetSystemTimes(&idletime, &kerneltime, &usertime);
	idle = (idletime.dwLowDateTime - preidletime.dwLowDateTime) / 100;
	kernel = (kerneltime.dwLowDateTime - prekerneltime.dwLowDateTime) / 100;
	user = (usertime.dwLowDateTime - preusertime.dwLowDateTime) / 100;
	int sys = kernel + user;
	if (sys != 0)
	{
		cpuidle = (int)((idle)* 100 / sys);
		cpuused = (int)((sys - idle) * 100 / sys);
	}
}
void globalmem()
{
	MEMORYSTATUSEX statux;
	statux.dwLength = sizeof(statux);
	GlobalMemoryStatusEx(&statux);
	memused = (statux.ullTotalPhys - statux.ullAvailPhys) / 1024 / 1024;
	memunused = statux.ullAvailPhys / 1024 / 1024;
	memusedprecent = statux.dwMemoryLoad;
}
void EndProcess()
{
	int Result;
	HANDLE ProcHandle, Handle;

	Handle = CreateToolhelp32Snapshot((DWORD)TH32CS_SNAPPROCESS, 0);
	processListStr.dwSize = sizeof(PROCESSENTRY32);
	Result = Process32First(Handle, &processListStr);

	while (Result)
	{

		if (processListStr.th32ProcessID == psPid)  ///此处〈---- 
		{

			ProcHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processListStr.th32ProcessID);
			TerminateProcess(ProcHandle, 0);
			printf("成功结束掉指定进程！！\n");
			break;
		}

		Result = Process32Next(Handle, &processListStr);
	}
}
int main()
{
	printhead();
	pslist();
	Cputimes();
	globalmem();
	cout << "进程数目" << i << endl;
	cout << "CPU状况" << cpuused << "%使用/" << cpuidle << "%空闲" << endl;
	cout << "内存情况" << memused << "MB使用/" << memunused << "MB空闲/"
		<< "内存使用率" << memusedprecent << "%" << endl;
	printf("请输入要结束进程的PID:");
	while (scanf_s("%d", &psPid)){
		EndProcess();
		printf("请输入要结束进程的PID:");
	}
	return 0;
}