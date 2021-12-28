#include "topLayout.hh"
#include <iostream>
#include <QApplication> 

int main( int argc, char **argv )
{
    QApplication app(argc, argv);
		TopLayout *window = new TopLayout();
		window->setMinimumSize(600, 300);
		window->setWindowState(Qt::WindowMaximized);
		window->show();

    return app.exec();
}
