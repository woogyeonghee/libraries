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

	
	
	

