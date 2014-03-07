// Program to write video from default camera device to file  
// Author: Samarth Manoj Brahmbhatt, University of Pennsylvania  
#include <opencv2/opencv.hpp>  
using namespace cv;  
using namespace std;  
int main()  
{  
     // 0 is the ID of the built-in laptop camera, change if you want to use other camera  
     VideoCapture cap(0);  
    //check if the file was opened properly  
    if(!cap.isOpened())  
    {  
        cout << "Capture could not be opened succesfully" << endl;  
        return -1;  
    }  
    // Get size of frames  
    Size S = Size((int) cap.get(CV_CAP_PROP_FRAME_WIDTH), (int)  
    cap.get(CV_CAP_PROP_FRAME_HEIGHT));  
    // Make a video writer object and initialize it at 30 FPS  
    VideoWriter put("output.mpg", CV_FOURCC('M','P','E','G'), 30, S);  
    if(!put.isOpened())  
    {  
        cout << "File could not be created for writing. Check permissions" << endl;  
        return -1;  
    }  
    namedWindow("Video");  
    // Play the video in a loop till it ends  
    while(char(waitKey(1)) != 'q' && cap.isOpened())  
   {  
       Mat frame;  
       cap >> frame;  
       // Check if the video is over  
       if(frame.empty())  
       {  
           cout << "Video over" << endl;  
           break;  
       }  
       imshow("Video", frame);  
       put << frame;  
    }  
  return 0;  
}  


#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
  
using namespace cv;  
  
void main()  
{  
    VideoCapture capture(0);  
    VideoWriter writer("VideoTest.avi", CV_FOURCC('M', 'J', 'P', 'G'), 25.0, Size(640, 480));  
    Mat frame;  
      
    while (capture.isOpened())  
    {  
        capture >> frame;  
        writer << frame;  
        imshow("video", frame);  
        if (cvWaitKey(20) == 27)  
        {  
            break;  
        }  
    }  
}  