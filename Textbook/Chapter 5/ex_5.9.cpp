#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("canny.jpg", IMREAD_COLOR);
	Mat gray;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	threshold(gray, gray, 200, 255, THRESH_BINARY_INV);
	imshow("Gray image", gray);
	int largest_area = 0;
	int largest_contour_index = 0;
	Rect bounding_rect;
	vector<vector<Point>>contours;
	vector<Vec4i>hierachy;
	findContours(gray, contours, hierachy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);
	for (int i = 0; i < contours.size(); i++)
	{
		double a = contourArea(contours[i], false);
		if (a > largest_area) {
			largest_area = a; cout << i << " area  " << a << endl;
			largest_contour_index = i;
			bounding_rect = boundingRect(contours[i]);
		}
	}
	Scalar color(255, 255, 255); 
	drawContours(src, contours, largest_contour_index, color, FILLED, 8, hierachy);
	rectangle(src, bounding_rect, Scalar(0, 255, 0), 2, 8, 0);
	namedWindow("Display window", WINDOW_AUTOSIZE);
	imshow("Display window", src);
	waitKey(0);
	return 0;
}