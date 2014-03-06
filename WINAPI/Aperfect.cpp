#include <Windows.h>
using namespace std;
//窗口消息处理程序
LRESULT CALLBACK WndRroc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR szCmdLine,
	int iCmdShow
	)
{
	static TCHAR szAppName[] = TEXT("HelloWIn8");
	HWND hwnd;  //窗口句柄
	MSG  msg;   //消息结构
	//窗口类别
	WNDCLASS wndclass;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;//水平竖直方向上的redraw
	wndclass.lpfnWndProc = WndRroc;//消息处理程序设定为WndRroc
	wndclass.cbClsExtra = 0; //预留空间
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance; //执行实体句柄（WinMain参数之一）
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//加载图标
	wndclass.hCursor = LoadCursor(NULL,IDC_ARROW);//加载鼠标光标
	//hbr画刷句柄，stack(备用)，传回一个白色画刷
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//取得一个图形对象
	//窗口类别菜单
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName; //类别名字，存放在szAppName变量中

	//在为程序创建窗口之前，必须呼叫RegisterClass注册一个窗口类
	if (!RegisterClass(&wndclass)) //为程序窗口注册窗口类别
	{
		MessageBox(NULL, TEXT("This program requires windows"),//显示消息框
			szAppName, MB_ICONERROR);
		return 0;
	}
	/*窗口类别 & 建立窗口*/
	//根据窗口类别建立一个窗口 & 信息存放在hwnd中
	hwnd = CreateWindow(szAppName,//window class name
		TEXT("The Hello Pragram"),//window caption & 窗口名字
		WS_OVERLAPPEDWINDOW,//window style & 标准样式的窗口
		CW_USEDEFAULT,//initial x pos
		CW_USEDEFAULT,//initial y pos
		CW_USEDEFAULT,//initial x size
		CW_USEDEFAULT,//initial y size
		NULL,		  //parent window handle	
		NULL,		  //window menu handle & 没有菜单
		hInstance,	  //program instance handle	
		NULL);		  //creation parameters
	
	ShowWindow(hwnd, iCmdShow);//显示窗口
	UpdateWindow(hwnd);//指示窗口自我更新
	//消息循环程序
	while (GetMessage(&msg, NULL, 0, 0))//从消息队列中取得消息。
	{
		TranslateMessage(&msg);//转译某些键盘消息
		DispatchMessage(&msg);//将消息发送给窗口消息处理程序
	}
	return msg.wParam;
}
//窗口消息处理程序
LRESULT CALLBACK WndRroc(HWND hwnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc;//设备内容句柄
	PAINTSTRUCT ps;//绘图结构
	RECT rect;//矩形结构
	//message 决定消息处理。。只接受一下3种信息
	switch (message)
	{
	case WM_CREATE:
		PlaySound(TEXT("E:\\hello.mp3"), NULL, SND_FILENAME | SND_ASYNC);//播放一个声音
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);//开始绘制窗口
		GetClientRect(hwnd, &rect);//显示窗口显示区域的大小
		DrawText(hdc, TEXT("Hello,windows"), -1, &rect, //显示字符串
			DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps); //结束绘制窗口
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);//在消息队列中插入一个quit
		return 0;
	}
	//呼叫DefWindowProc来为窗口消息处理程序不予处理的所有消息提供内定处理
	return DefWindowProc(hwnd, message, wParam, lParam);//执行内定的消息处理
}
/*大写字母标识符前缀：
  CS 	窗口类别样式，
  CW 	建立窗口
  DT    绘制文字
  IDI   图示ID
  IDC   游标ID
  MB    消息框
  SND   声音
  WM    窗口消息 
  WS    窗口样式

  数据类型：
  MSG            消息结构
  WNDCLASS       窗口类别
  PAINTSTRUCT    绘图结构
  RECT           矩形结构

  句柄简介：句柄是一个（通常为32位）整数。
  HINSTANCE      执行实体
  HWND           窗口句柄
  HDC            设备内容句柄

  匈牙利前缀：
  w  	WORD
  l     LONG
  dw    DWORD
  fn    function
  s     string
  sz    以0结尾的字符串
  h     句柄
  p     指标
*/

