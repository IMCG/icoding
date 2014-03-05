//Mat1
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
int main()
{
	Mat A, C;	//只创建信息头部分
	A = imread("E:\\pic.jpg", CV_LOAD_IMAGE_COLOR);
	Mat B(A);	//拷贝构造函数，只拷贝信息头和矩阵指针
	C = A;		//赋值运算符
	//using rectangle 感兴趣区域
	Mat D(A, Rect(10, 10, 100, 100));
	// using row and column boundaries
	Mat E = A(Range::all(), Range(1, 3));
	/*矩阵属于多个Mat对象，使用了引用计数机制。*/

	//拷贝矩阵本身 clone()  copyTo()
	Mat F = A.clone();
	Mat G;
	A.copyTo(G);
	/*现在改变F或者G就不会影响Mat信息头所指向的矩阵*/

	//Mat 不但是图像容器类，也是通用的矩阵类可用来创建和操作多维矩阵
	//分别是行列，存储元素的数据类型，以及矩阵通道数
	Mat M(2, 2, CV_8UC3, Scalar(0, 0, 225));
	cout << "M = " << endl << " " << M << endl;
	//C++ 方法
	int sz[3] = { 2, 2, 2 };
	Mat L(3, sz, CV_8UC(1), Scalar::all(0));


	return 0;
}