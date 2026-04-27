#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat image = imread("input.jpg");
    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);
    Mat kernel = (Mat_<float>(3, 3) << 
        -1, -1,  0,
        -1,  0,  1,
         0,  1,  1);
    Mat emboss;
    filter2D(gray, emboss, -1, kernel);
    emboss = emboss + 128;
    namedWindow("Original", WINDOW_AUTOSIZE);
    namedWindow("Emboss Effect", WINDOW_AUTOSIZE);
    imshow("Original", image);
    imshow("Emboss Effect", emboss);
    imwrite("emboss_result.jpg", emboss);
    waitKey(0);
    destroyAllWindows();

    return 0;
}