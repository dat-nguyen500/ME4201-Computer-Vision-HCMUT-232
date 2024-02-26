#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat src = imread("shape.jpg", IMREAD_GRAYSCALE);

    GaussianBlur(src, src, Size(3, 3), 1, 1, 0);
    src.convertTo(src, CV_64FC1);

    Mat Sobelx = (Mat_<float>(3, 3) << 1, 0, -1,
        2, 0, -2,
        1, 0, -1);
    Mat Sobely = (Mat_<float>(3, 3) << -1, -2, -1,
        0, 0, 0,
        1, 2, 1);

    Mat filx, fily;
    filter2D(src, filx, src.depth(), Sobelx, Point(-1, -1), 0, 0);
    filter2D(src, fily, src.depth(), Sobely, Point(-1, -1), 0, 0);

    imshow("Sobel x", filx);
    imshow("Sobel y", fily);

    waitKey();
    return 0;
}
