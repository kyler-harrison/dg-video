#include "parentLayout.hh"
#include "parentWidget.hh"

#include <QMainWindow>
#include <QCloseEvent>

/*
 *  Main window of application to be called show() on.
 */

class Window : public QMainWindow {
	Q_OBJECT 

	private:
		void closeEvent(QCloseEvent *event);
		ParentWidget *parentWidget;  // make everything else a child descendant and then free only parentWidget
		ParentLayout *parentLayout;

	public:
		Window(QWidget *parent = nullptr);
		void cleanup();
};

