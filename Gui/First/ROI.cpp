//ROI：从图像裁剪矩形区域
//图像的兴趣区
#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

//标记
bool down = false, up = false;
Mat img;
//Starting and ending points
Point corner1, corner2;
//ROI
Rect box;
static void mouse_callback(int event, int x, int y, int, void*)
{
	// When the left mouse button is pressed, record 
	//its position andsave it in corner1
	if (event == EVENT_LBUTTONDOWN)
	{
		down = true;
		corner1.x = x;
		corner1.y = y;
		cout << "Corner 1 recored at" << corner1 << endl;
	}
	// When the left mouse button is released, record 
	//its position and save it in corner2 
	if (event == EVENT_LBUTTONUP)
	{
		/*Also check if user selection is bigger than 20
		pixels (jut for fun!) */
		if (abs(x - corner1.x) > 20 && abs(y - corner1.y) > 20)
		{
			up = true;
			corner2.x = x;
			corner2.y = y;
			cout << "Corner 2 recorded at " << corner2 << endl;
		}
		else
		{
			cout << "Please select a bigger region" << endl;
			down = false;
		}
	}
	/*Update the box showing the selected region as the user drags
	the mouse*/
	if (down == true && up == false)
	{
		Point pt;
		pt.x = x;
		pt.y = y;
		Mat local_img = img.clone();
		rectangle(local_img, corner1, pt, Scalar(0, 0, 225));
		imshow("Cropping app", local_img);
	}
	// Define ROI and crop it out when both corners have been selected  
	if (down == true && up == true)
	{
		box.width = abs(corner1.x - corner2.x);
		box.height = abs(corner1.y - corner2.y);
		box.x = min(corner1.x, corner2.x);
		box.y = min(corner1.y, corner2.y);
		// Make an image out of just the selected ROI and display it in a new window  
		Mat crop(img, box);
		namedWindow("Crop");
		imshow("Crop", crop);
		down = false;
		up = false;
	}
}
int main()
{
	img = imread("E:\\pia1.jpg");
	namedWindow("Cropping app");
	imshow("Cropping app", img);
	// Set the mouse event callback function  
	setMouseCallback("Cropping app", mouse_callback);
	// Exit by pressing 'q'  
	while (char(waitKey(1)) != 'q') {}
	return 0;
}