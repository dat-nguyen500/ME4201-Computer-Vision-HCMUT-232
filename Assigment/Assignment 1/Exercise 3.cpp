#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat img = (Mat_<float>(4, 6) << 1, 2, 3, 3, 10, 11,
        3, 10, 11, 16, 11, 18,
        16, 11, 18, 22, 24, 25,
        23, 24, 25, 25, 4, 7);
    Mat temp = (Mat_<float>(3, 3) << 3, 10, 11,
        16, 11, 18,
        23, 24, 25);

    Mat ncc;
    matchTemplate(img, temp, ncc, TM_CCORR_NORMED);
    cout << "NCC coefficients matrix :" << endl << ncc << endl;
    double minVal, maxVal;
    Point minLoc, maxLoc;
    minMaxLoc(ncc, &minVal, &maxVal, &minLoc, &maxLoc);
    cout << "The position of the image is similar to the template is R(" << maxLoc.y + 1 << "," << maxLoc.x + 1 << ")" << endl;
    Mat bin; 
    threshold(ncc, bin, 0.98, 1, THRESH_BINARY);
    vector<Point> locs;
    findNonZero(bin, locs); 
    cout << "The positions with values greater than 0.98 are:" << endl;
    for (auto loc : locs) {
        cout << "R(" << loc.y + 1 << "," << loc.x + 1 << ")\t";
    }
    cout << "\nObtain thresholding the NCC coefficients matrix" << endl << "" << bin << endl;
    waitKey();
}
