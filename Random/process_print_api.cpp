#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <stdio.h>
#include <Psapi.h>
#include <windef.h>
#include <iostream>
using namespace std;
//#pragma comment (lib,"pspai.lib")
/*变量声明*/
//use vector<int> num.size()标识进程数目。 别忘了num.clear();
//int i = 0;//item index
HANDLE Snapshot;
BOOL return_value;
//Describes an entry from a list of the processes residing 
//in the system address space when a snapshot was taken.
PROCESSENTRY32 processListStr;
//Contains the memory statistics for a process.
PROCESS_MEMORY_COUNTERS pmc;
int memory;
int psPid;
int cpuidle, cpuused;
int memusedprecent;
DWORDLONG memused, memunused;
void pslist(void)
{
	int i = 0;
	memory = processListStr.cntThreads;
	Snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	//获得某一时刻系统的进程、堆（heap）、模块（module）或线程的快照信息
	processListStr.dwSize = sizeof(PROCESSENTRY32);
	//Retrieves information about the first process encountered in a system snapshot.
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
			cout << "0\n";
		CloseHandle(temp);
		return_value = Process32Next(Snapshot, &processListStr);
		//获得系统进程链表中下一个进程的信息
		i++;
	}
	cout << "进程数目" << i << endl;
}

void printhead()/*打印头信息*/
{
	printf("    %-20s   %-8s   %s\t   %s\n", "进程名", "PID", "优先级","内存使用");
}
//获取cpu利用率。
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
//获取内存使用情况
void globalmem()
{
	//Contains information about the current state of both physical and virtual memory
	MEMORYSTATUSEX statux;
	statux.dwLength = sizeof(statux);
	GlobalMemoryStatusEx(&statux);
	memused = (statux.ullTotalPhys - statux.ullAvailPhys) / 1024 / 1024;
	memunused = statux.ullAvailPhys / 1024 / 1024;
	memusedprecent = statux.dwMemoryLoad;
}
//结束特定进程
void EndProcess()
{
	int Result;
	HANDLE ProcHandle, Handle;

	Handle = CreateToolhelp32Snapshot((DWORD)TH32CS_SNAPPROCESS, 0);
	processListStr.dwSize = sizeof(PROCESSENTRY32);
	Result = Process32First(Handle, &processListStr);

	while (Result)
	{

		if (processListStr.th32ProcessID == psPid) 
		{

			ProcHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processListStr.th32ProcessID);
			TerminateProcess(ProcHandle, 0);
			printf("成功结束掉指定进程！！\n");
			break;
		}

		Result = Process32Next(Handle, &processListStr);
	}
}
void Print()
{
	printhead();
	pslist();
	Cputimes();
	globalmem();
	cout<<"进程数目"<<num.size()<<endl;
	cout << "CPU状况" << cpuused << "%使用/" << cpuidle << "%空闲" << endl;
	cout << "内存情况" << memused << "MB使用/" << memunused << "MB空闲/"
		<< "内存使用率" << memusedprecent << "%" << endl;
}
void End()
{
	
	//cout << "进程数目" << i << endl;
	//Print();
	printf("请输入要结束进程的PID:");
	scanf_s("%d", &psPid);
	EndProcess();
	//Print();
	//printf("请输入要结束进程的PID:");
	
}
int main()
{
	int select = 0;
	cout << "****************************************\n";
	cout << "*1:显示进程等信息        2:结束进程     *\n";
	cout << "*3.结束。                              *\n";
	cout << "****************************************\n";
	cout << "Input integer:";
	while (cin >> select)
	{
		switch (select)
		{
		case 1:
			Print(); break;
		case 2:
			End(); break;
		case 3:
			exit(1);
		default:
			cout << "输入错误";
		}
		cout << "Input integer:";
	}
	return 0;
}