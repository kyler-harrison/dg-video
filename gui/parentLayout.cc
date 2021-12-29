#include "parentLayout.hh"
#include "leftLayout.hh"
#include "rightLayout.hh"
#include <QLabel>

/*
 *  Creates a left and right layout (see leftLayout.hh and rightLayout.hh).
 */

ParentLayout::ParentLayout(QWidget *parent) : QHBoxLayout(parent) {
	LeftLayout *left = new LeftLayout();
	RightLayout *right = new RightLayout();

	this->addLayout(left);
	this->addLayout(right);
}
