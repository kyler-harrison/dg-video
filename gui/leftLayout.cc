#include "leftLayout.hh"
#include <QVBoxLayout>
#include <QMenuBar>
#include <QLabel>
#include <QMenu>
#include <QAction>
#include <QFileDialog>

/*
 *  Creates a menu bar, image viewer, and image options inside
 *  a vertical box.
 */

LeftLayout::LeftLayout(QWidget *parent) : QVBoxLayout(parent) {
	// TODO dump into menu class
	// top menu
	auto *menu = new QMenuBar();
	QMenu *fileOption = menu->addMenu("&File");
	QAction *open = new QAction("&Open", this);
	fileOption->addAction(open);
	connect(open, &QAction::triggered, this, &LeftLayout::handleFile);  // TODO make img viewer its own class and define handle in there
	menu->setStyleSheet("background-color: purple");
	this->addWidget(menu);

	// TODO dump into img viewer class
	// image viewer
	auto *label = new QLabel("IMAGE");
	label->setStyleSheet("background-color: blue");
	label->setFixedSize(1500, 1000);
	this->addWidget(label);
	this->setAlignment(label, Qt::AlignHCenter);

	// TODO dump into img options class
	// image viewer actions/options
	auto *imgOptions = new QLabel("OPTIONS");
	imgOptions->setStyleSheet("background-color: red");
	this->addWidget(imgOptions);
}

void LeftLayout::handleFile() {
	const char *path = qUtf8Printable(QFileDialog::getOpenFileName());
	this->filePath = path;
	qDebug("%s", this->filePath);
}
