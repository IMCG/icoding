//线性混合(linear blending) & addWeighted
#include <cv.h>
#include <highgui.h>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	double alpha = 0.5, beta, input;
	Mat src1, src2, dst;
	cout << "Enter alpha (0-1): ";
	cin >> input;
	if (alpha >= 0 && alpha <= 1)
		alpha = input;
	//Read image
	src1 = imread("E:\\pia1.jpg");
	src2 = imread("E:\\pib1.jpg");

	//namedWindow("Linear Blend",1); 
	cvNamedWindow("Linear Blend", CV_WINDOW_NORMAL);
	beta = (1.0 - alpha);
	/*dst = a*src1 + b*src2 + r
	 *两个图片必须相同高度，宽度
	 */
	addWeighted(src1, alpha, src2, beta, 0.0, dst);

	imshow("Linear Blend", dst);

	waitKey(0);
	return 0;
}