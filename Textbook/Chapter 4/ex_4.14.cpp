#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat src = imread("a.png");
    threshold(src, src, 50, 255, THRESH_BINARY);
    imshow("Source image", src);

    Mat h_line;
    Mat h_element = getStructuringElement(MORPH_ERODE, Size(50, 1), Point(-1, -1));
    morphologyEx(src, h_line, MORPH_OPEN, h_element, Point(-1, -1), 1, 0, 0);

    Mat v_line;
    Mat v_element = getStructuringElement(MORPH_ERODE, Size(1, 50), Point(-1, -1));
    morphologyEx(src, v_line, MORPH_OPEN, v_element, Point(-1, -1), 1, 0, 0);

    Mat hv_line;
    bitwise_xor(h_line, v_line, hv_line);
    imshow("Horizontal and vertical lines", hv_line);

    Mat square;
    Mat sq_element = getStructuringElement(MORPH_RECT, Size(19, 19), Point(-1, -1));
    morphologyEx(src, square, MORPH_OPEN, sq_element, Point(-1, -1), 1, 0, 0);
    imshow("Squares", square);

    Mat square_circle;
    Mat sq_ci_element = getStructuringElement(MORPH_RECT, Size(11, 11), Point(-1, -1));
    morphologyEx(src, square_circle, MORPH_OPEN, sq_ci_element, Point(-1, -1), 1, 0, 0);

    Mat circle;
    bitwise_xor(square, square_circle, circle);
    medianBlur(circle, circle, 3);
    imshow("Circles", circle);

    Mat diag_line;
    bitwise_or(square_circle, h_line, diag_line);
    bitwise_xor(src, diag_line, diag_line);
    medianBlur(diag_line, diag_line, 5);
    imshow("Diagonal and vertical lines", diag_line);
    waitKey(0);
    return 0;
}
