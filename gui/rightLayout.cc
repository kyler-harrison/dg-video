#include "rightLayout.hh"

/*
 *  Creates settings for right side of application.
 *
 *  @param parent QWidget* parent object
 */

RightLayout::RightLayout(QWidget *parent) : QVBoxLayout(parent) {
	// right side settings/info box
	this->info = new QLabel("settings and stuff");
	this->info->setStyleSheet("background-color: green");

	this->addSpacing(16);
	this->addWidget(info);
}
