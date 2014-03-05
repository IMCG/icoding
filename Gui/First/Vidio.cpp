#include <opencv2/opencv.hpp>  
using namespace cv;
using namespace std;
int main()
{
	// 创建VideoCapture对象来读取视频文件  
	VideoCapture cap("E:\\first.mp4");
	//check if the file was opened properly  
	if (!cap.isOpened())
	{
		cout << "Capture could not be opened succesfully" << endl;
		return -1;
	}
	namedWindow("Video");
	// Play the video in a loop till it ends  
	while (char(waitKey(1)) != 'q' && cap.isOpened())
	{
		Mat frame;
		cap >> frame;
		// Check if the video is over  
		if (frame.empty())
		{
			cout << "Video over" << endl;
			break;
		}
		imshow("Video", frame);
	}
	return 0;
}