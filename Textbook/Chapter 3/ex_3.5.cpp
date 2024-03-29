#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat output, image;
    float image_data[10][11] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 2, 3, 4, 5, 6, 7, 0, 0,
        0, 0, 8, 9, 10, 11, 12, 13, 14, 0, 0,
        0, 0, 15, 16, 17, 18, 19, 20, 21, 0, 0,
        0, 0, 22, 23, 24, 25, 26, 27, 28, 0, 0,
        0, 0, 29, 30, 31, 32, 33, 34, 35, 0, 0,
        0, 0, 36, 37, 38, 39, 40, 41, 42, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    image = Mat(10, 11, CV_32F, image_data);


    cout << "Input:" << endl << image << endl;
    medianBlur(image, output, 5);
    cout << "Result:" << endl << output << endl;
    waitKey();
}
