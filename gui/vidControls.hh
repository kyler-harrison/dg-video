#pragma once
#include "vidViewer.hh"

#include <QHBoxLayout>

/*
 *  Bottom left video controls.
 */

class VidControls : public QHBoxLayout {
	public:
		VidControls(QWidget *parent = nullptr, VidViewer *vidViewer = nullptr);
};
