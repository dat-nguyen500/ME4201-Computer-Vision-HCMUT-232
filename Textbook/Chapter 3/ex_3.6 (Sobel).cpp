#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat src = (Mat_<double>(6, 7) << 9, 10, 11, 9, 9, 10, 11,
        10, 40, 40, 40, 40, 40, 11,
        10, 40, 40, 40, 40, 40, 11,
        10, 40, 40, 40, 40, 40, 11,
        10, 40, 40, 40, 40, 40, 11,
        10, 10, 10, 10, 10, 10, 10);

    Mat sobelx, sobely;
    Sobel(src, sobelx, CV_64F, 1, 0, 3, 1, 0, BORDER_CONSTANT);
    Sobel(src, sobely, CV_64F, 0, 1, 3, 1, 0, BORDER_CONSTANT);
    cout << "Sobel x = " << endl << "" << sobelx << endl << endl;
    cout << "Sobel y = " << endl << "" << sobely << endl << endl;
    waitKey();
}