#include "topLayout.hh"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QLabel>

TopLayout::TopLayout(QWidget *parent) : QWidget(parent) {
	// TODO put 4 sub elems together in here
	// each will need its own class, pass in as args

	// top parent boxes
	auto *leftVBox = new QVBoxLayout();
	auto *parentHBox = new QHBoxLayout(this);

	// top menu
	auto *menu = new QMenuBar();
	menu->addMenu("&File");
	menu->setStyleSheet("background-color: purple");
	leftVBox->addWidget(menu);

	// image viewer
	auto *label = new QLabel("IMAGE");
	label->setStyleSheet("background-color: blue");
	leftVBox->addWidget(label);

	// image viewer actions/options
	auto *imgOptions = new QLabel("OPTIONS");
	imgOptions->setStyleSheet("background-color: red");
	leftVBox->addWidget(imgOptions);

	// right side settings/info box
	auto *rightInfo = new QLabel("INFO/SETTINGS");
	rightInfo->setStyleSheet("background-color: green");

	parentHBox->addLayout(leftVBox);
	//parentHBox->addSpacing(16);
	parentHBox->addWidget(rightInfo);
	setLayout(parentHBox);
}
