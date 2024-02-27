#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    uchar src_data[6][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0, 0},
        {0, 1, 1, 1, 1, 0},
        {0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0}
    };
    Mat src = Mat(6, 6, CV_8UC1, src_data);
    cout << "Original matrix:" << endl << src << endl;
    uchar kernel_data[2][2] = {
        {0, 1},
        {1, 1}
    };
    Mat kernel = Mat(2, 2, CV_8UC1, kernel_data);
    cout << "Kernel matrix:" << endl << kernel << endl;
    Mat dst;
    dilate(src, dst, kernel, Point(0, 0));
    cout << "The matrix after dilation" << endl << dst << endl;
    waitKey(0);
    return 0;
}
