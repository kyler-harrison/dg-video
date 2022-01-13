#include "leftLayout.hh"
#include "rightLayout.hh"

#include <QHBoxLayout>

/*
 *  The main parent layout. All other layouts are sub-layouts of this. 
 */

class ParentLayout : public QHBoxLayout {
	Q_OBJECT

	private:
		LeftLayout *left;
		RightLayout *right;

	public:
		ParentLayout(QWidget *parent = nullptr);
		void cleanup();
};
