#include <QLabel>

/*
 *  Main video viewer label.
 */

class VidViewer : public QLabel {
	private:
		const char *filePath;

	public:
		VidViewer(QWidget *parent = nullptr);
		void handleFile();
};
