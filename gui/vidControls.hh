#pragma once
#include "vidViewer.hh"

#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>

/*
 *  Bottom left video controls.
 */

class VidControls : public QVBoxLayout {
	Q_OBJECT

	private:
		QLabel *numFrames;
		QLineEdit *inpFrame;
		VidViewer *vidViewer;


	public:
		VidControls(QWidget *parent = nullptr, VidViewer *vidViewer = nullptr);

	public slots:
		void updateTotalFrames();
		void updateFrameNum();
};
