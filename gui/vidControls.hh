#pragma once
#include "vidViewer.hh"

#include <QLabel>
#include <QVBoxLayout>

/*
 *  Bottom left video controls.
 */

class VidControls : public QVBoxLayout {
	Q_OBJECT

	private:
		QLabel *numFrames;
		VidViewer *vidViewer;


	public:
		VidControls(QWidget *parent = nullptr, VidViewer *vidViewer = nullptr);

	public slots:
		void updateTotalFrames();
};
