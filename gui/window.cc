#include "window.hh"

#include <iostream>

/*
 *  Sets ParentLayout to main layout of main window.
 */

Window::Window(QWidget *parent) : QMainWindow(parent) {
	ParentLayout *parentLayout = new ParentLayout(this);
	QWidget *parentWidget = new QWidget(this);
	parentWidget->setLayout(parentLayout);
	this->setCentralWidget(parentWidget);
}

void Window::cleanup() {
}

void Window::closeEvent(QCloseEvent *event) {
	std::cout << "closing...\n";
	event->accept();
}
