#include "leftLayout.hh"

#include <QVBoxLayout>

/*
 *  Left side of display. Creates a menu bar, video viewer, and 
 *  video controls inside a vertical box. 
 *
 *  @param parent QWidget* parent object
 */

LeftLayout::LeftLayout(QWidget *parent) : QVBoxLayout(parent) {
	// main video viewer
	this->vidViewer = new VidViewer();

	// top menu
	this->menu = new Menu(parent, this->vidViewer);
	this->addWidget(menu);

	// add and center vidViewer
	this->addWidget(this->vidViewer);
	this->setAlignment(this->vidViewer, Qt::AlignHCenter);

	// video viewer controls
	this->vidControls = new VidControls();
	this->addWidget(this->vidControls);
}

