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

    return app.exec();
}
