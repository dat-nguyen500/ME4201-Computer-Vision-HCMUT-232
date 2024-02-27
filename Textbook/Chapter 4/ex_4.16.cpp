#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    char data[] = {
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 0, 0, 0,
        0, 1, 1, 1, 1, 1, 1, 0,
        0, 0, 1, 1, 1, 0, 1, 0,
        0, 1, 1, 1, 1, 1, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 0
    };
    Mat image = Mat(6, 8, CV_8UC1, data);
    Mat kernel = getStructuringElement(MORPH_CROSS, Size(3, 3), Point(-1, -1));
    Mat dst;
    cout << "Opening using morphologyEx of OpenCV:" << endl;
    morphologyEx(image, dst, MORPH_CLOSE, kernel);
    cout << dst << endl;
    Mat dst2;
    dilate(image, dst2, kernel);
    cout << "Dilate:" << endl;
    cout << dst2 << endl;
    erode(dst2, dst2, kernel);
    cout << "Erode:" << endl;
    cout << dst2 << endl;
    waitKey(0);
    return 0;
}
