#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

/*
 *  Vertical box layout for the right side of the application.
 */

class RightLayout : public QVBoxLayout {
	Q_OBJECT

	private:
		QLabel *scaleLabel;
		QPushButton *scaleButton;

	public:
		RightLayout(QWidget *parent = nullptr);
};
