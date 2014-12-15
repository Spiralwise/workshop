#include "skizzedited.h"
#include "ui_skizzedited.h"

SkizzEdited::SkizzEdited(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::SkizzEdited)
{
	ui->setupUi(this);
}

SkizzEdited::~SkizzEdited()
{
	delete ui;
}
