#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    // Define source data
    uchar src_data[6][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0, 0},
        {0, 1, 1, 1, 1, 0},
        {0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0}
    };
    // Convert source data to a Mat
    Mat src = Mat(6, 6, CV_8UC1, src_data);

    cout << "Original matrix:" << endl << src << endl;

    // Define kernel data
    uchar kernel_data[2][2] = {
        {0, 1},
        {1, 1}
    };
    // Convert kernel data to a Mat
    Mat kernel = Mat(2, 2, CV_8UC1, kernel_data);

    cout << "Kernel matrix:" << endl << kernel << endl;

    Mat dst;
    // Perform erosion
    erode(src, dst, kernel, Point(0, 0));

    cout << "The matrix after erosion" << endl << dst << endl;

    waitKey(0);
    return 0;
}
