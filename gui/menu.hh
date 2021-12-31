#include "vidViewer.hh"

#include <QMenuBar>

/*
 *  Top menu bar.
 */

class Menu : public QMenuBar {
	public:
		Menu(QWidget *parent = nullptr);
		Menu(QWidget *parent = nullptr, VidViewer *vidViewer = nullptr);
};
