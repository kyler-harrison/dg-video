#pragma once
#include "../cv/video.hh"

#include <QLabel>

/*
 *  Main video viewer label. Handles all gui aspects of viewing images
 *  and communicates with external cv dir. Depends on a Video object for 
 *  image processing.
 */

class VidViewer : public QLabel {
	Q_OBJECT

	private:
		bool vidOpen = false;

	public:
		VidViewer(QWidget *parent = nullptr);
		Video *video;
		void handleFile();
		void loadFrame();
		void displayFrame(cv::Mat frame);
		void handleNext();
		void handlePrev();
		void handleSeek(int frameNum);
		void cleanup();

	signals:
		void vidLoaded();  // NOTE don't implement this, Q_OBJECT magic implementation behind the scenes
		void newFrameLoaded();
};
