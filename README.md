# opencv

https://sunkyoo.github.io/opencv4cvml/


# the way to build opencv project


- goto ur project dir
~~~
cd {OpenCV_INCLUDE_DIRS}
~~~


- make CMakeList.txt, this is example, you can also download txt file in main branch
~~~
cmake_minimum_required(VERSION 2.8)
project(video)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(video main.cpp)
target_link_libraries(video ${OpenCV_LIBS})
~~~


- make dir named build dir
~~~
mkdir build
~~~


- goto build dir
~~~
cd build
~~~


- cmake
~~~
cmake ..
~~~


- make
~~~
make
~~~


- execute ur program
~~~
./a.out
~~~


# contents

01. hello

02. 기본자료형

03. 비디오, 그리기, 끝내기, 저장하기, 트랙바, 마스크, 유틸리티

04. 밝기, 명암, 히스토그램

05. 영상의 비교 및 합성

06. 영상 필터링 

07. 영상 기하학적 변환

08. 에지 검출, 직선 검출, 원 검출

09. 특정 색 검출 이진화로

10. 이진화 영상 처리

11. 외곽선 검출

12. 템플릿, 얼굴, 보행자, QR 검출

13. 코너, 특징점 매칭

14. 머신러닝

15. 딥러닝

# keyword_class

## Point_ 
 
## Size_ 

## Rect_ 

## RotatedRect 

## Range 

## String 

## Mat 

- Mat 02

- zeros 02

- ones 02

- eye 02

- create 02

- setTo 02,03

- clone 02,03

- copyTo 02

- rowRange 02

- colRange 02

- row 02

- col 02

- at 02

- ptr 02

- mul 02

- inv 02

- t 02

- convertTo 02

- reshape 02

- resize 02

- pop_back 02

## vec 

## scalar 

## InputArray 

- getMat 02

## OutputArray 

## VideoCapture 

- VideoCapture 03

- open 03

- isOpened 03

- release 03

- read 03

- get 03

## VideoWriter 

- VideoWriter 03

- open 03

- fourcc 03

- write 03

- release 03

## FileStorage 

- open 03

- isOpend 03

- release 03

## CascadeClassifier

- load 12

- empty 12

- detectMultiScale 12

## HOGDescriptor 

- getDefaultPeopleDetector 12

- setSVMDetector 12

- detectMultiScale 12

- HOGGDescriptor 14

- compute 14

## QRCodeDetector

- detect 12

- decode 12

- detectAndDecode 12

## ORB

- create 13

## Feature2D

- detect 13

- compute 13

- detectAndCompute 13

## BFMatcher 

- create 13

## FlannBasedMatcher 

- create 13

## DescriptorMatcher 

- match 13

## Stitcher 

- create 13

## StatModel 

- train 14

- predict 14

## KNerest 

- create 14

- setDefault 14

- setIsClassifier 14

- findeNearest 14

## SVM

- create 14

- setType 14

- setKernel 14

- trianAuto 14

# Net

- empty 15

- setInput 15

- forward 15

# keyword-function 

- line 03

- arrowedLine 03

- drawMarker 03

- rectangle 03

- circle 03

- ellipse 03

- polylines 03

- putText 03

- getTextSize 03

- waitKey 03

- setMouseCallBack 03

- createTrackbar 03

- getTrackbarPos 03

- setTrackbarPos 03

- getTickCount 03

- getTickFrequency 03

- sum 03

- mean 03

- minMacLoc 03

- normalize 03

- cvRound 03

- calcHist 04

- equalizeHist 04

- add 05

- addWeighted 05

- substract 05

- absdiff 05

- multiply 05

- divide 05

- bitwise_and 05

- bitwise_or 05

- bitwise_xor 05

- bitwise_not 05

- filter2D 06

- blur 06

- GaussianBlur 07

- GaussianKernel 07

- randn 07

- bilateralFilter 07

- medianBlur 07

- getAffineTransform 07

- WarpAffine 07

- transform 07

- resize 07

- getRotationMatrix2D 07

- rotate 07

- flip 07

- getPerspectiveTransform 07

- WarpPerspective 07

- Sobel 08

- Scharr 08

- magnitude 08

- phase 08

- Canny 08

- HoughLines 08

- HoughLinesP 08

- HoughCircles 08

- cvtColor 09

- split 09

- merge 09

- inrange 09

- calcBackProject 09

- threshold 10

- adaptiveThreshold 10

- getStructuringElement 10

- erode 10

- dilate 10

- morphologyEx 10

- connectedComponents 11

- connectedComponentsWithStats 11

- findContours 11

- drawContours 11

- boudingRect 11

- minAreaRect 11

- minEnclosingCircle 11

- arcLength 11

- contourArea 11

- approxPolyDP 11

- matchTemplate 12

- cornerHarris 13

- Fast 13

- drawKeypoint 13

- drawMatches 13

- findHomography 13

- readNet 15

- bolbFromImage 15

	
	

