#include "vidControls.hh"

/*
 *  Bottom left video controls.
 *
 *  @param parent QWidget* parent object
 */

VidControls::VidControls(QWidget *parent) : QLabel(parent) {
	this->setStyleSheet("background-color: red");
}
