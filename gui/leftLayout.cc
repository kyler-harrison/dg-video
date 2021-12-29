#include "leftLayout.hh"
#include <QVBoxLayout>
#include <QMenuBar>
#include <QLabel>

/*
 *  Creates a menu bar, image viewer, and image options inside
 *  a vertical box.
 */

LeftLayout::LeftLayout(QWidget *parent) : QVBoxLayout(parent) {
	// top menu
	auto *menu = new QMenuBar();
	menu->addMenu("&File");
	menu->setStyleSheet("background-color: purple");
	this->addWidget(menu);

	// image viewer
	auto *label = new QLabel("IMAGE");
	label->setStyleSheet("background-color: blue");
	label->setFixedSize(1500, 1000);
	this->addWidget(label);
	this->setAlignment(label, Qt::AlignHCenter);

	// image viewer actions/options
	auto *imgOptions = new QLabel("OPTIONS");
	imgOptions->setStyleSheet("background-color: red");
	this->addWidget(imgOptions);
}
