#include "window.hh"

#include <iostream>
#include <QApplication> 
#include <QDesktopWidget>
#include <QFileDialog>

int main(int argc, char **argv) {
	QApplication app(argc, argv);
	Window window;
	window.showMaximized();
	window.setWindowState(Qt::WindowMaximized);
	window.show();

	// start app main event loop
	app.exec();

	return 0;
}
