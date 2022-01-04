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
		// this is the master parent widget, make everything a child descendant
		// and free only parentWidget to free everything
		QWidget *parentWidget = new QWidget();  
		ParentLayout *parentLayout = new ParentLayout();

	public:
		Window(QWidget *parent = nullptr);
		void cleanup();
};

