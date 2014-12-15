#include "skizzmainwindow.h"

SkizzMainWindow::SkizzMainWindow(QWidget *parent) :
	QMainWindow(parent)
{
	menuBar()->addMenu("&File");
	menuBar()->addMenu("&Edit");
	menuBar()->addMenu("&Display");
}
