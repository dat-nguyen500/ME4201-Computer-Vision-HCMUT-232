#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    Mat src = imread("opencv.jpg", IMREAD_GRAYSCALE);
    imshow("Original image", src);
    Mat bin, dst;
    threshold(src, bin, 20, 255, THRESH_BINARY);
    src = bin.clone();
    Mat B[] = {
        (Mat_<int>(3, 3) << -1, -1, -1, 0, 1, 0, 1, 1, 1),
        (Mat_<int>(3, 3) << 0, -1, -1, 1, 1, -1, 1, 1, 0),
        (Mat_<int>(3, 3) << 1, 0, -1, 1, 1, -1, 1, 0, -1),
        (Mat_<int>(3, 3) << 0, 1, 0, 1, 1, -1, 0, -1, -1),
        (Mat_<int>(3, 3) << 1, 1, 1, 0, 1, 0, -1, -1, -1),
        (Mat_<int>(3, 3) << 0, 1, 0, -1, 1, 1, -1, -1, 0),
        (Mat_<int>(3, 3) << -1, 0, 1, -1, 1, 1, -1, 0, 1),
        (Mat_<int>(3, 3) << -1, -1, 0, -1, 1, 1, 0, 1, 1)
    };
    for (int i = 0; i < 8; i++) {
        morphologyEx(src, dst, MORPH_HITMISS, B[0]);
        src -= dst;
    }
    imshow("Thinned image", src);
    waitKey(0);
    return 0;
}