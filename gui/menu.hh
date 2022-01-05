#include "vidViewer.hh"

#include <QMenuBar>

/*
 *  Top menu bar.
 */

class Menu : public QMenuBar {
	private:
		QMenu *fileOption;
		QAction *open;

	public:
		Menu(QWidget *parent = nullptr);
		Menu(QWidget *parent = nullptr, VidViewer *vidViewer = nullptr);
};
