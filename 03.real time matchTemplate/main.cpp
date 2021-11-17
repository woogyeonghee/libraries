// #include <iostream>
#include <opencv2/opencv.hpp>
// #include <opencv2/videoio.hpp>
// #include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;


string gstreamer_pipeline (int capture_width, int capture_height, int display_width, int display_height, int framerate, int flip_method) {
    return "nvarguscamerasrc ! video/x-raw(memory:NVMM), width=(int)" + to_string(capture_width) + ", height=(int)" +
           to_string(capture_height) + ", format=(string)NV12, framerate=(fraction)" + to_string(framerate) +
           "/1 ! nvvidconv flip-method=" + to_string(flip_method) + " ! video/x-raw, width=(int)" + to_string(display_width) + ", height=(int)" +
           to_string(display_height) + ", format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink";
}
const Mat& colorLabelfind(Mat& img);
int main()
{
    int capture_width = 1280 ;
    int capture_height = 720 ;
    int display_width =  800 ;
    int display_height = 600 ;
    int framerate = 60 ;
    int flip_method = 0 ;

    string pipeline = gstreamer_pipeline(capture_width,
   capture_height,
   display_width,
   display_height,
   framerate,
   flip_method);
    cout << "Using pipeline: \n\t" << pipeline << "\n";
 
    VideoCapture cap(pipeline, CAP_GSTREAMER);
    if(!cap.isOpened()) {
   cout<<"Failed to open camera."<<endl;
   return (-1);
    }

    namedWindow("CSI Camera", WINDOW_AUTOSIZE);
    Mat img;

    cout << "Hit ESC to exit" << "\n" ;    
   int i = 0;
   Mat subImg;
   Mat subImg_;
   Mat templ = imread("cap.jpg", IMREAD_COLOR);
   Mat templ2 = imread("line.jpg", IMREAD_COLOR);
   Mat templ3 = imread("no.jpg", IMREAD_COLOR);
   Mat templ4 = imread("can.jpg", IMREAD_COLOR);
   Mat templ5 = imread("cap_line.jpg", IMREAD_COLOR);
   
   Mat res, res_norm;
   Mat res2, res_norm2;
   Mat res3, res_norm3;
   Mat res4, res_norm4;
   Mat res5, res_norm5;
   
   double maxv;
   Point maxloc;
   double maxv2;
   Point maxloc2;
   double maxv3;
   Point maxloc3;
   double maxv4;
   Point maxloc4;
   double maxv5;
   Point maxloc5;
while(true)
    {
       if (!cap.read(img)) {
      cout<<"Capture read error"<<endl;
      break;
   }
   flip(img, subImg, 0);
   imshow("CSI Camera",subImg);
   int y1 = 0;
   int y2 = 600;
   int x1 = 200;
   int x2 = 650;
	
   subImg_ = subImg(Range(y1, y2), Range(x1, x2));
   subImg_ = subImg_ + Scalar(10, 10, 10);
   
   //Mat noise(subImg_.size(), CV_32SC3);
   //randn(noise, 0, 10);
   //add(subImg_, noise, subImg_, Mat(), CV_8UC3);


   matchTemplate(subImg_, templ, res, TM_CCOEFF_NORMED);
   matchTemplate(subImg_, templ2, res2, TM_CCOEFF_NORMED);
   matchTemplate(subImg_, templ3, res3, TM_CCOEFF_NORMED);
   matchTemplate(subImg_, templ4, res4, TM_CCOEFF_NORMED);
   matchTemplate(subImg_, templ5, res5, TM_CCOEFF_NORMED);
   
   normalize(res, res_norm, 0, 255, NORM_MINMAX, CV_8U);
   normalize(res2, res_norm2, 0, 255, NORM_MINMAX, CV_8U);
   normalize(res3, res_norm3, 0, 255, NORM_MINMAX, CV_8U);
   normalize(res4, res_norm4, 0, 255, NORM_MINMAX, CV_8U);
   normalize(res5, res_norm5, 0, 255, NORM_MINMAX, CV_8U);

   minMaxLoc(res, 0, &maxv, 0, &maxloc);
   if(maxv>0.8){
      //cout << "maxv: " << maxv << endl;
      rectangle(subImg_, Rect(maxloc.x, maxloc.y, templ.cols, templ.rows), Scalar(0, 0, 255), 2);
      putText(subImg_,"cap",Point(maxloc.x,maxloc.y),FONT_HERSHEY_DUPLEX,1,Scalar(0,0,255));
   }

   
   minMaxLoc(res2, 0, &maxv2, 0, &maxloc2);
   if(maxv2>0.8){
      //cout << "maxv: " << maxv << endl;
      rectangle(subImg_, Rect(maxloc2.x, maxloc2.y, templ2.cols, templ2.rows), Scalar(255, 0, 0), 2);
      putText(subImg_,"line",Point(maxloc2.x,maxloc2.y),FONT_HERSHEY_DUPLEX,1,Scalar(255,0,0));
   }

   minMaxLoc(res3, 0, &maxv3, 0, &maxloc3);
   if(maxv3>0.7){
      //cout << "maxv: " << maxv << endl;
      rectangle(subImg_, Rect(maxloc3.x, maxloc3.y, templ3.cols, templ3.rows), Scalar(255, 255, 0), 2);
      putText(subImg_,"no",Point(maxloc3.x,maxloc3.y),FONT_HERSHEY_DUPLEX,1,Scalar(255,255,0));
      colorLabelfind(subImg_);
   }

   
   minMaxLoc(res4, 0, &maxv4, 0, &maxloc4);
   if(maxv4>0.7){
      //cout << "maxv: " << maxv << endl;
      rectangle(subImg_, Rect(maxloc4.x, maxloc4.y, templ4.cols, templ4.rows), Scalar(255, 0, 255), 2);
      putText(subImg_,"can",Point(maxloc4.x,maxloc4.y),FONT_HERSHEY_DUPLEX,1,Scalar(255,0,255));
   }
   
   minMaxLoc(res5, 0, &maxv5, 0, &maxloc5);
   if(maxv5>0.8){
      //cout << "maxv: " << maxv << endl;
      //rectangle(subImg_, Rect(maxloc5.x, maxloc5.y, templ5.cols, templ5.rows), Scalar(0, 255, 0), 2);
      //putText(subImg_,"cap_line",Point(maxloc5.x,maxloc5.y),FONT_HERSHEY_DUPLEX,1,Scalar(0,255,0));
   }
   
   imshow("img",subImg_);
   int keycode = waitKey(50) & 0xff ;
       string filename =format("%d.jpg",i);
   if(keycode == 'i'){
   imwrite(filename, subImg);
   i++;   
   }    
        if (keycode == 27) break ;
    }   

    cap.release();
    destroyAllWindows() ;
    return 0;
}
const Mat& colorLabelfind(Mat& img)
{
    //img = 2 * img;
    int numOfLabels = 0;
    Mat img_hsv, blue_mask;
    cvtColor(img, img_hsv, COLOR_BGR2HSV);
    Scalar lower_blue = Scalar(0, 100, 0);
    Scalar upper_blue = Scalar(255, 255, 255);

    inRange(img_hsv, lower_blue, upper_blue, blue_mask);

    int morph_size = 2;
    Mat element = getStructuringElement(MORPH_RECT, Size(2 * morph_size + 1, 2 * morph_size + 1),
    Point(morph_size, morph_size));
    morphologyEx(blue_mask, blue_mask, MORPH_OPEN, element);
    morphologyEx(blue_mask, blue_mask, MORPH_CLOSE, element);

    //Mat blue_image;
    //bitwise_not(blue_mask,blue_mask);


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

        if (area > 1000) // 100 < area = no color show
        {
            circle(img, Point(centerX, centerY), 5, Scalar(255, 0, 0), 1);
            rectangle(img, Point(left, top), Point(left + width, top + height), 			Scalar(0, 0, 255), 1);
            putText(img, to_string(area), Point(left, top), FONT_HERSHEY_PLAIN, 2.0, 				Scalar(255, 0, 0), 1);
	    cout<<"yes"<<endl;
            //imshow("find labelcolor", img);
            return img;
        }
	    cout<<"no"<<endl;
    }
    return img;
}

   
