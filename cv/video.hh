#include <opencv2/opencv.hpp>

/*
 *  Main video handler class.
 */

class Video {
	private:
		std::string filePath = "";  // input file
		std::string tempFramePath = "";  // where to keep temp video frames
		std::string tempDir = "./dgvidTemp/";
		std::string tempFramesDir = tempDir + "frames/";  
		std::string frameName = "frame";
		std::string logDir = tempDir + "logs/";  
		std::string logName = "log.txt";  
		std::string countFramesPath = tempDir + "numFrames.txt";  

	public:
		int frameIndex = -1;
		int numFrames = 0;
		Video(std::string path = "");
		cv::Mat getNextFrame();
		void cleanup();
		bool getNumFrames();
};
