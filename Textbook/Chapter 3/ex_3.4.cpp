#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat output, image;
    float image_data[6][7] = {
        1, 2, 3, 4, 5, 6, 7,
        8, 9, 10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21,
        22, 23, 24, 25, 26, 27, 28,
        29, 30, 31, 32, 33, 34, 35,
        36, 37, 38, 39, 40, 41, 42
    };
    Mat kernel = Mat::ones(Size(5, 5), CV_32F)/25;
    image = Mat(6, 7, CV_32F, image_data);


    cout << "filter2D command result:" << endl;
    filter2D(image, output, image.depth(), kernel, Point(-1, -1), 0, 0);
    cout << output << endl;
    waitKey();
}
