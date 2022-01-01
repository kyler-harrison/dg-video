#include <opencv2/opencv.hpp>

class Video {
	public:
		Video();
		cv::Mat getFrame(const char *filePath);
};
