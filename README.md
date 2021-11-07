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
	- lena.jpg example
	- params
	- IMWRITE_JPEG_QUALITY
	- IMREAD_GRAYSCALE
	- namedWindow
	- destoryWindow
	- waitkey
<br/>

02.1. basic_data_types
	- Point class
	- Size class
	- Rect class
	- Rotated class
	- Range class
	- String class
<br/>

02.2. Mat
	- matrix in memory
	- depth
	- Mat::zeros; ones; eye
	- setTo
	- clone; copyTo
	- img(Rect())
	- ~img
	- mat::at
	- mat::ptr
	- img.type
	- mat.inv
	- convertTo
	- reshape
	- push_back
<br/>

02.3. scalar
	- scalar
<br/>

02.4. inputArray
	- inputArray
	- outputArray
<br/>

03.1. video
	- VideoCapture

03.2. drawing
	- drawing

03.3. keyboard
	- use key break

03.4. mouse
	- use mouse break

03.5. trackbar
	- make gui trackbar
	
03.6. storage
	- storage like a capcule
	
03.7. utils
	- mask
	- time

