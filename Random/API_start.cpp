#include<Windows.h>
/*链接时使用User32.lib*/
#pragma comment (lib,"User32.lib")
using namespace std;
int WinMain(
	HINSTANCE hInstance,
	HINSTANCE	hPrevInstance,
	LPSTR lpCmdline,
	int nCmdshow
	)
{
	//api MessageBox
	MessageBox(NULL,
		TEXT("开始学习windows编程"),
		TEXT("消息对话框"),
		MB_OK);
	return 0;
}