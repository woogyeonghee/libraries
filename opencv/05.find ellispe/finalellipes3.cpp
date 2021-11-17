#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <algorithm>
#include <iostream>
#include <math.h>
#include<string>
#include <windows.h>
#include<cstdlib>
#include<fstream>

using namespace std;
using namespace cv;

int main()
{
    int lowThreshold = 0;
    int highThreshold = 90;
    
    int low_H = 110, low_S = 70, low_V = 180;
    int high_H = 140, high_S = 82, high_V = 209;
    
    Mat src, gray;
    //src = imread("returnc(0).jpg");
    //src = imread("rr.jpg");
    src = imread("1.jpg");
    if (src.empty()) {
        return 0;
    }
    //resize(src, src, Size(200, 400));
    vector<Vec4i> hierarchy;
    cvtColor(src, gray, COLOR_BGR2GRAY);

    //cvtColor(src, gray,COLOR_BGR2HSV);
    blur(gray, gray, Size(3, 3));
    //GaussianBlur(gray, gray, Size(7, 7), 0);
    //Canny(gray, gray, lowThreshold, highThreshold, 3);
    //threshold(gray, gray, 100, 255, THRESH_BINARY);



    //threshold(gray, gray, 100, 255, THRESH_BINARY);
    vector<vector<Point> > contours;

    inRange(gray, Scalar(low_H, low_S, low_V), Scalar(high_H, high_S, high_V), gray);

    bitwise_not(gray, gray);

    findContours(gray, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
    namedWindow("Gray", WINDOW_AUTOSIZE);



    //RotatedRect fitEllipse()
    vector<vector<Point>> conPoly(contours.size());

    int area2=0;
    Moments moment1, moment2; int x1, x2, y1, y2;
    for (auto i : contours) {
        moment1 = moments(i, 1);
        x1 = int(moment1.m01 / moment1.m00);
        y1 = int(moment1.m10 / moment1.m00);

        RotatedRect temp = minAreaRect(Mat(i));
        //RotatedRect temp = fitEllipse(contours);

        if (i.size() > 200 && i.size() < 300) {
            //circle(src, Point(x1, y1), 3, Scalar(0,0,255), -1, 3);
            ellipse(src, temp, Scalar(0, 0, 255), 3);
            int he=temp.size.height;
            int wi=temp.size.width;
            area2 = he * wi * 0.5 * 0.5 * 3.14;
            cout << area2 << endl;
        }

    }
    int area3=0;
    for (int i = 0; i < contours.size();i++) {
 

        int area = contourArea(contours[i]);
        if (area > 11100)
        {
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.01 * peri, true);
            drawContours(src, conPoly, i, Scalar(255, 0, 0), 3);
            cout << area << endl;
            area3 = area;
        }

    }
    cout << area2 << endl;
    cout << area3 << endl;
    if (abs(area3 - area2) < 1000)
        cout << "can" << endl;
    else cout << "not can" << endl;

    namedWindow("Ready", WINDOW_AUTOSIZE);
    imshow("Ready", src);
    imshow("Gray", gray);


    waitKey(0);
    destroyAllWindows();
    return 0;
}