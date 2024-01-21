#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	float src_data[] = { 130,200,18 };
	Mat src = Mat(1, 1, CV_32FC3, src_data);
	cout << "src" << endl << "" << src << endl;
	Mat HSV;
	cvtColor(src, HSV, COLOR_BGR2HSV);
	cout << "HSV" << endl << "" << HSV << endl;
}
