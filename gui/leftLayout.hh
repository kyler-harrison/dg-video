#include <QVBoxLayout>
#include <QWidget>

/*
 *  Vertical box layout of the left side of the application.
 */

class LeftLayout : public QVBoxLayout {
	private:
		const char *filePath;

	public:
		LeftLayout(QWidget *parent = nullptr);
};
