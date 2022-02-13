#include "rightLayout.hh"

/*
 *  Creates settings for right side of application.
 *
 *  @param parent QWidget* parent object
 */

RightLayout::RightLayout(QWidget *parent) : QVBoxLayout(parent) {
	// right side settings/info box
	this->scaleButton = new QPushButton("Set scale");
	this->scaleLabel = new QLabel("Scale is not set");
	this->scaleLabel->setStyleSheet("background-color: green");

	this->addWidget(scaleButton);
	this->addWidget(scaleLabel);
}
