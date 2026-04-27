#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::Mat image = cv::imread("input.jpg");
    cv::Mat gray;
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    cv::Mat kernel = (cv::Mat_<float>(3, 3) << 
    -2, -1,  0,                                         
    -1,  1,  1,
     0,  1,  2);
    cv::Mat result;
    cv::filter2D(gray, result, -1, kernel);
    result += 128;
    cv::namedWindow("Original Image", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Emboss Effect", cv::WINDOW_AUTOSIZE);
    cv::imshow("Original Image", image);
    cv::imshow("Emboss Effect", result);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}