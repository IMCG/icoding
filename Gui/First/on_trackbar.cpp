#include <iostream>
#include <vector>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
using namespace cv;
using namespace std;

Mat img;
int threshval = 70;//轨迹条滑块对应的值

void on_trackbar(int, void*){
	Mat bw = threshval < 128 ? (img<threshval) : (img>threshval);

	//定义点和向量
	vector<vector<Point>>contours;
	vector<Vec4i> hierachy;

	//查找轮廓
	findContours(bw, contours, hierachy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
	//Init
	Mat dst = Mat::zeros(img.size(), CV_8UC3);
	//begin done
	if (!contours.empty() && !hierachy.empty()){
		//遍历所有顶层轮廓，随机生成颜色值绘制给各连接组曾部分
		int idx = 0;
		for (; idx >= 0; idx = hierachy[idx][0]){
			Scalar color(rand() & 255, rand() % 255, rand() & 255);
			//绘制填充轮廓
			drawContours(dst, contours, idx, color, CV_FILLED, 8, hierachy);
		}
	}
	imshow("Connected Components", dst);
}

int main()
{
	system("color 5F");
	img = imread("E:\\images\\pic.jpg", 0);
	if (!img.data)
		return 0;
	namedWindow("Image");
	imshow("Image", img);

	namedWindow("Connected Components");
	createTrackbar("Threshold", "Connected Components", &threshval, 255, on_trackbar);
	on_trackbar(threshval, 0);//轨迹条回调函数

	waitKey(0);
	return 0;
}
