//可以使用PSAPI的EnumProcesses函数和Tool help API的Processes32First和Process32Next
//函数完成进程列举的工作。
//EnumProcesses可以列举所有进程，但是没有Process32First和Process32Next获取的信息丰富
#include<iostream>
#include<Windows.h>
#include<TlHelp32.h>
#include<Psapi.h>
#pragma comment(lib,"psapi.lib")

using namespace std;

/**********************
*EnumProcesses遍历进程，
*调用ListProcessModules1函数和
*ListProcessThreads函数列举模块和线程
**********************/
VOID WINAPI EnumProcess1()
{
	//假设不超过1024个进程
	DWORD aProcesses[1024], cbNeeded, cProcesses;
	unsigned int i;
	//EnumProcesses
	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
		return;
	//进程数
	cProcesses = cbNeeded / sizeof(DWORD);
	for (i = 0; i < cProcesses; i++)
	{
		//display
		cout << "\nPROCESS: " << aProcesses[i];
	}
}
/**********************
*Process32First和Process32Next遍历进程
*ShowProcessMemoryInfo函数显示内存使用情况
***********************/
VOID WINAPI EnumProcess2()
{
	HANDLE hProcessSnap;
	HANDLE hProcess;
	PROCESSENTRY32 pe32;
	DWORD dwPriorityClass;
	
	//Snapshot
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		cout << "error\n";
		system("pause");
		exit(1);
	}
	//设置输入参数，结构的大小。
	pe32.dwSize = sizeof(pe32);

	//开始列举进程
	if (!Process32First(hProcessSnap, &pe32))
	{
		cout << "First_error";
		CloseHandle(hProcessSnap);
		return;
	}
	do
	{
		cout << "Process name:" << pe32.szExeFile << endl;
		//优先级
		dwPriorityClass = 0;
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);
		if (hProcess == NULL)
			cout << "open_error";
		else
		{
			dwPriorityClass = GetPriorityClass(hProcess);
			if (!dwPriorityClass)
				cout << "get_error";
			CloseHandle(hProcess);
		}
		//打印进程信息
		cout << "ID:" << pe32.th32ProcessID<<"\t";
		cout << "TC:" << pe32.cntThreads << "\t";
		cout << "PB:" << pe32.pcPriClassBase << "\t";
		if (dwPriorityClass)
			cout << "PC:" << dwPriorityClass << "\t";

		//获取模块信息，显示内存使用情况

	} while (Process32Next(hProcessSnap, &pe32));
	CloseHandle(hProcessSnap);
}
/***********************
*PrintMemoryInfo显示内存使用情况
*DWORD dwPID为进程PID
***********************/
VOID printMemoryInfo(DWORD dwPID)
{
	HANDLE hProcess;
	PROCESS_MEMORY_COUNTERS pmc;

}
int main()
{
	EnumProcess2();
	return 0;
}