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

## Point_ 02
 
## Size_ 02

## Rect_ 02

## RotatedRect 02

## Range 02

## String 02

## Mat 02

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

## vec 02

## scalar 02

- sum 03

- mean 03

-

## InputArray 02

- getMat 02

## OutputArray 02

## VideoCapture 03

- VideoCapture 03

- open 03

- isOpened 03

- release 03

- read 03

- get 03

## VideoWriter 03

- VideoWriter 03

- open 03

- fourcc 03

- write 03

- release 03

## FileStorage 03

- open 03

- isOpend 03

- release 03


# keyword-function 03

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

-




	
	

