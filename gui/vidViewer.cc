#include "vidViewer.hh"

#include <iostream>
#include <QImage>
#include <QFileDialog>

/*
 *  Video viewer label init.
 *
 *  @param parent QWidget* parent object 
 */

VidViewer::VidViewer(QWidget *parent) : QLabel(parent) {
	// temporary stuff
	this->setStyleSheet("background-color: blue");
	this->setFixedSize(1500, 1000);
}

/*
 *  Opens file dialog and defines a Video object with given file path.
 *
 *  @param void
 *  @return void
 */

void VidViewer::handleFile() {
	// get path from dialog 
	std::string path = QFileDialog::getOpenFileName().toStdString();
	this->video = new Video(path);
	bool readSuccess = this->video->getNumFrames();

	if (!readSuccess || this->video->numFrames <= 0) {
		// TODO clean error handling, propagate through
		return;
	}

	this->vidOpen = true;

	// load and display first frame
	cv::Mat frame = this->video->getNextFrame();
	this->displayFrame(frame);
	emit vidLoaded();
}

/*
 *  Displays an image on the gui.
 *
 *  @param frame opencv Mat object of the frame to display.
 *  @return void
 */

void VidViewer::displayFrame(cv::Mat frame) {
	// convert frame's data to QImage
	QImage imdisplay((unsigned char *) frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
	this->setPixmap(QPixmap::fromImage(imdisplay));
}

/*
 *  Handles prev frame click by calling Video's getPrevFrame (TODO implement) 
 *
 *  @return void
 */

void VidViewer::handlePrev() {
	std::cout << "back clicked\n";
}

/*
 *  Handles next frame click by calling Video's getNextFrame.
 *
 *  @return void
 */

void VidViewer::handleNext() {
	if (this->vidOpen){
		cv::Mat frame = this->video->getNextFrame();

		if (!frame.empty()) {
			this->displayFrame(frame);
		}
	}
}

/*
 *  Cleanup on window close.
 *
 *  @return void
 */

void VidViewer::cleanup() {
	if (this->vidOpen) {
		this->video->cleanup();
	}
}
