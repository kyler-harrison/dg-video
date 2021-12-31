#include "menu.hh"

#include <QApplication>
#include <QMenu>
#include <QAction>

/*
 *  Top menu bar with "open" file dropdown.
 */

Menu::Menu(QWidget *parent, VidViewer *vidViewer) : QMenuBar(parent) {
	QMenu *fileOption = this->addMenu("&File");
	QAction *open = new QAction("&Open", qApp);  // qApp is a macro defined in QApplication
	fileOption->addAction(open);
	//connect(open, &QAction::triggered, this, &Menu::handleFile);  // TODO make img viewer its own class and define handle in there, pass img viewer obj to this
	connect(open, &QAction::triggered, vidViewer, &VidViewer::handleFile);  // TODO make img viewer its own class and define handle in there, pass img viewer obj to this
	this->setStyleSheet("background-color: purple");
}

