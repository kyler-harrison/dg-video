#include "vidControls.hh"

#include <QPushButton>

/*
 *  Bottom left video controls.
 *
 *  @param parent QWidget* parent object
 */

VidControls::VidControls(QWidget *parent, VidViewer *inpVidViewer) : QVBoxLayout(parent) {
	// TODO maybe use more signal/slots so that dont even have to pass this in?
	this->vidViewer = inpVidViewer;

	// frame / totalFrames input and label
	QHBoxLayout *frameCountLayout = new QHBoxLayout();
	this->inpFrame = new QLineEdit();  // TODO connect return press event to something in inpVidViewer to jump to frameIndex
	this->inpFrame->setFixedWidth(80);
	this->inpFrame->setText("1");  // NOTE display index is +1 actual index
	this->numFrames = new QLabel("/ None");  // TODO connect to something in inpVidViewer when vid loaded and change to number of frames

	frameCountLayout->addWidget(this->inpFrame);
	frameCountLayout->addWidget(numFrames);
	frameCountLayout->setAlignment(inpFrame, Qt::AlignRight);

	QObject::connect(this->vidViewer, &VidViewer::newFrameLoaded, this, &VidControls::updateFrameNum);

	// previous and next frame buttons
	QHBoxLayout *btnLayout = new QHBoxLayout();
	QPushButton *prevBtn = new QPushButton("prev");
	QPushButton *nextBtn = new QPushButton("next");
	btnLayout->addWidget(prevBtn);
	btnLayout->addWidget(nextBtn);
	QObject::connect(prevBtn, &QPushButton::released, this->vidViewer, &VidViewer::handlePrev);  
	QObject::connect(nextBtn, &QPushButton::released, this->vidViewer, &VidViewer::handleNext);  

	this->addLayout(frameCountLayout);
	this->addLayout(btnLayout);
}

/*
 *  Change number of total frames displayed.
 *
 *  @return void
 */

void VidControls::updateTotalFrames() {
	std::string numStr = "/ " + std::to_string(this->vidViewer->video->numFrames);
	this->numFrames->setText(numStr.c_str());
}

void VidControls::updateFrameNum() {
	// display actual index + 1
	std::string frameStr = std::to_string(this->vidViewer->video->frameIndex + 1);
	this->inpFrame->setText(frameStr.c_str());
}
