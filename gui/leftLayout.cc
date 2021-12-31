#include "leftLayout.hh"
#include "menu.hh"
#include "vidControls.hh"
#include "vidViewer.hh"

#include <QVBoxLayout>
#include <QMenuBar>
#include <QLabel>
#include <QMenu>
#include <QAction>
#include <QFileDialog>

/*
 *  Creates a menu bar, video viewer, and video controls inside
 *  a vertical box.
 */

LeftLayout::LeftLayout(QWidget *parent) : QVBoxLayout(parent) {
	// top menu
	Menu *menu = new Menu();
	this->addWidget(menu);

	// video viewer
	VidViewer *vidViewer = new VidViewer();
	this->addWidget(vidViewer);
	this->setAlignment(vidViewer, Qt::AlignHCenter);

	// video viewer control
	VidControls *vidControls = new VidControls();
	this->addWidget(vidControls);
}

