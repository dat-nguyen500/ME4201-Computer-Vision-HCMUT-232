#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    float sigma = 0.3;
    Mat src = (Mat_<float>(5, 5) << 4, 2, 3, 4, 5,
        8, 5, 10, 11, 12,
        15, 16, 6, 18, 18,
        22, 23, 24, 7, 26,
        29, 30, 31, 32, 8);
    Mat dst;
    GaussianBlur(src, dst, Size(3, 3), sigma, sigma, BORDER_CONSTANT);
    cout << "Image Matrix" << endl << "" << src << endl;
    cout << "Gaussian Blur" << endl << "" << dst << endl;
    waitKey();
}