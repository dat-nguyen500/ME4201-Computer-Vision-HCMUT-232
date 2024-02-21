#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat src = (Mat_<double>(5, 7) << 9, 10, 11, 10, 9, 10, 11,
        10, 9, 95, 95, 95, 10, 11,
        10, 95, 10, 11, 10, 95, 11,
        10, 9, 95, 95, 95, 13, 11,
        10, 10, 10, 10, 10, 13, 1);

    Mat sobelx, sobely;
    Sobel(src, sobelx, CV_64F, 1, 0, 3, 1, 0, BORDER_REPLICATE);
    Sobel(src, sobely, CV_64F, 0, 1, 3, 1, 0, BORDER_REPLICATE);
    cout << "Sobel x = " << endl << "" << sobelx << endl << endl;
    cout << "Sobel y = " << endl << "" << sobely << endl << endl;
    waitKey();
}