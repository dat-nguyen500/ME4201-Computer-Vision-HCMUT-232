#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat imageSrc = imread("lena.jpg", IMREAD_COLOR);
    Mat imageDst;
    Mat kernel = Mat::ones(Size(3, 3), CV_32F) / (float)9;
    filter2D(imageSrc, imageDst, imageSrc.depth(), kernel, Point(-1, -1), 0, 0);
    imshow("Image Src", imageSrc);
    imshow("Image Dst", imageDst);
    waitKey(0);
}