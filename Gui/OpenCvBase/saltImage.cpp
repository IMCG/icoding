#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;
 // Vec3b一个三元素向量
void salt(Mat&image, int n)
{
	int i, j;
	for (int k = 0; k < n; k++){
		i = rand() % image.cols;
		j = rand() % image.rows;

		if (image.channels() == 1){//灰度图
			// 与彩色图的区别
			image.at<uchar>(j, i) = 255;
		}
		else if (image.channels() == 3){//彩色图
			image.at<Vec3b>(j, i)[0] = 255;
			image.at<Vec3b>(j, i)[1] = 255;
			image.at<Vec3b>(j, i)[2] = 255;
		}
	}
}
int main()
{
	system("color 5F");
	Mat image = imread("E:\\images\\boldt.jpg");
	if (!image.data)
		return 0;
	salt(image, 3000);

	namedWindow("Image");
	imshow("Image", image);

	waitKey(0);

	return 0;
}