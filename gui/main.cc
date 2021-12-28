#include "topLayout.hh"
#include <QApplication> 

int main( int argc, char **argv )
{
    QApplication app(argc, argv);
		TopLayout *window = new TopLayout();
		window->show();

    return app.exec();
}
