#include<stdio.h>
#include<windows.h>
#include<tlhelp32.h>
int main(int argc,char*argv[]){
 /*int nSelect=::MessageBox(NULL,TEXT("Hello,Windows XP"),TEXT("Greetings"),MB_OKCANCEL);
 if(nSelect==IDOK)
  printf("用户选择了“确定”按钮\n");
 else
  printf("用户选择了“取消”按钮\n");
 STARTUPINFO si={sizeof(si)};
 PROCESS_INFORMATION pi;
 si.dwFlags=STARTF_USESHOWWINDOW|STARTF_USEPOSITION;
 si.wShowWindow=true;
 wchar_t szCommandLine[]=L"cmd";
 BOOL bRet=::CreateProcess(NULL,szCommandLine,NULL,NULL,FALSE,CREATE_NEW_CONSOLE,NULL,NULL,&si,&pi);
 if(bRet){
  ::CloseHandle(pi.hThread);
  ::CloseHandle(pi.hProcess);
  printf("新进程ID号：%d\n",pi.dwProcessId);
  printf("新线程的ID号：%d\n",pi.dwThreadId);
 }*/
 PROCESSENTRY32 pe32;
 pe32.dwSize=sizeof(pe32);
 HANDLE hProcessSnap=::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
 if(hProcessSnap==INVALID_HANDLE_VALUE){
  printf("CreateToolhelp32Snapshot调用失败!\n");
  return -1;
 }
 BOOL bMore=::Process32First(hProcessSnap,&pe32);
 while(bMore){
  printf("进程名称：%s\n",pe32.szExeFile);
  printf("进程ID号：%u\n\n",pe32.th32ProcessID);
  bMore=::Process32Next(hProcessSnap,&pe32);
 }
 ::CloseHandle(hProcessSnap);
 return 0;
}