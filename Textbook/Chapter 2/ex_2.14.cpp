#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat source = (Mat_<uint8_t>(5, 5) << 20, 30, 40, 10, 20,
        10, 80, 90, 100, 60,
        50, 150, 160, 170, 30,
        30, 220, 230, 240, 50,
        40, 60, 30, 40, 20);
    Mat dst;
    double thresh = 0, maxValue = 255;
    long double thres = threshold(source, dst, thresh, maxValue, THRESH_OTSU);

    cout << "Otsu Threshold T = " << thres << endl;
    cout << "OUTPUT" << endl << "" << dst << endl;

    waitKey(0);
    return 0;
}
