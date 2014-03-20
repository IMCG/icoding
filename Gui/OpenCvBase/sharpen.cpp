#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <cmath>
using namespace std;
using namespace cv;
 
void sharpen(const Mat&image, Mat&result)
{
	//分配图像
	result.create(image.rows, image.cols, image.type());
	//处理除了第一行和最后一行
	for (int i = 1; i < image.rows - 1; i++){
		const uchar* previous =
			image.ptr<const uchar>(i - 1);
		const uchar* current =
			image.ptr<const uchar>(i);
		const uchar* next =
			image.ptr<const uchar>(i - 1);
		//output
		uchar*output = result.ptr<uchar>(i);
		for (int j = 1; j < image.cols - 1; j++){
			//saturate对结果进行截断
			*output++ = cv::saturate_cast<uchar>(
				5 * current[j] - current[j-1]
				- current[j + 1] - previous[j] - next[j]
				);
		}
	}
	//未处理的像素设置为0
	result.row(0).setTo(Scalar(0));
	result.row(result.rows - 1).setTo(Scalar(0));
	result.col(0).setTo(Scalar(0));

	result.col(result.cols - 1).setTo(Scalar(0));

}
//使用了一个核矩阵。
void sharpen2D(const cv::Mat &image, cv::Mat &result) {

	// Construct kernel (all entries initialized to 0)
	cv::Mat kernel(3, 3, CV_32F, cv::Scalar(0));
	// assigns kernel values
	kernel.at<float>(1, 1) = 5.0;
	kernel.at<float>(0, 1) = -1.0;
	kernel.at<float>(2, 1) = -1.0;
	kernel.at<float>(1, 0) = -1.0;
	kernel.at<float>(1, 2) = -1.0;

	//filter the image
	filter2D(image, result, image.depth(), kernel);
}

int main()
{
	system("color 5F");
	//设定为灰度图
	Mat im = imread("E:\\images\\boldt.jpg", 0);
	Mat result;
	sharpen(im, result);
	namedWindow("Result");
	imshow("Result", result);

	waitKey(0);
	return 0;
}