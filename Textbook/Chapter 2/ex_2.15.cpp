#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main() {
    // Read the image from file
    Mat img = imread("photo.jpg", IMREAD_GRAYSCALE);

    if (img.empty()) {
        std::cerr << "Unable to read the image." << std::endl;
        return -1;
    }

    // Calculate the global threshold value according to the Otsu method
    double otsu_threshold = threshold(img, img, 0, 255, THRESH_BINARY | THRESH_OTSU);

    // Using the Otsu result to threshold the image
    Mat thresholded_img;
    threshold(img, thresholded_img, otsu_threshold, 255, THRESH_BINARY);

    // Drawing histogram of the image
    Mat hist;
    int histSize = 256;
    float range[] = { 0, 255 };  
    const float* histRange = { range };
    calcHist(&img, 1, 0, Mat(), hist, 1, &histSize, &histRange, true, false);

    int hist_w = 512, hist_h = 400;
    int bin_w = cvRound((double)hist_w / histSize);

    Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));

    normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

    for (int i = 1; i < histSize; i++) {
        line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(hist.at<float>(i - 1))),
            Point(bin_w * (i), hist_h - cvRound(hist.at<float>(i))),
            Scalar(0, 0, 255), 2, 8, 0);
    }

    // Ouput the Otsu thresholding value
    std::cout << "Otsu Threshold: " << otsu_threshold << std::endl;

    // Output the image and histogram
    namedWindow("Original Image", WINDOW_AUTOSIZE);
    imshow("Original Image", img);

    namedWindow("Otsu Thresholded Image", WINDOW_AUTOSIZE);
    imshow("Otsu Thresholded Image", thresholded_img);

    namedWindow("Histogram", WINDOW_AUTOSIZE);
    imshow("Histogram", histImage);

    waitKey(0);

    return 0;
}
