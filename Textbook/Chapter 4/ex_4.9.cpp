#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat src, dst;
    src = imread("beans.jpg", 1);
    int dilation_size = 6;
    Mat element = getStructuringElement(MORPH_DILATE, Size(2 * dilation_size + 1, 2 * dilation_size + 1), Point(dilation_size, dilation_size));
    dilate(src, dst, element);
    imshow("Display window", src);
    imshow("Result window", dst);
    waitKey(0);
    return 0;
}