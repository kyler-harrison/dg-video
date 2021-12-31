#include "leftLayout.hh"
#include "menu.hh"
#include "vidControls.hh"

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
	// video viewer
	VidViewer *vidViewer = new VidViewer();

	// top menu
	Menu *menu = new Menu(parent, vidViewer);  // is parent supposed to be passed? wtf is parent anyways
	this->addWidget(menu);

	// add and center vidViewer
	this->addWidget(vidViewer);
	this->setAlignment(vidViewer, Qt::AlignHCenter);

	// video viewer control
	VidControls *vidControls = new VidControls();
	this->addWidget(vidControls);
}

