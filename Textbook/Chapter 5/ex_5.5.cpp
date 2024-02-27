#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat src = imread("canny.jpg", IMREAD_COLOR);
	Mat gray;
	imshow("Original image", src);
	cvtColor(src, gray, COLOR_BGR2GRAY);
	Canny(gray, gray, 50, 150, 3);
	gray.convertTo(gray, CV_8U);
	imshow("Image edge", gray);
	waitKey();
	return 0;
}