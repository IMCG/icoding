/*findContours
 *drawContours
 */
#include <iostream>
#include <vector>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
using namespace cv;
using namespace std;

Mat src, src_gray;
int thresh = 100;
int max_thresh = 225;
RNG rng(12345);

void thresh_callback(int, void*);
int main()
{
	src = imread("E:\\images\\pia1.jpg");
	cvtColor(src, src_gray, CV_BGR2GRAY);
	blur(src_gray, src_gray, Size(3, 3));

	char*source_window = "Source";
	namedWindow(source_window);
	imshow(source_window, src);
	
	createTrackbar("Canny:", source_window, &thresh, max_thresh, thresh_callback);
	thresh_callback(0, 0);

	waitKey(0);
	return 0;
}
void thresh_callback(int, void*)
{
	Mat canny_output;
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;
	Canny(src_gray, canny_output, thresh, thresh * 2);
	findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CHAIN_APPROX_SIMPLE, Point());

	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		//drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
		drawContours(drawing, contours, i, color, 1, 8, hierarchy, 1);
	}
	namedWindow("Contours");
	imshow("Contours", drawing);
}

