#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<Windows.h>
#include<Psapi.h>
#include<iomanip>
//#include<windef.h>
#include<TlHelp32.h>
//#pragma comment(lib,"psapi.lib")
using namespace std;

#define DIV 1024;
struct process{
	wstring name;
	int id;
	SIZE_T memuse;
	SIZE_T vmemuse;
	LONG PriClass;
};
bool operator<(const process&p1, const process&p2)
{
	return p1.name < p2.name;
}
wostream&operator<<(wostream&os, const process&p)
{
	os << setiosflags(ios::left) << setw(20) << p.name << "\t" << p.id << "\t" 
		<< p.memuse << "\t" << p.vmemuse << "\t\t" << p.PriClass << endl;
	return os;
}
bool showsys = false;
int pid;
vector<process> plist;
int cpuidle, cpuused;
int memusedprecent;
DWORDLONG memused, memunused;
void Snapshot();
void Print();
void Endprocess();
void Globalmem();
void Cputimes();
int main()
{
	//Cputimes();
	Snapshot();
	//globalmem();
	Print();
	int select = 0;
	cout << "Please input integer: ";
	while (cin >> select)
	{
		switch (select)
		{
		case 1:
			Snapshot(); Print(); break;
		case 2:
			cout << "Input PID: ";
			cin >> pid;
			Endprocess(); Snapshot(); Print(); break;
		case 3:
			showsys = !showsys; Snapshot(); Print(); break;
		default:
			cout << "ERROR!\n" << endl;
		}
		cout << "Please input integer: ";
	}

	return 0;
}
void Print()
{
	cout << "进程名\t\t\t进程ID\t内存\t虚拟内存\t优先级" << endl;
	for (auto s : plist){
		wcout << s;
	}
	cout << "进程数目:" << plist.size() << endl;
	cout << "CPU使用情况：" << cpuused << "%使用/" << cpuidle << "%空闲" << endl;
	cout << "内存使用情况：" << memused << "MB使用/" << memunused << "MB空闲/"
		<< "内存使用率" << memusedprecent << "%" << endl;
	cout << "1.更新\n2.结束进程\n3.显示/关闭系统进程\n" << endl;
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
void Globalmem()
{
	MEMORYSTATUSEX statux;
	statux.dwLength = sizeof(statux);
	GlobalMemoryStatusEx(&statux);
	memused = (statux.ullTotalPhys - statux.ullAvailPhys) / 1024 / 1024;
	memunused = statux.ullAvailPhys / 1024 / 1024;
	memusedprecent = statux.dwMemoryLoad;
}
void Snapshot()
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

		process TempProcess;
		while (bFirstProcess)
		{
			TempProcess.name = (wstring)pe32.szExeFile;
			TempProcess.id = pe32.th32ProcessID;
			TempProcess.PriClass = pe32.pcPriClassBase;

			HANDLE temp = OpenProcess(PROCESS_QUERY_INFORMATION, TRUE,
				TempProcess.id);
			if (GetProcessMemoryInfo(temp, &pmc, sizeof(pmc)))
			{
				TempProcess.memuse = pmc.WorkingSetSize / 1024;
				TempProcess.vmemuse = pmc.WorkingSetSize / 1024;
				plist.push_back(TempProcess);
			}
			else
			{
				TempProcess.memuse = 0;
				TempProcess.vmemuse = 0;
				if (showsys)
					plist.push_back(TempProcess);
			}
			CloseHandle(temp);
			bFirstProcess = Process32Next(hProcessSnap, &pe32);
		}
		sort(plist.begin(), plist.end());
		CloseHandle(hProcessSnap);
	}
	Cputimes();
	Globalmem();
}
void Endprocess()
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
	cout << "Do not specify a process!" << endl;
	system("pause");
	return;
}
//you can string->wstring.or  CW2A(pe32.szExeFile);