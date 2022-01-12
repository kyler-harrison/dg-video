#include "video.hh"

#include <iostream>
#include <string.h>

/*
 *  Initialize main video class with a file path.
 *
 *  @param path std::string representing the file path of the video.
 */

Video::Video(std::string path) {
	this->filePath = path;
	this->tempFramePath = this->tempFramesDir + this->frameName + "0.png";  // assumes all frames will be removed when done
	this->frameIndex = 0;
	//this->vidCap = cv::VideoCapture(this->filePath);

	// TODO check for temp dirs, make if none
}

/*
 *  Gets the next video frame based on current frameIndex. Reads index from video with ffmpeg
 *  and writes the frame to temp dir. Returns cv::Mat of read frame. 
 *
 *  @return cv::Mat of image data.
 */

cv::Mat Video::getNextFrame() {
	// TODO do some input checks

	this->frameIndex++;

	// TODO check if frame already read

	// path to write temp frame to 
	this->tempFramePath = this->tempFramesDir + this->frameName + std::to_string(this->frameIndex) + ".png";

	// ffmpeg cmd
	std::string frameCommand = "ffmpeg -y -i " + this->filePath + " -vf 'select=eq(n\\," + std::to_string(this->frameIndex) + ")' -vframes 1 " + this->tempFramePath + " > " + this->ffmpegLogPath + " 2>&1";
	char *frameCommandC = const_cast<char*>(frameCommand.c_str());
	system(frameCommandC);

	// read in what ffmpeg outputted with opencv
	cv::Mat frame = cv::imread(this->tempFramePath);
	cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);  // qt uses BGR while cv uses RGB

	// TODO track created frame indices and rm later in other fun

	return frame;
}
