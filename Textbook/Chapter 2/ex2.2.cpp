#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace std;
using namespace cv;
void mouseEvent(int evt, int x, int y, int flags, void* param)
{
	Mat* rgb = (Mat*)param;
	if (evt == EVENT_LBUTTONDOWN)
	{
		printf("%d %d: %d, %d, %d\n",
			x, y,
			(int)(*rgb).at<Vec3b>(y, x)[0],
			(int)(*rgb).at<Vec3b>(y, x)[1],
			(int)(*rgb).at<Vec3b>(y, x)[2]);
	}
}
int main(int argc, char** argv)
{
	// Read image from file
	Mat img = imread("Machovka_Happy_fish.PNG");
	//if fail to read the image
	if (img.empty())
	{
		cout << "Error loading the image" << endl;
		return -1;
	}
	//Create a window
	namedWindow("My Window", 1);
	//set the callback function for any mouse event
	setMouseCallback("My Window", mouseEvent, &img);
	//show the image
	imshow("My Window", img);
	// Wait until user press some key
	waitKey(0);
	return 0;
}
