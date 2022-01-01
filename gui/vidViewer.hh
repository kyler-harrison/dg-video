#include "../cv/video.hh"

#include <QLabel>

/*
 *  Main video viewer label. Handles all gui aspects of viewing images. 
 *  Depends on a Video object to do any image processing.
 */

class VidViewer : public QLabel {
	private:
		Video video;

	public:
		VidViewer(QWidget *parent = nullptr);
		void handleFile();
		void loadFrame();
		void displayFrame(cv::Mat frame);
};
