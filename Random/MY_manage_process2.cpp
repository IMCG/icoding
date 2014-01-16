#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<Windows.h>
#include<Psapi.h>
#include<windef.h>
#include<TlHelp32.h>
#pragma comment(lib,"psapi.lib")
using namespace std;

#define DIV 1024;
struct process{
	WCHAR name;
	int id;
	SIZE_T memuse;
	LONG PriClass;
};
bool operator<(const process&p1, const process&p2)
{
	return p1.name < p2.name;
}
ostream&operator<<(ostream&os, const process&p)
{
	os << p.name << "\t" << p.id << "\t" << p.memuse<<"\t"<<p.PriClass <<  endl;
	return os;
}
bool showsys = false;
int pid;
vector<process> plist;
int cpuidle, cpuused;
int memusedprecent;
DWORDLONG memused, memunused;
void snap();
void display();
void endprocess();
void globalmem();
void Cputimes();
int main()
{
	//Cputimes();
	snap();
	//globalmem();
	display();
	int select = 0;
	while (cin >> select)
	{
		switch (select)
		{
		case 1:
			snap(); display(); break;
		case 2:
			cout << "Input PID:";
			cin >> pid;
			endprocess(); snap(); display(); break;
		case 3:
			showsys = !showsys; snap(); display(); break;
		default:
			cout << "ERROR!" << endl;
		}
	}

	return 0;
}
void display()
{
	cout << "进程名\t进程ID\t内存使用" << endl;
	for (auto s : plist){
		cout << s;
	}
	cout << "进程数目" << plist.size() << endl;
	cout << "CPU状况" << cpuused << "%使用/" << cpuidle << "%空闲" << endl;
	cout << "内存情况" << memused << "MB使用/" << memunused << "MB空闲/"
		<< "内存使用率" << memusedprecent << "%" << endl;
	cout << "1.更新，2.结束进程，3.显示/关闭系统进程" << endl;
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
void snap()
{
	plist.clear();
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE){
		//创建快照失败
		return;
	}
	else
	{
		//Describes an entry from a list of the processes residing in the system
		//address space when a snapshot was taken.
		PROCESSENTRY32 pe32;
		//Contains the memory statistics for a process.
		PROCESS_MEMORY_COUNTERS pmc;

		//Before calling the Process32First function,
		pe32.dwSize = sizeof(PROCESSENTRY32);
		//Retrieves information about the first process encountered in a system snapshot.
		BOOL bFirstProcess = Process32First(hProcessSnap, &pe32);

		process tempprocess;
		while (bFirstProcess)
		{
			tempprocess.name = (WCHAR)pe32.szExeFile;
			tempprocess.id = pe32.th32ProcessID;
			tempprocess.PriClass = pe32.pcPriClassBase;
			
			HANDLE temp = OpenProcess(PROCESS_QUERY_INFORMATION, TRUE,
				tempprocess.id);
			if (GetProcessMemoryInfo(temp, &pmc, sizeof(pmc)))
			{
				tempprocess.memuse = pmc.WorkingSetSize / 1024;
				plist.push_back(tempprocess);
			}
			else
			{
				tempprocess.memuse = 0;
				if (showsys)
					plist.push_back(tempprocess);
			}
			CloseHandle(temp);
			bFirstProcess = Process32Next(hProcessSnap, &pe32);
		}
		//sort(plist.begin(), plist.end());
		CloseHandle(hProcessSnap);
	}
	Cputimes();
	globalmem();
}
void endprocess()
{
	for (auto p : plist)
	{
		if (p.id == pid)
		{
			HANDLE h = OpenProcess(PROCESS_TERMINATE, TRUE, pid);
			if (h)
				TerminateProcess(h, 0);
			return;
		}
	}
	cout << "没有指定的进程" << endl;
	system("pause");
	return;
}
//you can string->wstring.or  CW2A(pe32.szExeFile);