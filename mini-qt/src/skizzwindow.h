#ifndef SKIZZWINDOW_H
#define SKIZZWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QProgressBar>
#include <QPushButton>
#include <QSlider>


class SkizzWindow : public QWidget
{
	QProgressBar* m_displayNumber;
	QSlider*      m_sliderNumber;
	QPushButton*  m_buttonReset;

public:
	explicit SkizzWindow(QWidget *parent = 0);
	SkizzWindow(int width, int height, QWidget* parent = 0);

};

#endif // SKIZZWINDOW_H
