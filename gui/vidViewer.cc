#include "vidViewer.hh"

#include <opencv2/opencv.hpp>
#include <QImage>

using namespace cv;

/*
 *  Video viewer label. 
 *  NOTE i think i should move all image processing to another dir
 *  and use this purely as the gui aspect, so gui would take in vid
 *  path and send off to image processing land, and then the data to
 *  display is returned to the gui and converted to QT image display
 */

VidViewer::VidViewer(QWidget *parent) : QLabel(parent) {
	// TODO temporary stuff
	this->setStyleSheet("background-color: blue");
	this->setFixedSize(1500, 1000);

	// load in image with opencv and display with qt (also temporary)
	Mat img = imread("im.jpg");
	cvtColor(img, img, COLOR_BGR2RGB);  // qt uses BGR while cv uses RGB
	QImage imdisplay((unsigned char *) img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
	this->setPixmap(QPixmap::fromImage(imdisplay));
}
