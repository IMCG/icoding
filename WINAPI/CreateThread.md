CreadThread
=================
		#include <iostream>
		#include<Windows.h>
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


CreateThread
-----------------
		HANDLEWINAPICreateThread(

		  LPSECURITY_ATTRIBUTESlpThreadAttributes,

		  SIZE_TdwStackSize,

		  LPTHREAD_START_ROUTINElpStartAddress,

		  LPVOIDlpParameter,

		  DWORDdwCreationFlags,

		  LPDWORDlpThreadId

		);

###函数说明：

		第一个参数表示线程内核对象的安全属性，一般传入NULL表示使用默认设置。

		第二个参数表示线程栈空间大小。传入0表示使用默认大小（1MB）。

		第三个参数表示新线程所执行的线程函数地址，多个线程可以使用同一个函数地址。

		第四个参数是传给线程函数的参数。

		第五个参数指定额外的标志来控制线程的创建，为0表示线程创建之后立即就可以进行调度，如果为CREATE_SUSPENDED则表示线程创建后暂停运行，这样它就无法调度，直到调用ResumeThread()。

		第六个参数将返回线程的ID号，传入NULL表示不需要返回该线程ID号。

		函数返回值：

		成功返回新线程的句柄，失败返回NULL。 
WaitForSingleObject
-------------------------
###等待函数-使线程进入等待状态，直到指定的内核对象被触发。
		DWORDWINAPIWaitForSingleObject(

		  HANDLEhHandle,

		  DWORDdwMilliseconds

		);

		函数说明：

		第一个参数为要等待的内核对象。

		第二个参数为最长等待的时间，以毫秒为单位，如传入5000就表示5秒，传入0就立即返回，传入INFINITE表示无限等待。

		因为线程的句柄在线程运行时是未触发的，线程结束运行，句柄处于触发状态。所以可以用WaitForSingleObject()来等待一个线程结束运行。


_beginthreadex
================
###_beginthreadex()函数在创建新线程时会分配并初始化一个_tiddata块。这个_tiddata块自然是用来
###存放一些需要线程独享的数据。事实上新线程运行时会首先将_tiddata块与自己进一步关联起来。然后
###新线程调用标准C运行库函数如strtok()时就会先取得_tiddata块的地址再将需要保护的数据存入_tiddata块中。
###这样每个线程就只会访问和修改自己的数据而不会去篡改其它线程的数据了。因此，如果在代码中有
###使用标准C运行库中的函数时，尽量使用_beginthreadex()来代替CreateThread()。
		#include<iostream>
		#include<Windows.h>
		#include<process.h>
		using namespace std;
		//子线程函数
		unsigned int __stdcall ThreadFun(PVOID pM)
		{
			printf("PID为%d的子线程说:hello world\n", GetCurrentThreadId());
			return 0;
		}
		int main()
		{
			const int THREAD_NUM = 5;
			HANDLE handle[THREAD_NUM];
			for (int i = 0; i < THREAD_NUM; i++)
			{
				handle[i] = (HANDLE)_beginthreadex(NULL, 0, ThreadFun, NULL, 0, NULL);
			}
			WaitForMultipleObjects(THREAD_NUM, handle, TRUE, INFINITE);
		}
