#ifndef SKIZZEDITED_H
#define SKIZZEDITED_H

#include <QMainWindow>

namespace Ui {
class SkizzEdited;
}

class SkizzEdited : public QMainWindow
{
	Q_OBJECT

public:
	explicit SkizzEdited(QWidget *parent = 0);
	~SkizzEdited();

private:
	Ui::SkizzEdited *ui;
};

#endif // SKIZZEDITED_H
