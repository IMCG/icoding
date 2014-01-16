/*PSAPI*/
EnumProcess  取得系统中所有ID;
OpenProcess  取得Handle
EnumProcessModules 取得可执行程序HModule句柄
GetModuleBaseName  获得Process名字
CloseHandle  关闭句柄

每一个进程都有一个PID和一个句柄
进程状态信息（PSAPI)(Tool help API)

/*以下计算cpu利用率*/
BOOL WINAPI GetSystemTimes(
  _Out_opt_  LPFILETIME lpIdleTime,				//idle
  _Out_opt_  LPFILETIME lpKernelTime,			//core
  _Out_opt_  LPFILETIME lpUserTime				//user
);
//FILETIME structure（windef.h）
typedef struct _FILETIME {
  DWORD dwLowDateTime;			//低32位
  DWORD dwHighDateTime;			//高32位
} FILETIME, *PFILETIME;

//Get CPU Usage with GetSystemTimes
FILETIME idleTime;
FILETIME kernelTime;
FILETIME userTime;
BOOL res = GetSystemTimes( &idleTime, &kernelTime, &userTime );
//Now you have to poll this function and make a little calculus.
usr = userTime - last_userTime;
ker = kernelTime - last_kernelTime;
idl = idleTime - last_idleTime;
//system time is
sys = kerl + usr
//idleTime is the rest because "System Idle" process is taking 100 % of CPU.

So CPU is :
cpu = int( (sys - idl) *100 / sys );

//GlobalMemoryStatusEx function
BOOL WINAPI GlobalMemoryStatusEx(
  _Inout_  LPMEMORYSTATUSEX lpBuffer
  //A pointer to a MEMORYSTATUSEX structure that 
  //receives information about current memory availability
);
Examples
内存使用情况。。
The following code shows a simple use of the GlobalMemoryStatusEx function.
//  Sample output:
//  There is       51 percent of memory in use.
//  There are 2029968 total KB of physical memory.
//  There are  987388 free  KB of physical memory.
//  There are 3884620 total KB of paging file.
//  There are 2799776 free  KB of paging file.
//  There are 2097024 total KB of virtual memory.
//  There are 2084876 free  KB of virtual memory.
//  There are       0 free  KB of extended memory.

#include <windows.h>
#include <stdio.h>
#include <tchar.h>

// Use to convert bytes to KB
#define DIV 1024

// Specify the width of the field in which to print the numbers. 
// The asterisk in the format specifier "%*I64d" takes an integer 
// argument and uses it to pad and right justify the number.
#define WIDTH 7

void _tmain()
{
  MEMORYSTATUSEX statex;

  statex.dwLength = sizeof (statex);

  GlobalMemoryStatusEx (&statex);

  _tprintf (TEXT("There is  %*ld percent of memory in use.\n"),
            WIDTH, statex.dwMemoryLoad);
  _tprintf (TEXT("There are %*I64d total KB of physical memory.\n"),
            WIDTH, statex.ullTotalPhys/DIV);
  _tprintf (TEXT("There are %*I64d free  KB of physical memory.\n"),
            WIDTH, statex.ullAvailPhys/DIV);
  _tprintf (TEXT("There are %*I64d total KB of paging file.\n"),
            WIDTH, statex.ullTotalPageFile/DIV);
  _tprintf (TEXT("There are %*I64d free  KB of paging file.\n"),
            WIDTH, statex.ullAvailPageFile/DIV);
  _tprintf (TEXT("There are %*I64d total KB of virtual memory.\n"),
            WIDTH, statex.ullTotalVirtual/DIV);
  _tprintf (TEXT("There are %*I64d free  KB of virtual memory.\n"),
            WIDTH, statex.ullAvailVirtual/DIV);

  // Show the amount of extended memory available.

  _tprintf (TEXT("There are %*I64d free  KB of extended memory.\n"),
            WIDTH, statex.ullAvailExtendedVirtual/DIV);
}

//TerminateProcess function
BOOL WINAPI TerminateProcess(
  _In_  HANDLE hProcess,
  /*hProcess [in]
  A handle to the process to be terminated.
  The handle must have the PROCESS_TERMINATE access right.
  For more information, see Process Security and Access Rights.
  */
  _In_  UINT uExitCode
);

//OpenProcess function---------->Opens an existing local process object.
HANDLE WINAPI OpenProcess(
  _In_  DWORD dwDesiredAccess,
  _In_  BOOL bInheritHandle,
  _In_  DWORD dwProcessId
);

//GetProcessMemoryInfo function------------------->memory usage of the specified process.
BOOL WINAPI GetProcessMemoryInfo(
  _In_   HANDLE Process,
  _Out_  PPROCESS_MEMORY_COUNTERS ppsmemCounters,
  _In_   DWORD cb
);