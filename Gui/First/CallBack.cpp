#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;
const int slider_max = 1;
int slider;
Mat img;
//回掉函数
void on_trackbar(int pos, void *)
{
	Mat img_converted;
	if (pos > 0)cvtColor(img, img_converted,CV_RGB2GRAY);
	else img_converted = img;
	imshow("Trackbar app", img_converted);
}
int main()
{
	img = imread(("E:\\pic.jpg"));
	namedWindow("Trackbar app");
	imshow("Trackbar app", img);
	slider = 0;
	createTrackbar("RGB <-> Grayscale", "Trackbar app", 
		&slider, slider_max, on_trackbar);
	cout << "Press 'q' to quit..." << endl;
	while (char(waitKey(1)) != 'q'){}
	return 0;
}