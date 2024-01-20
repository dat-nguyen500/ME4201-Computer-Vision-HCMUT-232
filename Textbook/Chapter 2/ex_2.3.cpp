#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace std;
using namespace cv;
int main(int argc, char** argv)
{
	//Read original image
	Mat src = imread("lena.jpg");

	if (!src.data)
	{
		cout << "Error loading image" << endl;
		return -1;
	}

	//Create a window
	namedWindow("My Window", 1);

	//Create trackbar to change the brightness and the contrast
	int iSliderValue1 = 50;
	createTrackbar("Brightness", "My Window", &iSliderValue1, 100);
	int iSliderValue2 = 50;
	createTrackbar("Contrast", "My Window", &iSliderValue2, 100);

	while (true)
	{
		//Change the brightness and contrast of the image
		Mat dst;
		int iBrightness = iSliderValue1 - 50;
		double dContrast = iSliderValue2/50.0;
		src.convertTo(dst, -1, dContrast, iBrightness);
		//show the brightness and contrast adjusted image
		imshow("My Window", dst);

		
	}

	return 0;
}
