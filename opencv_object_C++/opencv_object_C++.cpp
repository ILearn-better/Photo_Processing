// opencv_object_C++.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
using namespace cv;
using namespace std;
/*
需求:
1.实现一些基础的图像数据增强操作
1.1 翻转
1.2 剪切
1.3 颜色变换
1.4 平滑
等等
2.实现QT可视化操作,并打包



*/

Mat img = Mat::zeros(512, 512, CV_8UC3);

void judge_empty(Mat img) {
	if (img.empty()) {
		std::cout << "empty" << std::endl;

	}
	else {
		std::cout << "not empty" << std::endl;
	}
}
void draw_line_photo(Mat img) {

	/*绘制图像*/
	// 创建一个黑色的图像
	//Mat img = Mat::zeros(512, 512, CV_8UC3);
	// 画一条 5px 宽的蓝色对角线
	line(img, Point(0, 0), Point(511, 511), Scalar(255, 0, 0), 5);
	imshow("Image", img);
	waitKey(0);
}
void show_pic(Mat img) {
	imshow("windows title", img);
	waitKey(0);
}
void draw_rectangle(Mat img) {

	Point top_left = Point(100, 100);
	Point bottom_right = Point(150, 150);
	rectangle(img, top_left, bottom_right, Scalar(0, 255, 0), 3);
	imshow("Image", img);
	waitKey(0);

}
void save_img(Mat img) {
	imwrite("pic.bmp", img);
}
void work_1() {
	// 创建一个黑色的图像
	Mat img = Mat::ones(512, 512, CV_8UC3);

	// 定义文本
	String text = "Hello, OpenCV!";
	// 定义文本位置
	Point textOrg = Point(150, 150);
	// 定义字体
	int fontFace = FONT_HERSHEY_SIMPLEX;
	// 定义字体大小
	double fontScale = 1;
	// 定义文本颜色
	Scalar textColor = Scalar(255, 255, 255);
	// 定义文本厚度
	int thickness = 2;

	// 在图像上添加文本
	putText(img, text, textOrg, fontFace, fontScale, textColor, thickness);

	line(img, Point(100, 175), Point(400, 175), Scalar(255, 0, 0), 5);

	// 显示图像
	imshow("Image with text", img);
	waitKey(0);
}
void show_mouse_event() {
	// Create a vector of strings containing the names of mouse events available in OpenCV
	vector<string> events = {
		"EVENT_FLAG_ALTKEY",
		"EVENT_FLAG_CTRLKEY",
		"EVENT_FLAG_LBUTTON",
		"EVENT_FLAG_MBUTTON",
		"EVENT_FLAG_RBUTTON",
		"EVENT_FLAG_SHIFTKEY",
		"EVENT_LBUTTONDBLCLK",
		"EVENT_LBUTTONDOWN",
		"EVENT_LBUTTONUP",
		"EVENT_MBUTTONDBLCLK",
		"EVENT_MBUTTONDOWN",
		"EVENT_MBUTTONUP",
		"EVENT_MOUSEHWHEEL",
		"EVENT_MOUSEMOVE",
		"EVENT_MOUSEWHEEL",
		"EVENT_RBUTTONDBLCLK",
		"EVENT_RBUTTONDOWN",
		"EVENT_RBUTTONUP"
	};

	// Iterate over the vector of event names
	for (int i = 0; i < (int)events.size(); i++) {
		// Get the name of the current event
		string event_name = events[i];
		//cout << event_name << endl;

		// Check if the event name contains the string "EVENT"
		if (event_name.find("EVENT") != string::npos) {
			// Add the event name to the vector of events
			events.push_back(event_name);
		}
	}

	// Iterate over the vector of event names
	for (const auto& event : events) {
		// Print out the name of the current event
		cout << event << endl;
	}
}


// Global variable to keep track of whether the left mouse button is down
bool drawing = false;

void draw_circle(int event, int x, int y, int flags, void* param) {
	// Check if the left mouse button was pressed
	if (event == EVENT_LBUTTONDOWN) {
		// Set the drawing flag to true
		drawing = true;
	}
	// Check if the left mouse button was released
	else if (event == EVENT_LBUTTONUP) {
		// Set the drawing flag to false
		drawing = false;
	}
	// Check if the mouse was moved
	else if (event == EVENT_MOUSEMOVE) {
		// Check if the drawing flag is true
		if (drawing) {
			// Draw a circle at the current mouse position
			circle(img, Point(x, y), 5, Scalar(255, 0, 0), -1);
		}
	}
}

void mouse() {
	namedWindow("image");
	setMouseCallback("image", draw_circle);

	// Display the image and wait for a key press
	while (true) {
		imshow("image", img);
		if (waitKey(20) == 27) {
			break;
		}
	}

	// Destroy all windows
	destroyAllWindows();
}

void clip_img(Mat img) {
	if (img.empty()) {
		printf("could not load image...\\n");
	}

	imshow("input", img);
	Mat dst;
	// X Flip 倒影
	flip(img, dst, 0);
	imshow("x-flip", dst);
	// Y Flip 镜像
	flip(img, dst, 1);
	imshow("y-flip", dst);
	// XY Flip 对角
	flip(img, dst, -1);
	imshow("xy-flip", dst);
	waitKey(0);
	//return dst;
}
void color_transform(Mat img) {
	imshow("input", img);
	Mat gray, hsv;
	cvtColor(img, hsv, COLOR_BGR2HSV);
	cvtColor(img, gray, COLOR_BGR2GRAY);
	imshow("Hsv", hsv);
	imshow("Gray", gray);
	waitKey(0);
	destroyAllWindows();
}
void soft(Mat img, float index) {
	/*
	功能:
		对输入的img做平滑
	参数:
		img:输入的图片Mat
		index:调整平滑指数
	*/
	imshow("origin", img);
	Mat dst;
	int ksize = (int)index * 2 + 1; // 核大小必须为奇数
	GaussianBlur(img, dst, Size(ksize, ksize), 0, 0);
	imshow("smooth", dst);
	waitKey(0);

}
int main()
{  
	
	/*展示图像  */
	String	path = "C:/Users/6/Pictures/download.jpg";

	Mat img = imread(path);
		
	/*
	judge_empty(img);

	show_pic(img);
	
	draw_line_photo(img);
	*/

	//draw_rectangle(img);
	
	//work_1();
	//show_mouse_event();

	//mouse();
	//clip_img(img);
	//color_transform(img);
	soft(img, 1);
	system("pause");
	return 0;


}
/*
vs2022下opencv-c++安装教程:
【Visual Studio 2022 配置 OpenCV4.5.5-哔哩哔哩】 https://b23.tv/l7O9QW8
*/
