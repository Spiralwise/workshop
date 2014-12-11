#include "skizzwindow.h"

SkizzWindow::SkizzWindow(QWidget *parent) :
	SkizzWindow(200,200, parent)
{
}


SkizzWindow::SkizzWindow(int width, int height, QWidget *parent) :
	QWidget(parent)
{
	setFixedSize(width, height);

	m_displayNumber = new QLCDNumber(this);
	m_displayNumber->setSegmentStyle(QLCDNumber::Flat);
	m_displayNumber->move(50, 20);

	m_sliderNumber = new QSlider(Qt::Horizontal, this);
	m_sliderNumber->setGeometry(10, 60, 150, 20);

	QObject::connect(m_sliderNumber, SIGNAL(valueChanged(int)), m_displayNumber, SLOT(display(int)));
}
