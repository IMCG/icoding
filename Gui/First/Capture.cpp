#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main()
{
	// 0是笔记本内置摄像头的ID,想使用其他摄像头可以改变该值
	VideoCapture cap(0);
	//检查是否正确打开
	if (!cap.isOpened()){
		cout << "Capture could't be opened!";
		return -1;
	}
	namedWindow("Video");
	//循环播放到停止
	while (char(waitKey(0)) != 'q' && cap.isOpened()){
		Mat frame;
		cap >> frame;//注：这里重载操作符 读取截图  
        //检查视频是否结束
		if (frame.empty()){
			cout << "Video over" << endl;
			break;
		}
		imshow("Video", frame);
	}
	return 0;
}