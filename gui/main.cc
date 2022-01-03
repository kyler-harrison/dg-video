#include "window.hh"

#include <iostream>
#include <QApplication> 
#include <QDesktopWidget>
#include <QFileDialog>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
		Window *window = new Window();
		window->showMaximized();
		window->setWindowState(Qt::WindowMaximized);
		window->show();

		// start app main event loop
    app.exec();

		// i believe this also frees all heap-allocated children of window (everything?)
		delete window;  

		return 0;
}
