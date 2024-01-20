#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main(int argv, char** argc)
{
	//Original file
	Mat original = imread("threshold.jpg", IMREAD_GRAYSCALE);
	//Modified file
	Mat modify = imread("threshold.jpg", IMREAD_GRAYSCALE);
	//Accessing row
	for (int i = 0; i < modify.rows; i++)
	{
		//Accessing column
		for (int k = 0; k < modify.cols; k++)
		{
			//Pixel with value from 10 to 40 
			if (modify.at<uint8_t>(i, k) < 210 && modify.at<uint8_t>(i, k) > 190)
				modify.at<uint8_t>(i, k) = 0; //Will be white
			else
				modify.at<uint8_t>(i, k) = 255; //Other will be black
		}
	}
	imshow("Original", original);
	imshow("Theshold", modify);
	waitKey(0);
	return 0;
}
