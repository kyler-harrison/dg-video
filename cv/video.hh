#include <opencv2/opencv.hpp>

/*
 *  Main video handler class.
 */

class Video {
	private:
		int frameIndex = 0;
		std::string filePath = "";  // input file
		std::string tempFramePath = "";  // where to keep temp video frames
		std::string tempDir = "./dgvidTemp/";
		std::string tempFramesDir = tempDir + "frames/";  
		std::string frameName = "frame";
		std::string logDir = tempDir + "logs/";  
		std::string logName = "log.txt";  

	public:
		Video(std::string path = "");
		cv::Mat getNextFrame();
		void cleanup();
};
