#include <opencv2/opencv.hpp>
using namespace cv;

int main() {

    Mat img = imread("./assets/images/lena.jpg");
    imshow("新垣结衣", img);
    waitKey(0);

    destroyAllWindows();
    return 0;
}