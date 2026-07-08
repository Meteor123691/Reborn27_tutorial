#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    std::string path = "test.jpg";
    cv::Mat img = cv::imread(path);
    if (img.empty()) {
        std::cerr << "读取图片失败" << std::endl;
        return -1;
    }

    std::cout << "图片尺寸: " << img.cols << " x " << img.rows << std::endl;

    // 灰度图
    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::imwrite("grayscale.jpg", gray);
    std::cout << "[OK] 灰度图已保存" << std::endl;

    // 边缘检测（Canny算法）
    cv::Mat edges;
    cv::Canny(gray, edges, 50, 150);
    cv::imwrite("edges.jpg", edges);
    std::cout << "[OK] 边缘检测图已保存" << std::endl;

    // 高斯模糊
    cv::Mat blurred;
    cv::GaussianBlur(img, blurred, cv::Size(15, 15), 0);
    cv::imwrite("blurred.jpg", blurred);
    std::cout << "[OK] 模糊图已保存" << std::endl;

    std::cout << "\n完成！共生成 3 张图片，请用文件管理器查看。" << std::endl;
    return 0;
}

