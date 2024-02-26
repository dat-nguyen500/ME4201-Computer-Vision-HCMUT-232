#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat img = (Mat_<float>(6, 7) << 1, 2, 3, 4, 2, 3, 4,
        8, 9, 10, 11, 9, 10, 11,
        15, 16, 17, 18, 16, 17, 18,
        1, 2, 3, 2, 1, 2, 2,
        7, 9, 11, 9, 8, 9, 11,
        15, 15, 16, 16, 16, 18, 17);
    Mat temp = (Mat_<float>(3, 3) << 1, 2, 3,
        8, 9, 10,
        15, 16, 17);

    Mat ncc;
    matchTemplate(img, temp, ncc, TM_CCORR_NORMED);
    cout << "NCC coefficients matrix :" << endl << ncc << endl;
    double minVal, maxVal;
    Point minLoc, maxLoc;
    minMaxLoc(ncc, &minVal, &maxVal, &minLoc, &maxLoc);
    cout << "The position of the image is similar to the template is R(" << maxLoc.y + 1 << "," << maxLoc.x + 1 << ")" << endl;
    waitKey();
    return 0;
}