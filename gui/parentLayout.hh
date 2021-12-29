#include <QHBoxLayout>

/*
 *  Upper most parent layout to be included by the main window.
 */

class ParentLayout : public QHBoxLayout {
	public:
		ParentLayout(QWidget *parent = nullptr);
};
