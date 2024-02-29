#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    Mat src = (Mat_<uchar>(8, 6) <<
        1, 1, 1, 1, 0, 0,
        1, 1, 1, 1, 1, 1,
        1, 1, 0, 0, 1, 1,
        1, 1, 1, 0, 1, 1,
        1, 1, 0, 0, 1, 1,
        1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 0, 0,
        0, 0, 0, 0, 0, 0
        );
    cout << "Input image:" << endl << src << endl;
    namedWindow("Input image", WINDOW_FREERATIO);
    resizeWindow("Input image", 400, 300);
    imshow("Input image", src * 255);
    Mat dst;
    Mat B[] = {
        (Mat_<int>(3, 3) << -1, -1, -1, 0, 1, 0, 1, 1, 1),
        (Mat_<int>(3, 3) << 0, -1, -1, 1, 1, -1, 1, 1, 0),
        (Mat_<int>(3, 3) << 1, 0, -1, 1, 1, -1, 1, 0, -1),
        (Mat_<int>(3, 3) << 0, 1, 0, 1, 1, -1, 0, -1, -1),
        (Mat_<int>(3, 3) << 1, 1, 1, 0, 1, 0, -1, -1, -1),
        (Mat_<int>(3, 3) << 0, 1, 0, -1, 1, 1, -1, -1, 0),
        (Mat_<int>(3, 3) << -1, 0, 1, -1, 1, 1, -1, 0, 1)
    };

    for (int i = 0; i < 7; i++) {
        morphologyEx(src, dst, MORPH_HITMISS, B[i]);
        src -= dst;
    }
    cout << "Image after thinning:" << endl << src << endl;
    namedWindow("Image after thinning", WINDOW_KEEPRATIO);
    resizeWindow("Image after thinning", 400, 300);
    imshow("Image after thinning", src * 255);
    waitKey(0);
    return 0;
}