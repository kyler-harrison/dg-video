#include "video.hh"

Video::Video() {
}

cv::Mat Video::getFrame(const char *filePath) {
	cv::Mat img = cv::imread("im.jpg");
	cv::cvtColor(img, img, cv::COLOR_BGR2RGB);  // qt uses BGR while cv uses RGB
	return img;
}
