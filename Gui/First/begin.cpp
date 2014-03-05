//开始图形界面
#include <iostream>  
#include <tchar.h>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  


using namespace cv;
using namespace std;
int main()
{
	// 读入一张图片（游戏原画）  
	Mat img = imread(("E:\\pic.jpg"));
	// 创建一个名为 "游戏原画"窗口  
	cvNamedWindow("游戏原画");
	// 在窗口中显示游戏原画  
	imshow("游戏原画", img);
	// 等待6000 ms后窗口自动关闭  
	waitKey(60000);
}
