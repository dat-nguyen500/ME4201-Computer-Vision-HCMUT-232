#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main() {
    // Read the image
    cv::Mat img = cv::imread("lena.jpg", cv::IMREAD_GRAYSCALE);
    CV_Assert(!img.empty() && "file could not be read, check with os.path.exists()");


    // Thresholding to Binary Image
    cv::Mat th1, th2, th3;
    cv::threshold(img, th1, 127, 255, cv::THRESH_BINARY); //Global threshold
    cv::adaptiveThreshold(img, th2, 127, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 9, 0);
    cv::adaptiveThreshold(img, th3, 127, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 9, 0);

    // Show the images
    std::vector<cv::Mat> images = { img, th1, th2, th3 };
    std::vector<std::string> titles = { "Original Image", "Global Thresholding (v = 127)","Adaptive Mean Thresholding", "Adaptive Gaussian Thresholding" };

    for (int i = 0; i < 4; ++i) {
        cv::namedWindow(titles[i], cv::WINDOW_AUTOSIZE);
        cv::imshow(titles[i], images[i]);
    }

    cv::waitKey(0);
    return 0;
}
