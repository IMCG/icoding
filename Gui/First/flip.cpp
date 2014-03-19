#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
//尽量少用cv.h  和 huighgui.h
int main()
{
	system("color 5F");

	Mat im = imread("E:\\pia1.jpg");
	if (!im.data){
		cout << "error";
	}
	/*cout << "Size: " << im.size().height << ","
		<< im.size().width << endl;*/
	Mat result;
	//反转图片
	flip(im, result, 1);

	namedWindow("Color");
	imshow("Color", im);

	namedWindow("Output Image");
	imshow("Output Image", result);

	waitKey(0);

	return 0;
}