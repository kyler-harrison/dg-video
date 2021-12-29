#include "rightLayout.hh"
#include <QLabel>

/*
 *  Creates settings for right side of application.
 */

RightLayout::RightLayout(QWidget *parent) : QVBoxLayout(parent) {
	// right side settings/info box
	QLabel *rightInfo = new QLabel("INFO/SETTINGS");
	rightInfo->setStyleSheet("background-color: green");
	this->addSpacing(16);
	this->addWidget(rightInfo);
}
