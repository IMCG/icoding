#include "stdafx.h"
#include <iostream>
#include "windows.h"
#include <string.h>
#include <Strsafe.h>
using namespace std;

//传入要遍历的文件夹路径，并遍历相应文件夹
void TraverseDirectory(wchar_t Dir[MAX_PATH])    
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind=INVALID_HANDLE_VALUE;
	wchar_t DirSpec[MAX_PATH];                  //定义要遍历的文件夹的目录
	DWORD dwError;
	StringCchCopy(DirSpec,MAX_PATH,Dir);
        StringCchCat(DirSpec,MAX_PATH,TEXT("\\*"));   //定义要遍历的文件夹的完整路径\*

	hFind=FindFirstFile(DirSpec,&FindFileData);          //找到文件夹中的第一个文件

	if(hFind==INVALID_HANDLE_VALUE)                               //如果hFind句柄创建失败，输出错误信息
	{
		FindClose(hFind); 
		return;  
	}
	else 
	{
		while(FindNextFile(hFind,&FindFileData)!=0)                            //当文件或者文件夹存在时
		{
			if((FindFileData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)!=0&&wcscmp(FindFileData.cFileName,L".")==0||wcscmp(FindFileData.cFileName,L"..")==0)        //判断是文件夹&&表示为"."||表示为"."
			{
				 continue;
			}
			if((FindFileData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)!=0)      //判断如果是文件夹
			{
				wchar_t DirAdd[MAX_PATH];
				StringCchCopy(DirAdd,MAX_PATH,Dir);
				StringCchCat(DirAdd,MAX_PATH,TEXT("\\"));
				StringCchCat(DirAdd,MAX_PATH,FindFileData.cFileName);       //拼接得到此文件夹的完整路径
				TraverseDirectory(DirAdd);                                  //实现递归调用
			}
			if((FindFileData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)==0)    //如果不是文件夹
			{
				wcout<<Dir<<"\\"<<FindFileData.cFileName<<endl;            //输出完整路径
			}
		}
		FindClose(hFind);
	}
}

int _tmain( int argc, wchar_t *argv[ ], wchar_t *envp[ ] )
{
	locale loc( "chs" );                //支持中文输出，否则wchar可能无法输出值为中文的变量
	wcout.imbue( loc );
	

	TraverseDirectory(L"C:\\Users\\v_tianboli\\Desktop\\windows程式设计开发指南");         //遍历指定的文件夹，此处文件路径可按具体情况修改
	system("pause");
	return 0;
}
