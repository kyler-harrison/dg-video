#include "parentLayout.hh"

/*
 *  Creates left and right sub-layouts.
 *
 *  @param parent QWidget* parent object
 */

ParentLayout::ParentLayout(QWidget *parent) : QHBoxLayout(parent) {
	// each gets the same parent as this
	this->left = new LeftLayout();
	this->right = new RightLayout();

	this->addLayout(this->left);
	this->addLayout(this->right);
}

void ParentLayout::cleanup() {
	this->left->cleanup();
}
