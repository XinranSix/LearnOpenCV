#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void LOG1(Mat image_input, Mat image_output);
void LOG2(Mat image_input, Mat image_output);

int main() {
    Mat img1 = imread("./assets/images/lena.png", 0); // 读取灰度图像
    if (img1.empty()) {
        cout << "读取错误" << endl;
        return -1;
    }
    imshow("img1", img1);

    Mat img2 = Mat(img1.size(), CV_8U, Scalar(0));
    Mat img3 = Mat(img1.size(), CV_8U, Scalar(0));
    LOG1(img1, img2); // LOG边缘检测
    imshow("img2", img2);

    LOG2(img1, img3); // LOG边缘检测
    imshow("img3", img3);
    waitKey();

    return 0;
}

void LOG1(Mat image_input, Mat image_output) {
    Mat temp = Mat(image_input.size(), CV_64F, Scalar(0));

    // 1、构建LOG算子
    Mat log_kernel =
        (cv::Mat_<float>(5, 5) << 0, 0, -1, 0, 0, 0, -1, -2, -1, 0, -1, -2, 16,
         -2, -1, 0, -1, -2, -1, 0, 0, 0, -1, 0, 0); // LOG的5*5大小的核
    // 2、卷积运算
    filter2D(image_input, image_output, -1, log_kernel);
}

void LOG2(Mat image_input, Mat image_output) {

    GaussianBlur(image_input, image_output, Size(5, 5), 1, 1);
    Laplacian(image_output, image_output, image_input.depth(), 3, 1, 0,
              BORDER_DEFAULT);
}