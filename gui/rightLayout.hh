#include <QVBoxLayout>
#include <QLabel>

/*
 *  Vertical box layout for the right side of the application.
 */

class RightLayout : public QVBoxLayout {
	Q_OBJECT

	private:
		QLabel *info;

	public:
		RightLayout(QWidget *parent = nullptr);
};
