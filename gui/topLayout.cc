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
	leftVBox->addWidget(menu);

	// image viewer
	auto *label = new QLabel("IMAGE");
	leftVBox->addWidget(label);

	// image viewer actions/options
	auto *imgOptions = new QLabel("OPTIONS");
	leftVBox->addWidget(imgOptions);

	// right side settings/info box
	auto *rightInfo = new QLabel("INFO/SETTINGS");


	parentHBox->addLayout(leftVBox);
	parentHBox->addSpacing(16);
	parentHBox->addWidget(rightInfo);
	setLayout(parentHBox);
}
