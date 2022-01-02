#include "parentLayout.hh"

#include <QMainWindow>
#include <QWidget>
#include <QCloseEvent>

/*
 *  Main window of application to be called show() on.
 */

class Window : public QMainWindow {
	private:
		void closeEvent(QCloseEvent *event);
		QWidget *parentWidget;
		//ParentLayout *parentLayout;

	public:
		Window(QWidget *parent = nullptr);
		void cleanup();
};

