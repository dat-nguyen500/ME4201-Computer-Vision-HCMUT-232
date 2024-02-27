#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat src, dst;
    src = imread("bird.jpg", 0);
    int erosion_size = 1;
    Mat element = getStructuringElement(MORPH_ERODE,
        Size(2 * erosion_size + 1, 2 * erosion_size + 1),
        Point(erosion_size, erosion_size));
    erode(src, dst, element);
    subtract(src, dst, dst);
    imshow("Display window", src);
    imshow("Result window", dst);
    waitKey(0);
    return 0;
}
