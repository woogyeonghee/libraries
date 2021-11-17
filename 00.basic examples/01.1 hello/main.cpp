#include "opencv2/opencv.hpp"
#include <iostream>

//using namespace cv;
using namespace std;
using std::vector;

int main()
{
	cout << "Hello OpenCV " << CV_VERSION << endl;
	
	
	//행렬을 나타내는 클래스
	cv::Mat img;
	
	//이미지를 불러 올때, 흑백으로 불러올떄
	img = cv::imread("lena.jpg",cv::IMREAD_GRAYSCALE);
	
	
	if (img.empty()) {
		//비정상적인 이미지를 불러올때
		cerr << "Image load failed!" << endl;
		return -1;
	}
	
	//params 저장할 파일 형식
	vector<int> params;
	//압축 형태
	params.push_back(cv::IMWRITE_JPEG_QUALITY);
	//압축률
	params.push_back(95);
	//저장
	cv::imwrite("lena2.jpg",img, params);
	
	//이미지 메모리, "image" 윈도우 창을 구별
	cv::namedWindow("image");
	
	//띄운 창에 img를 띄움
	cv::imshow("image", img);

	//msec wait
	cv::waitKey(2000);
	
	//메모리 소거 꼭 해야하는것은 아님
	cv::destroyWindow("image");
	
	return 0;
}
