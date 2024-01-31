#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    float Image_Data[4][4] =
    {
        {1,2,3,4},
        {8,10,10,11},
        {9,8,9,18 },
        {22,23,24,9}
    };
    float Kernel_Convolution[3][3] =
    {
        {9,8,7},
        {6,5,4},
        {3,2,1}
    };
    Mat image(Size(4, 4), CV_32F, Image_Data);
    Mat kernel(Size(3, 3), CV_32F, Kernel_Convolution);

    Mat output = Mat::zeros(4, 4, CV_32F);
    cout << "Filter2D command result: " << endl;
    filter2D(image, output, image.depth(), kernel, Point(1, 1), 0, 0);
    cout << output << endl;
    return 0;
}
