#include <QMenuBar>

/*
 *  Top menu bar.
 */

class Menu : public QMenuBar {
	private:
		const char *filePath;

	public:
		Menu(QWidget *parent = nullptr);
		void handleFile();
};
