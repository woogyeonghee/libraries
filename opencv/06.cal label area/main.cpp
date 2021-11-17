// #include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
// #include <opencv2/videoio.hpp>
// #include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;
static int numOfLabels;

string gstreamer_pipeline (int capture_width, int capture_height, int display_width, int display_height, int framerate, int flip_method) {
    return "nvarguscamerasrc ! video/x-raw(memory:NVMM), width=(int)" + to_string(capture_width) + ", height=(int)" +
           to_string(capture_height) + ", format=(string)NV12, framerate=(fraction)" + to_string(framerate) +
           "/1 ! nvvidconv flip-method=" + to_string(flip_method) + " ! video/x-raw, width=(int)" + std::to_string(display_width) + ", height=(int)" +
           to_string(display_height) + ", format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink";
}

int main()
{
    int capture_width = 1280 ;
    int capture_height = 720 ;
    int display_width =  1280 ;
    int display_height = 720 ;
    int framerate = 60 ;
    int flip_method = 0 ;

    string pipeline = gstreamer_pipeline(capture_width,
	capture_height,
	display_width,
	display_height,
	framerate,
	flip_method);
    cout << "Using pipeline: \n\t" << pipeline << "\n";
 
    VideoCapture cap(pipeline,CAP_GSTREAMER);
    if(!cap.isOpened()) {
	cout<<"Failed to open camera."<<endl;
	return (-1);
    }

    namedWindow("CSI Camera", WINDOW_AUTOSIZE);

    cout << "Hit ESC to exit" << "\n" ;    
    Mat img;
    Mat img2;
while(true)
    {

    Mat img_hsv, blue_mask;
    if (!cap.read(img2)) {
		std::cout<<"Capture read error"<<std::endl;
		break;
	}
    flip(img2,img,0);
    //img=2*img;
    cvtColor(img, img_hsv, COLOR_BGR2HSV);
    Scalar lower_blue = Scalar(100, 30, 30);
    Scalar upper_blue = Scalar(140, 255, 255);
    inRange(img_hsv, lower_blue, upper_blue, blue_mask);
    Mat blue_image;
    bitwise_and(img, img, blue_image, blue_mask);

    Mat img_labels, stats, centroids;
    numOfLabels = connectedComponentsWithStats(blue_mask, img_labels, stats, centroids, 8, CV_32S);

    int j;
    for (j = 1; j < numOfLabels; j++) {
	    int area = stats.at<int>(j, CC_STAT_AREA);
	    int left = stats.at<int>(j, CC_STAT_LEFT);
	    int top = stats.at<int>(j, CC_STAT_TOP);
	    int width = stats.at<int>(j, CC_STAT_WIDTH);
	    int height = stats.at<int>(j, CC_STAT_HEIGHT);

	    int centerX = centroids.at<double>(j, 0);
	    int centerY = centroids.at<double>(j, 1);

	    if (area > 500) // 100 < area = no color show
	    {
		    circle(img, Point(centerX, centerY), 5, Scalar(255, 0, 0), 1);
		    rectangle(img, Point(left, top), Point(left + width, top + height), Scalar(0, 0, 255), 1);
		    putText(img, to_string(area), Point(left, top), FONT_HERSHEY_PLAIN, 2.0, Scalar(255, 0, 0), 1);
		    imshow("img_mask", blue_mask);
		    imshow("img_result", blue_image);
		    imshow("find labelcolor", img);
	    }
    	}	
    	int keycode=waitKey(30)&0xff;
    	if(keycode =='i') break;
	if(keycode ==27) break;
    }
    cap.release();
    destroyAllWindows() ;
    return 0;

}
