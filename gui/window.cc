#include "window.hh"

/*
 *  Defines parentWidget and parentLayout, sets parentWidget as the
 *  central widget.
 *
 *  @param parent QWidget* parent object
 */

Window::Window(QWidget *parent) : QMainWindow(parent) {
	//this->parentWidget = new ParentWidget();
	this->parentWidget = new ParentWidget();
	this->parentLayout = new ParentLayout(this->parentWidget);
	this->setCentralWidget(this->parentWidget);
}

/*
 *  Frees allocated memory of parentWidget and all of its children (implicit).
 *
 *  @param void
 *  @return void
 */

void Window::cleanup() {
	delete this->parentWidget;  
}

/*
 *  Catch window close.
 *
 *  @param event QCloseEvent* actual event object
 *  @return void
 */

void Window::closeEvent(QCloseEvent *event) {
	std::cout << "closing...\n";
	event->accept();
	this->cleanup();
}
