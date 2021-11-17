#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int lower_hue_B = 0, upper_hue_B = 255;
int lower_hue_G = 100, upper_hue_G = 255;
int lower_hue_R = 0, upper_hue_R = 255;
Mat src, src_hsv, mask;

void on_hue_changed(int, void*);
int main(int argc, char* argv[])
{
	src = imread("can.jpg", IMREAD_COLOR);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	cvtColor(src, src_hsv, COLOR_BGR2HSV);

	imshow("src", src);

	namedWindow("mask");
	namedWindow("track");
	createTrackbar("Lower Hue_B", "track", &lower_hue_B, 255, on_hue_changed);
	createTrackbar("Upper Hue_B", "track", &upper_hue_B, 255, on_hue_changed);
	//on_hue_changed(0, 0);
	createTrackbar("Lower Hue_G", "track", &lower_hue_G, 255, on_hue_changed);
	createTrackbar("Upper Hue_G", "track", &upper_hue_G, 255, on_hue_changed);
	//on_hue_changed(0, 0);
	createTrackbar("Lower Hue_R", "track", &lower_hue_R, 255, on_hue_changed);
	createTrackbar("Upper Hue_R", "track", &upper_hue_R, 255, on_hue_changed);
	on_hue_changed(0, 0);

	waitKey();
	return 0;
}

void on_hue_changed(int, void*)
{
	int numOfLabels = 0;
	Mat img;
	Scalar lowerb(lower_hue_B, lower_hue_G, lower_hue_R);
	Scalar upperb(upper_hue_B, upper_hue_G, upper_hue_R);
	inRange(src_hsv, lowerb, upperb, mask);

	int morph_size = 2;
	Mat element = getStructuringElement(MORPH_RECT, Size(2 * morph_size + 1, 2 * morph_size + 1),
		Point(morph_size, morph_size));
	morphologyEx(mask, mask, MORPH_OPEN, element);
	morphologyEx(mask, mask, MORPH_CLOSE, element);
	Mat blue_image;

	//bitwise_not(mask, mask);


	Mat img_labels, stats, centroids;
	numOfLabels = connectedComponentsWithStats(mask, img_labels, stats, centroids, 8, CV_32S);




	imshow("mask", mask);
}


