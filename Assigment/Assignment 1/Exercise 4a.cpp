#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    float sigma = 0.3;
    Mat src = (Mat_<float>(5, 7) << 9, 10, 11, 10, 9, 10, 11,
        10, 9, 95, 95, 95, 10, 11,
        10, 95, 10, 11, 10, 95, 11,
        10, 9, 95, 95, 95, 13, 11,
        10, 10, 10, 10, 10, 13, 11);
    Mat dst;
    GaussianBlur(src, dst, Size(3, 3), sigma, sigma, BORDER_REPLICATE);
    cout << "Image Matrix" << endl << "" << src << endl;
    cout << "Gaussian Blur" << endl << "" << dst << endl;
    waitKey();
}
