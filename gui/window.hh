#include "parentLayout.hh"

#include <QMainWindow>
#include <QWidget>
#include <QCloseEvent>
#include <QObject>

/*
 *  Main window of application to be called show() on.
 */

class Window : public QMainWindow {
	Q_OBJECT 

	private:
		void closeEvent(QCloseEvent *event);

	public:
		Window(QWidget *parent = nullptr);
		void cleanup();
};

