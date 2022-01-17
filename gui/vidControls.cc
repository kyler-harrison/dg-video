#include "vidControls.hh"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

/*
 *  Bottom left video controls.
 *
 *  @param parent QWidget* parent object
 */

VidControls::VidControls(QWidget *parent, VidViewer *vidViewer) : QVBoxLayout(parent) {
	// frame / totalFrames input and label
	QHBoxLayout *frameCountLayout = new QHBoxLayout();
	QLineEdit *inpFrame = new QLineEdit();  // TODO connect return press event to something in vidViewer to jump to frameIndex
	inpFrame->setFixedWidth(80);
	inpFrame->setText("0");
	QLabel *numFrames = new QLabel("/ None");  // TODO connect to something in vidViewer when vid loaded and change to number of frames
	frameCountLayout->addWidget(inpFrame);
	frameCountLayout->addWidget(numFrames);
	frameCountLayout->setAlignment(inpFrame, Qt::AlignRight);

	// previous and next frame buttons
	QHBoxLayout *btnLayout = new QHBoxLayout();
	QPushButton *prevBtn = new QPushButton("prev");
	QPushButton *nextBtn = new QPushButton("next");
	btnLayout->addWidget(prevBtn);
	btnLayout->addWidget(nextBtn);
	QObject::connect(prevBtn, &QPushButton::released, vidViewer, &VidViewer::handlePrev);  
	QObject::connect(nextBtn, &QPushButton::released, vidViewer, &VidViewer::handleNext);  

	this->addLayout(frameCountLayout);
	this->addLayout(btnLayout);
}
