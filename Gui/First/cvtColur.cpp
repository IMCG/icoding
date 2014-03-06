//图像转换为灰度
#include <cv.h>
#include <highgui.h>
using namespace cv;
int main()
{
	//创建Mat 并且读取文件按BGR格式
	Mat im = imread("E:\\pia.jpg", CV_LOAD_IMAGE_COLOR);
	Mat gray_image;
	//将RGB图像转化为灰度格式-->GRAY
	cvtColor(im, gray_image, CV_BGR2GRAY);
	imwrite("E:\\first.jpg", gray_image);

	cvNamedWindow("Source", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Gray image", CV_WINDOW_NORMAL);

	imshow("Source", im);
	imshow("Gray image", gray_image);
	//等待用户的按键操作来关闭窗口
	waitKey(0);
	return 0;
}
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

const int slider_max = 1;
int slider;
Mat img;
void on_trackbar(int pos, void *){
	Mat img_converted;
	if (pos > 0)
		cvtColor(img, img_converted, CV_RGB2GRAY);
	else
		img_converted = img;
	imshow("Trackbar app", img_converted);
}
int main()
{
	img = imread("E:\\pia1.jpg");
	namedWindow("Trackbar app");
	imshow("Trackbar app", img);
	slider = 0;
	createTrackbar("RGB <-> Grayscale", "Trackbar app",
		&slider, slider_max, on_trackbar);
	while (char(waitKey(0)) != 'q'){}
	return 0;
}
