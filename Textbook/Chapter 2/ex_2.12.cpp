#include "opencv2/opencv.hpp"
#include <opencv2/core/mat.hpp>
#include <iostream>

using namespace cv;
using std::cout;
using std::endl;

int main(int argv, char** argc)
{
	Mat M = (Mat_<uint8_t>(6, 7) << 1, 2, 10, 40, 5, 6, 7,
										8, 10, 12, 11, 40, 13, 14,
										11, 40, 40, 40, 9, 40, 12,
										8, 10, 40, 10, 10, 10, 15,
										10, 2, 4, 40, 10, 7, 8,
										1, 2, 10, 4, 5, 10, 7);
	cout << "Original Matrix" << endl << "" << M << endl;
	copyMakeBorder(M, M, 1, 1, 1, 1, BORDER_CONSTANT);
	//local threshold

	adaptiveThreshold(M, M, 1, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 3, 0);
	cout << "Matrix after adaptiveThreshold" << endl << "" << M;

	return 0;
}
