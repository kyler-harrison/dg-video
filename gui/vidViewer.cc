#include "vidViewer.hh"

#include <QImage>
#include <QFileDialog>

/*
 *  Video viewer label init.
 *
 *  @param parent QWidget pointer to parent object.
 */

VidViewer::VidViewer(QWidget *parent) : QLabel(parent) {
	// TODO rm this temporary stuff
	this->setStyleSheet("background-color: blue");
	this->setFixedSize(1500, 1000);
}

/*
 *  Opens file dialog, creates a Video object with given file path.
 *
 *  @param void
 *  @return void
 */

void VidViewer::handleFile() {
	// get path from dialog 
	std::string path = QFileDialog::getOpenFileName().toStdString();
	this->video = Video(path);
	std::cout << path << "\n";

	// load and display first frame
	cv::Mat frame = this->video.getNextFrame();
	this->displayFrame(frame);
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
