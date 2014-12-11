#ifndef SKIZZWINDOW_H
#define SKIZZWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QLCDNumber>
#include <QSlider>


class SkizzWindow : public QWidget
{
	QLCDNumber* m_displayNumber;
	QSlider*    m_sliderNumber;

public:
	explicit SkizzWindow(QWidget *parent = 0);
	SkizzWindow(int width, int height, QWidget* parent = 0);

};

#endif // SKIZZWINDOW_H
