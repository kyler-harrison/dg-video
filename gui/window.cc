#include "window.hh"

#include <iostream>

/*
 *  Sets ParentLayout to main layout of main window.
 */

Window::Window(QWidget *parent) : QMainWindow(parent) {
	this->parentWidget->setLayout(this->parentLayout);
	this->setCentralWidget(this->parentWidget);
}

void Window::cleanup() {
	// this also appears to delete parentLayout
	delete this->parentWidget;  
}

void Window::closeEvent(QCloseEvent *event) {
	std::cout << "closing...\n";
	event->accept();
	this->cleanup();
}
