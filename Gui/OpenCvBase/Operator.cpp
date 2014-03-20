#include <vector>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
using namespace std;
using namespace cv;

int main()
{
	system("color 5F");
	Mat image1;
	Mat image2;
	image1 = imread("E:\\images\\boldt.jpg");
	image2 = imread("E:\\images\\rain.jpg");
	if (!image1.data || !image2.data)
		return 0;
	namedWindow("Image 1");
	imshow("Image 1", image1);
	namedWindow("Image 2");
	imshow("Image 2", image2);

	Mat result;
	addWeighted(image1, 0.7, image2, 0.9, 0.0, result);
	namedWindow("Result");
	imshow("Result", result);

	result = 0.7*image1 + 0.9*image2;
	namedWindow("result with op");
	imshow("result with op", result);

	waitKey(0);
	return 0;
}