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