#include "window.hh"
#include "parentLayout.hh"
#include <QWidget>

/*
 *  Sets ParentLayout to main layout of main window.
 */

Window::Window(QWidget *parent) : QWidget(parent) {
	ParentLayout *parentLayout = new ParentLayout(this);
	setLayout(parentLayout);
}
