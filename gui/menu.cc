#include "menu.hh"

#include <QApplication>

/*
 *  Top menu bar with "open" file dropdown.
 *
 *  @param parent QWidget* parent object
 *  @param vidViewer VidViewer* main video viewer of the application to file open action to
 */

Menu::Menu(QWidget *parent, VidViewer *vidViewer) : QMenuBar(parent) {
	// add "File" to menu
	this->fileOption = this->addMenu("&File");

	// add "Open" to menu and connect it to the vidViewer
	this->open = new QAction("&Open", qApp);  // qApp is a macro defined in QApplication
	this->fileOption->addAction(open);
	connect(this->open, &QAction::triggered, vidViewer, &VidViewer::handleFile);  

	// temporary
	this->setStyleSheet("background-color: purple");
}

