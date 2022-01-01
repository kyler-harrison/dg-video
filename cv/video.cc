#include "video.hh"

/*
 *  Initialize main video class with a file path.
 *
 *  @param path std::string representing the file path of the video.
 */

Video::Video(std::string path) {
	this->filePath = path;
}

cv::Mat Video::getNextFrame() {
	//cv::Mat img = cv::imread("im.jpg");
	std::cout << "in Video path = " << this->filePath << "\n";
	cv::Mat img = cv::imread(this->filePath);
	cv::cvtColor(img, img, cv::COLOR_BGR2RGB);  // qt uses BGR while cv uses RGB
	return img;
}
