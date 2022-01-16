#include "vidControls.hh"

#include <QPushButton>

/*
 *  Bottom left video controls.
 *
 *  @param parent QWidget* parent object
 */

VidControls::VidControls(QWidget *parent, VidViewer *vidViewer) : QHBoxLayout(parent) {
	QPushButton *backBtn = new QPushButton("back");
	QPushButton *nextBtn = new QPushButton("next");
	this->addWidget(backBtn);
	this->addWidget(nextBtn);
	QObject::connect(backBtn, &QPushButton::released, vidViewer, &VidViewer::handleBack);  
	QObject::connect(nextBtn, &QPushButton::released, vidViewer, &VidViewer::handleNext);  
}
