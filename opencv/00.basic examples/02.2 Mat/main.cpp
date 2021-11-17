#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void MatOp1();
void MatOp2();
void MatOp3();
void MatOp4();
void MatOp5();
void MatOp6();
void MatOp7();

int main()
{
	MatOp1();
	MatOp2();
	MatOp3();
	MatOp4();
	MatOp5();
	MatOp6();
	MatOp7();

	return 0;
}

void MatOp1()
{
	Mat img1; 	// empty matrix
	
	//unsigned char, 1-channel black or white
	Mat img2(480, 640, CV_8UC1);		
	
	//unsigned char, 3-channel red green blue
	Mat img3(480, 640, CV_8UC3);		
	
	// Size(width, height)
	Mat img4(Size(640, 480), CV_8UC3);	


	//initial values, 128(middle color)
	Mat img5(480, 640, CV_8UC1, Scalar(128));		
	
	// initial values, red(g,b,r)
	Mat img6(480, 640, CV_8UC3, Scalar(0, 0, 255));	

	// 0's matrix, 모두 0 으로 초기화
	Mat mat1 = Mat::zeros(3, 3, CV_32SC1);
	// 1's matrix, 모두 1 로 초기화
	Mat mat2 = Mat::ones(3, 3, CV_32FC1);
	// identity matrix, 역슬래쉬를 모두 1로 초기화
	Mat mat3 = Mat::eye(3, 3, CV_32FC1);
	
	float data[] = { 1, 2, 3, 4, 5, 6 };
	Mat mat4(2, 3, CV_32FC1, data);
	
	Mat mat5 = (Mat_<float>(2, 3) << 1, 2, 3, 4, 5, 6);
	Mat mat6 = Mat_<uchar>({2, 3}, { 1, 2, 3, 4, 5, 6 });
	/* 58 line 과 같다*/
	/*
	Mat_<float> tmp(2,3);
	tmp<<1,2,3,4,5,6;
	Mat mat5=tmp;
	*/
	
	//기존의 공간을 제거하고 덮여씌움
	mat4.create(256, 256, CV_8UC3);	// uchar, 3-channels
	mat5.create(4, 4, CV_32FC1);	// float, 1-channel
	
	//파란색으로 바꿈
	mat4 = Scalar(255, 0, 0);
	//값을 세팅
	mat5.setTo(1.f);
	
	
	//cout<<"img1 : "<< img1 << endl;
	//cout<<"img2 : "<< img2 << endl;
	//cout<<"img3 : "<< img3 << endl;
	//cout<<"img4 : "<< img4 << endl;
	//cout<<"img5 : "<< img5 << endl;
	//cout<<"img6 : "<< img6 << endl;
	
	cout<<"mat1 : "<< mat1 << endl;
	cout<<"mat2 : "<< mat2 << endl;
	cout<<"mat3 : "<< mat3 << endl;
	//cout<<"mat4 : "<< mat4 << endl;
	cout<<"mat5 : "<< mat5 << endl;
	cout<<"mat6 : "<< mat6 << endl;
	
}

void MatOp2()
{
	Mat img1 = imread("dog.bmp");

	Mat img2 = img1;
	Mat img3;
	img3 = img1;

	Mat img4 = img1.clone();
	Mat img5;
	
	//클론은 깊은 복사
	img1.copyTo(img5);
	
	
	//이전에 치환했던것 대입했던것 모두 바뀜 얕은 복시
	img1.setTo(Scalar(0, 255, 255));	// yellow

	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);
	imshow("img4", img4);
	imshow("img5", img5);

	waitKey();
	destroyAllWindows();
}

void MatOp3()
{
	Mat img1 = imread("cat.bmp");

	if (img1.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}
	
	//펑터-> 객체() , operator () 와 같음
	Mat img2 = img1(Rect(220, 120, 340, 240));
	Mat img3 = img1(Rect(220, 120, 340, 240)).clone();

	//이미지 색깔 반전
	img2 = ~img2;

	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);

	waitKey();
	destroyAllWindows();
}

void MatOp4()
{
	Mat mat1 = Mat::zeros(3, 4, CV_8UC1);
	
	//0~1증가
	for (int j = 0; j < mat1.rows; j++) {
		for (int i = 0; i < mat1.cols; i++) {
			mat1.at<uchar>(j, i)++;//반환타입이 임의의 타입일떄
		}
	}

	//1~2증가
	for (int j = 0; j < mat1.rows; j++) {
		uchar* p = mat1.ptr<uchar>(j);//반환을 포인터로 정의
		for (int i = 0; i < mat1.cols; i++) {
			p[i]++;
		}
	}

	//2~3증가
	for (MatIterator_<uchar> it = mat1.begin<uchar>(); it != mat1.end<uchar>(); ++it) {
		(*it)++;
	}

	cout << "mat1:\n" << mat1 << endl;
}

void MatOp5()
{
	Mat img1 = imread("lenna.bmp");

	cout << "Width: " << img1.cols << endl;
	cout << "Height: " << img1.rows << endl;
	cout << "Channels: " << img1.channels() << endl;

	//color check
	if (img1.type() == CV_8UC1)
		cout << "img1 is a grayscale image." << endl;
	else if (img1.type() == CV_8UC3)
		cout << "img1 is a truecolor image." << endl;

	float data[] = { 2.f, 1.414f, 3.f, 1.732f };
	Mat mat1(2, 2, CV_32FC1, data);
	cout << "mat1:\n" << mat1 << endl;
}

void MatOp6()
{
	float data[] = { 1, 1, 2, 3 };
	Mat mat1(2, 2, CV_32FC1, data);
	cout << "mat1:\n" << mat1 << endl;

	Mat mat2 = mat1.inv();
	cout << "mat2:\n" << mat2 << endl;

	cout << "mat1.t():\n" << mat1.t() << endl;
	cout << "mat1 + 3:\n" << mat1 + 3 << endl;
	cout << "mat1 + mat2:\n" << mat1 + mat2 << endl;
	cout << "mat1 * mat2:\n" << mat1 * mat2 << endl;
}

void MatOp7()
{
	Mat img1 = imread("lenna.bmp", IMREAD_GRAYSCALE);

	Mat img1f;
	//크기또는 타입을 변환시키고 싶을때
	img1.convertTo(img1f, CV_32FC1);

	uchar data1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	Mat mat1(3, 4, CV_8UC1, data1);
	Mat mat2 = mat1.reshape(0, 1);

	cout << "mat1:\n" << mat1 << endl;
	cout << "mat2:\n" << mat2 << endl;
	
	//행렬의 행크기 변경
	mat1.resize(5, 100);
	cout << "mat1:\n" << mat1 << endl;

	Mat mat3 = Mat::ones(1, 4, CV_8UC1) * 255;
	
	//행렬의 마지막 행에 원소 데이터 추가
	mat1.push_back(mat3);
	cout << "mat1:\n" << mat1 << endl;
}
