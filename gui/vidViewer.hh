#include "../cv/video.hh"

#include <QLabel>

/*
 *  Main video viewer label. Handles all gui aspects of viewing images
 *  and communicates with external cv dir. Depends on a Video object for 
 *  image processing.
 */

class VidViewer : public QLabel {
	private:
		Video *video;
		bool vidOpen = false;

	public:
		VidViewer(QWidget *parent = nullptr);
		void handleFile();
		void loadFrame();
		void displayFrame(cv::Mat frame);
		void cleanup();
};
