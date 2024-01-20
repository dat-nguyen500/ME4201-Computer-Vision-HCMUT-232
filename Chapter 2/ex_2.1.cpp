#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"
using namespace cv;
using namespace std;
int main()
{
	Mat src1 = imread("lena.jpg", IMREAD_COLOR);
	namedWindow("Original image", WINDOW_AUTOSIZE);
	imshow("Original image", src1);
	Mat gray;
	cvtColor(src1, gray, COLOR_BGR2GRAY);
	namedWindow("Gray image", WINDOW_AUTOSIZE);
	imshow("Gray image", gray);
	// know the number of channels the image has
	cout << "original image channels: " << src1.channels() << "gray image channels: " << gray.channels() << endl;
	// ******************* READ the Pixel intensity *********************
	// single channel grey scale image (type 8UC1) and pixel coordinates x=5 and y=2
	// by convention, {row number = y} and {column number = x}
	// intensity.val[0] contains a value from 0 to 255
	Scalar intensity1 = gray.at<uchar>(2, 5);
	cout << "Intensity gray at (2,5) = " << endl << " " << intensity1.val[0] << endl << endl;
	// 3 channel image with BGR color (type 8UC3)
	// the values can be stored in "int" or in "uchar". Here int is used.
	Vec3b intensity2 = src1.at<Vec3b>(10, 15);
		int blue = intensity2.val[0];
	int green = intensity2.val[1];
	int red = intensity2.val[2];
	cout << "Intensity at (10,15) = " << endl << "blue= " << blue << "green= " << green << "red= " << red << endl
		<< endl;
	// ******************* WRITE to Pixel intensity **********************
	// This is an example in OpenCV 2.4.6.0 documentation 
	for (int i = 0; i < gray.rows; i++)
	{
		for (int j = 0; j < gray.cols; j++)
		{
			gray.at<uchar>(j, i) = gray.at<uchar>(j, i) + 100;
		}
	}
	namedWindow("Gray image modify", WINDOW_AUTOSIZE);
	imshow("Gray image modify", gray);
	// Modify the pixels of the BGR image
	for (int i = 100; i < src1.rows; i++)
	{
		for (int j = 100; j < src1.cols; j++)
		{
			src1.at<Vec3b>(i, j)[0] = src1.at<Vec3b>(i, j)[0] + 10;
			src1.at<Vec3b>(i, j)[1] = src1.at<Vec3b>(i, j)[1] + 10;
			src1.at<Vec3b>(i, j)[2] = src1.at<Vec3b>(i, j)[2] + 10;
		}
	}
	namedWindow("Modify RGB pixel", WINDOW_AUTOSIZE);
	imshow("Modify RGB pixel", src1);
	waitKey(0);
	return 0;
}
