#pragma once
#include "vidViewer.hh"

#include <QVBoxLayout>

/*
 *  Bottom left video controls.
 */

class VidControls : public QVBoxLayout {
	public:
		VidControls(QWidget *parent = nullptr, VidViewer *vidViewer = nullptr);
};
