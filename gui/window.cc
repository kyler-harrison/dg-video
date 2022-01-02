#include "window.hh"

#include <iostream>

/*
 *  Sets ParentLayout to main layout of main window.
 */

Window::Window(QWidget *parent) : QMainWindow(parent) {
	//this->parentLayout = new ParentLayout(this);
	ParentLayout *parentLayout = new ParentLayout();
	this->parentWidget = new QWidget();
	this->parentWidget->setLayout(parentLayout);
	this->setCentralWidget(this->parentWidget);
}

void Window::cleanup() {
	delete (this->parentWidget);
	//this->parentLayout->cleanup();

	// do anything else ("are you sure?" prompt, etc...)
}

void Window::closeEvent(QCloseEvent *event) {
	std::cout << "closing...\n";
	//event->accept();
	this->cleanup();
}
