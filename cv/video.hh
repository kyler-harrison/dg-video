#include <opencv2/opencv.hpp>

/*
 *  Main video handler class.
 */

class Video {
	public:
		Video(std::string path = "");
		std::string filePath;
		cv::Mat getNextFrame();
};
