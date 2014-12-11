#include "skizzwindow.h"

SkizzWindow::SkizzWindow(QWidget *parent) :
	SkizzWindow(200,200, parent)
{
}


SkizzWindow::SkizzWindow(int width, int height, QWidget *parent) :
	QWidget(parent)
{
	setFixedSize(width, height);

	m_displayNumber = new QProgressBar(this);
	m_displayNumber->setGeometry(20, 20, width-40, 15);

	m_sliderNumber = new QSlider(Qt::Horizontal, this);
	m_sliderNumber->setGeometry(20, 40, width-40, 20);

	m_buttonReset = new QPushButton("Reset", this);
	m_buttonReset->setGeometry(20, 80, 40, 20);

	QObject::connect(m_sliderNumber, SIGNAL(valueChanged(int)), m_displayNumber, SLOT(setValue(int)));
	QObject::connect(m_buttonReset, SIGNAL(clicked()), m_displayNumber, SLOT(reset()));
	//QObject::connect(m_buttonReset, SIGNAL(clicked()), m_sliderNumber, SLOT(setValue(int)));
}
