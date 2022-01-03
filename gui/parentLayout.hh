#include <QHBoxLayout>
#include <QObject>

/*
 *  Upper most parent layout to be included by the main window.
 */

class ParentLayout : public QHBoxLayout {
	Q_OBJECT

	public:
		ParentLayout(QWidget *parent = nullptr);
};
