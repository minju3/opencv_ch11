#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

// 실습1
/*int main(void)
{
	Mat m1 = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
	Mat m2 = getStructuringElement(MORPH_CROSS, Size(3, 3), Point(-1, -1));
	Mat m3 = getStructuringElement(MORPH_ELLIPSE, Size(5, 3), Point(-1, -1));

	cout << "MORPH_RECT\n" << m1 << endl;
	cout << "MORPH_CROSS\n" << m2 << endl;
	cout << "MORPH_ELLIPSE\n" << m3 << endl;

	return 0;
}*/

//실습과제2
/*int main(void) {
	Mat src = imread("letterj.png", IMREAD_GRAYSCALE);
	if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }

	Mat bin;
	threshold(src, bin, 127, 255, THRESH_BINARY);

	Mat dst, dst2;
	morphologyEx(bin, dst, MORPH_OPEN, Mat(),Point(-1,-1),1);
	morphologyEx(dst, dst2, MORPH_CLOSE, Mat(), Point(-1,-1),3);

	imshow("src", src);
	imshow("bin", bin);
	imshow("dst2", dst2);
	waitKey();
	return 0;
}*/

//실습과제3
/*int main(void) {
	Mat src = imread("letterj2.png", IMREAD_GRAYSCALE);
	if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }
	
	Mat bin;
	threshold(src, bin, 127, 255, THRESH_BINARY);

	Mat dst;
	morphologyEx(bin, dst, MORPH_GRADIENT, Mat());

	imshow("src", src);
	imshow("bin", bin);
	imshow("edge", dst);
	waitKey();
	return 0;
}*/

//실습과제4
int main(void) {
	Mat src = imread("car.jpg", IMREAD_GRAYSCALE);
	if (src.empty()) { cerr << "Image load failed!" << endl; }

	Mat dst, res, bin, close;
	for (int sig = 1; sig <= 5; sig++) {
		GaussianBlur(src, dst, Size(5, 5), (double)sig);
	}

	Mat dx;
	Sobel(dst, dx, CV_8U, 1, 0);
	res = abs(dx);

	threshold(res, bin, 128, 255, THRESH_BINARY);
	Mat M = getStructuringElement(MORPH_RECT, Size(32, 5), Point(-1,-1));
	morphologyEx(bin, close, MORPH_CLOSE, M);

	imshow("src", src);
	imshow("x축 소벨", res);
	imshow("이진화 영상", bin);
	imshow("닫힘 연산", close);
	waitKey();
	return 0;

}