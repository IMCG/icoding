#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <iostream>
#include <cmath>
using namespace std;
using namespace cv;
 
void colorReduce(Mat&image, int div = 64)
{
	int nl = image.rows;//行数
	//每行元素个数，因为channels不同
	int nc = image.cols*image.channels();
	for (int j = 0; j < nl; j++){
		//得到第j行的首地址
		uchar*data = image.ptr<uchar>(j);
		for (int i = 0; i < nc; i++){
			*data++ = *data / div*div + div / 2;
		}
	}
}

void colorReduce1(Mat&image, int div = 64)
{
	int nl = image.rows;
	int nc = image.cols*image.channels();

	int n = static_cast<int>(log(static_cast<double>(div)) / log(2.0));
	uchar mask = 0xFF << n;

	for (int j = 0; j<nl; j++) {
		uchar* data = image.ptr<uchar>(j);
		for (int i = 0; i<nc; i++) {
			*data++ = *data&mask + div / 2;
		}                
	}
}

//分像素 遍历using .ptr and * ++ and bitwise (continuous+channels)
//效率最高。
void colorReduce7(cv::Mat &image, int div=64) {

	  int nl= image.rows; // number of lines
	  int nc= image.cols ; // number of columns

	  if (image.isContinuous())  {
		  // then no padded pixels
		  nc= nc*nl; 
		  nl= 1;  // it is now a 1D array
	   }

	  int n= static_cast<int>(log(static_cast<double>(div))/log(2.0));
	  // mask used to round the pixel value
	  uchar mask= 0xFF<<n; // e.g. for div=16, mask= 0xF0
              
      for (int j=0; j<nl; j++) {

		  uchar* data= image.ptr<uchar>(j);

          for (int i=0; i<nc; i++) {
 
            // process each pixel ---------------------
                 
            *data++= *data&mask + div/2;
            *data++= *data&mask + div/2;
            *data++= *data&mask + div/2;
 
            // end of pixel processing ----------------
 
            } // end of line                   
      }
}


//使用迭代器
void colorReduce8(cv::Mat &image, int div=64) {

	  // get iterators
	  //Mat_<Vec3b> cimage=image;   这样可以不用写后面的Vec3b;
	  cv::Mat_<cv::Vec3b>::iterator it= image.begin<cv::Vec3b>();
	  cv::Mat_<cv::Vec3b>::iterator itend= image.end<cv::Vec3b>();

	  for ( ; it!= itend; ++it) {
        
		// process each pixel ---------------------

        (*it)[0]= (*it)[0]/div*div + div/2;
        (*it)[1]= (*it)[1]/div*div + div/2;
        (*it)[2]= (*it)[2]/div*div + div/2;

        // end of pixel processing ----------------
	  }
}
//直接调用
void colorReduce11(cv::Mat &image, int div=64) {

	  int nl= image.rows; // number of lines
	  int nc= image.cols; // number of columns
              
      for (int j=0; j<nl; j++) {
          for (int i=0; i<nc; i++) {
 
            // process each pixel ---------------------
                 
                  image.at<cv::Vec3b>(j,i)[0]=	 
                  image.at<cv::Vec3b>(j,i)[0]/div*div + div/2;
                  image.at<cv::Vec3b>(j,i)[1]=	 
                  image.at<cv::Vec3b>(j,i)[1]/div*div + div/2;
                  image.at<cv::Vec3b>(j,i)[2]=	 
                  image.at<cv::Vec3b>(j,i)[2]/div*div + div/2;
 
            // end of pixel processing ----------------
 
            } // end of line                   
      }
}
int main()
{
	system("color 5F");
	Mat image = imread("E:\\images\\boldt.jpg");
	if (!image.data)
		return 0;
	//clone
	Mat imageClone = image.clone();
	colorReduce1(imageClone);

	namedWindow("ImageReduce");
	namedWindow("Image");
	imshow("ImageReduce", imageClone);
	imshow("Image", image);

	waitKey(0);

	return 0;
}