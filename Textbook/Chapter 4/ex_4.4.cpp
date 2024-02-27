#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat image, dst;
    image = imread("circles.png", 1);
    int erosion_size = 6;
    Mat element = getStructuringElement(MORPH_ERODE, Size(2 * erosion_size + 1, 2 * erosion_size + 1), Point(erosion_size, erosion_size));
    erode(image, dst, element);
    namedWindow("Display window", WINDOW_AUTOSIZE);
    imshow("Display window", image);
    namedWindow("Result window", WINDOW_AUTOSIZE);
    imshow("Result window", dst);
    waitKey();
    return 0;
}
