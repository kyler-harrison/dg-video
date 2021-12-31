#include "menu.hh"

#include <QApplication>
#include <QMenu>
#include <QAction>
#include <QFileDialog>

/*
 *  Top menu bar with "open" file dropdown.
 */

Menu::Menu(QWidget *parent) : QMenuBar(parent) {
	QMenu *fileOption = this->addMenu("&File");
	QAction *open = new QAction("&Open", qApp);  // qApp is a macro defined in QApplication
	fileOption->addAction(open);
	connect(open, &QAction::triggered, this, &Menu::handleFile);  // TODO make img viewer its own class and define handle in there, pass img viewer obj to this
	this->setStyleSheet("background-color: purple");
}

/*
 *  Opens file dialog and prints out path. Will probably move this later.
 */

void Menu::handleFile() {
	const char *path = qUtf8Printable(QFileDialog::getOpenFileName());
	this->filePath = path;
	qDebug("%s", this->filePath);
}
