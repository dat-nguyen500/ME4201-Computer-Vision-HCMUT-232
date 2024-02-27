#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat image;
	image = imread("canny.jpg", 1);
	namedWindow("Display window", WINDOW_AUTOSIZE);
	imshow("Display window", image);
	Mat gray;
	cvtColor(image, gray, COLOR_BGR2GRAY);
	Canny(gray, gray, 100, 200, 3);
	/// Find contours   
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	RNG rng(12345);
	findContours(gray, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
	/// Draw contours
	Mat drawing = Mat::zeros(gray.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
	}
	imshow("Result window", drawing);
	waitKey(0);
	
	return 0;
}