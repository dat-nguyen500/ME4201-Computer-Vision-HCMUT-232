#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat src = imread("canny.jpg", IMREAD_GRAYSCALE);

    GaussianBlur(src, src, Size(3, 3), 1, 1, 0);
    src.convertTo(src, CV_64FC1);
    Mat filx, fily;
    Sobel(src, filx, src.depth(), 1, 0, 3, 2, 1, 1);
    Sobel(src, fily, src.depth(), 0, 1, 3, 2, 1, 1);

    imshow("Sobel x", filx);
    imshow("Sobel y", fily);

    waitKey();
    return 0;
}