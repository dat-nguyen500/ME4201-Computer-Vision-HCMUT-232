#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    float src[4][4] =
    {
        1,2,3,4,
        8,2,10,11,
        15,16,10,18,
        2,23,24,25
    };
    float kernel[3][3] =
    {
        9,8,7,
        6,5,4,
        3,2,1
    };
    Mat source(Size(4, 4), CV_32F, src);
    Mat ker(Size(3, 3), CV_32F, kernel);
    Mat dst;

    filter2D(source, dst, -1, ker, Point(1, 2), 0, 0);
    cout << "Original matrix: " << endl << source << endl;
    cout << "Kernel: " << endl << ker << endl;
    cout << "Convolution calculation: " << endl << dst << endl;
    
    return 0;
}
