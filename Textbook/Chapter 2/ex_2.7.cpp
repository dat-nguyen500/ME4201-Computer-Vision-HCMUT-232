#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void histogram(string const& name, Mat const& Image)
{
	int bin = 255;
	int histsize[] = { bin };
	float range[] = { 0,255 };
	const float* ranges[] = { range };
	Mat hist;
	int chanel[] = { 0 };
	int hist_heigt = 256;
	Mat hist_image = Mat::zeros(hist_heigt, bin,CV_8SC3);
	calcHist(&Image, 1, chanel, Mat(), hist, 1,histsize, ranges, true, false);
	double max_val = 0;
	minMaxLoc(hist, 0, &max_val);
	for (int i = 0; i < bin; i++)
	{
		float binV = hist.at<float>(i);
		int height = cvRound(binV * hist_heigt / max_val);
		line(hist_image, Point(i, hist_heigt - height),Point(i, hist_heigt), Scalar::all(255));
	}
	imshow(name, hist_image);
}
int main(int argv, char** argc)
{
	float anh[25] = { 20,30,40,10,20,10,80,90,100,60,50,150,160,170,30,30,220,230,240,50,40,60,30,40,20 };
	Mat gray_anh = Mat(5, 5, CV_32F, anh);
	Mat gray_anh_his;
	namedWindow("Gray_old", WINDOW_FREERATIO);
	namedWindow("Gray_new_histogram", WINDOW_FREERATIO);
	gray_anh.convertTo(gray_anh, CV_8UC1);
	equalizeHist(gray_anh, gray_anh_his);
	cout << "Matrix = " << endl << "" << gray_anh << endl <<endl;
	cout << "Matrix_histogram = " << endl << "" << gray_anh_his << endl << endl;
	imshow("Gray_old", gray_anh);
	imshow("Gray_new_histogram", gray_anh_his);
	histogram("Histogram Old", gray_anh);
	histogram("Histogram New", gray_anh_his);
	waitKey();
}
