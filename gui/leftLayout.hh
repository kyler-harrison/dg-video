#include "menu.hh"
#include "vidControls.hh"

#include <QVBoxLayout>
#include <QWidget>

/*
 *  Vertical box layout of the left side of the application.
 */

class LeftLayout : public QVBoxLayout {
	Q_OBJECT

	private:
		const char *filePath;
		VidViewer *vidViewer;
		Menu *menu;
		QWidget *vidControlsWidget;
		VidControls *vidControlsLayout;

	public:
		LeftLayout(QWidget *parent = nullptr);
		void cleanup();
};
