#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	uint16_t input_m[48] = {
		10, 10, 10, 10, 200, 200, 200, 200,
		10, 10, 10, 10, 200, 200, 200, 200,
		10, 10, 10, 10, 200, 200, 200, 200,
		10, 10, 10, 10, 200, 200, 200, 200,
		10, 10, 10, 10, 200, 200, 200, 200,
		10, 10, 10, 10, 200, 200, 200, 200
	};
	Mat input = Mat(6, 8, CV_16U, input_m);
	Mat output;
	input.convertTo(input, CV_8U);
	output.convertTo(output, CV_8U);
	GaussianBlur(input, input, Size(3, 3), 1, 0, BORDER_REFLECT_101);
	Canny(input, output, 50, 100, 3);
	cout << "Imput matrix:" << endl << "" << input << endl;
	cout << "Canny result:" << endl << "" << output;
	waitKey();
	return 0;
}