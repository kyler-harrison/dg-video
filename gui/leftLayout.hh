#include "menu.hh"
#include "vidControls.hh"

#include <QVBoxLayout>

/*
 *  Vertical box layout of the left side of the application.
 */

class LeftLayout : public QVBoxLayout {
	Q_OBJECT

	private:
		const char *filePath;
		VidViewer *vidViewer;
		Menu *menu;
		VidControls *vidControls;

	public:
		LeftLayout(QWidget *parent = nullptr);
};
