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

	// rm temp dir if already exists, create temp dir
	std::string rmCmd = "rm -rf " + this->tempDir;
	std::string tmpDirCmd = "mkdir -p " + this->tempDir;
	std::string logDirCmd = "mkdir -p " + this->logDir;
	std::string framesDirCmd = "mkdir -p " + this->tempFramesDir;

	const char *rmCmdc = rmCmd.c_str();
	const char *tmpDirCmdc = tmpDirCmd.c_str();
	const char *logDirCmdc = logDirCmd.c_str();
	const char *framesDirCmdc = framesDirCmd.c_str();

	system(rmCmdc);
	system(tmpDirCmdc);
	system(logDirCmdc);
	system(framesDirCmdc);
}

/*
 *  Gets the next video frame based on current frameIndex. Reads index from video with ffmpeg
 *  and writes the frame to temp dir. Returns cv::Mat of read frame. 
 *
 *  @return cv::Mat of image data.
 */

cv::Mat Video::getNextFrame() {
	// TODO do some input checks

	// TODO check if frame already read

	// path to write temp frame to 
	this->tempFramePath = this->tempFramesDir + this->frameName + std::to_string(this->frameIndex) + ".png";

	// ffmpeg cmd
	std::string frameCommand = "ffmpeg -y -i " + this->filePath + " -vf 'select=eq(n\\," + std::to_string(this->frameIndex) + ")' -vframes 1 " + this->tempFramePath + " > " + this->logDir + this->logName + " 2>&1";
	const char *frameCommandC = frameCommand.c_str();
	system(frameCommandC);

	// read in what ffmpeg outputted with opencv
	cv::Mat frame = cv::imread(this->tempFramePath);
	cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);  // qt uses BGR while cv uses RGB

	// TODO track created frame indices 

	this->frameIndex++;

	return frame;
}

/*
 *  Remove the temp directory.
 *
 *  @return void
 */

void Video::cleanup() {
	std::string rmCmd = "rm -rf " + this->tempDir;
	const char *rmCmdc = rmCmd.c_str();
	system(rmCmdc);
}

