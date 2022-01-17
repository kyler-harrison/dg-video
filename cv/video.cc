#include "video.hh"

#include <stdio.h>

/*
 *  Initialize main video class with a file path.
 *
 *  @param path std::string representing the file path of the video.
 */

Video::Video(std::string path) {
	this->filePath = path;

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
 *  Gets the number of frames in the video.
 *
 *  @return bool false if something failed, true if value was found successfully.
 */

bool Video::getNumFrames() {
	std::string countFramesCmd = "ffprobe -v error -select_streams v:0 -count_frames -show_entries stream=nb_read_frames -of csv=p=0 " + this->filePath + " > " + this->countFramesPath + " 2>&1";
	std::string rmCountFramesCmd = "rm -rf " + this->countFramesPath;

	const char *countFramesCmdc = countFramesCmd.c_str();
	const char *rmCountFramesCmdc = rmCountFramesCmd.c_str(); 

	// dump number of frames to file
	system(countFramesCmdc);

	// read that number back in
	FILE *fptr = fopen(this->countFramesPath.c_str(), "r");

	if (fptr == NULL) {
		return false;
	}

	int tempNumFrames;
	int valsRead = fscanf(fptr, "%d", &tempNumFrames);

	if (valsRead != 1) {
		return false;
	}

	this->numFrames = tempNumFrames;

	// rm the temp file contaning frame count
	system(rmCountFramesCmdc);

	return true;
}

/*
 *  Gets a frame based on the current frameIndex. Reads index from video 
 *  with ffmpeg and writes the frame to temp dir. Returns cv::Mat of read frame. 
 *
 *  @return cv::Mat of image data
 */

cv::Mat Video::loadFrame() {
	// path to write temp frame to 
	this->tempFramePath = this->tempFramesDir + this->frameName + std::to_string(this->frameIndex) + ".png";

	// ffmpeg cmd to extract frame
	std::string frameCommand = "ffmpeg -y -i " + this->filePath + " -vf 'select=eq(n\\," + std::to_string(this->frameIndex) + ")' -vframes 1 " + this->tempFramePath + " > " + this->logDir + this->logName + " 2>&1";
	const char *frameCommandC = frameCommand.c_str();
	system(frameCommandC);

	// read in what ffmpeg outputted with opencv
	cv::Mat frame = cv::imread(this->tempFramePath);

	if (!frame.empty()) {
		cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);  // qt uses BGR while cv uses RGB
	}

	return frame;
}

/*
 *  Gets the next video frame based on current frameIndex. 
 *
 *  @return cv::Mat of image data
 */

cv::Mat Video::getNextFrame() {
	// TODO do some input checks

	// TODO track created frame indices 

	// TODO check if frame already read and check for valid next idx

	if (this->frameIndex + 1 < this->numFrames) {
		this->frameIndex++;
		return this->loadFrame();

	} else {
		cv::Mat emptyFrame;
		return emptyFrame;
	}
}

/*
 *  Gets the previous video frame based on current frameIndex. 
 *
 *  @return cv::Mat of image data
 */

cv::Mat Video::getPrevFrame() {
	// TODO same stuff as getNextFrame()

	if (this->frameIndex - 1 >= 0) {
		this->frameIndex--;
		return this->loadFrame();

	} else {
		cv::Mat emptyFrame;
		return emptyFrame;
	}
}

/*
 *  Loads the frame at index frameNum - 1 (display is not index).
 *
 *  @param int frameNum user-inputted frame number to load
 *  @return cv::Mat of image data
 */

cv::Mat Video::seekFrame(int frameNum) {
	int idx = frameNum - 1;

	if ((idx != this->frameIndex) && (idx >= 0) && (idx < this->numFrames)) {
		this->frameIndex = idx;
		return this->loadFrame();

	} else {
		cv::Mat emptyFrame;
		return emptyFrame;
	}
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

