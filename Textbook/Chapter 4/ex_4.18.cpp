#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    Mat src = (Mat_<uchar>(6, 6) <<
        0, 0, 0, 0, 0, 0,
        0, 0, 1, 0, 0, 0,
        0, 0, 1, 1, 0, 0,
        0, 1, 1, 1, 1, 0,
        0, 1, 1, 1, 1, 1,
        0, 0, 0, 0, 0, 0);
    Mat hitkernel = (Mat_<uchar>(3, 3) <<
        1, 0, 0,
        1, 1, 0,
        1, 1, 1);
    Mat misskernel = (Mat_<uchar>(3, 3) <<
        0, 1, 1,
        0, 0, 1,
        0, 0, 0);
    Mat combinedkernel = (Mat_<uchar>(3, 3) <<
        1, -1, -1,
        1, 1, -1,
        1, 1, 1);
    Mat image, erodekernel, complement_image, complement_erodekernel;
    erode(src, erodekernel, hitkernel);
    bitwise_not(src, complement_image);
    erode(complement_image, complement_erodekernel, misskernel);
    bitwise_and(erodekernel, complement_erodekernel, image);
    cout << "Output image without OpenCV function:" << endl << image << endl;
    morphologyEx(src, src, MORPH_HITMISS, combinedkernel);
    cout << "Output image using OpenCV function:" << endl << src << endl;
    waitKey();
    return 0;
}