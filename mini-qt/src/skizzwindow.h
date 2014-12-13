#ifndef SKIZZWINDOW_H
#define SKIZZWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QFontDialog>
#include <QBoxLayout>
#include <QGridLayout>
#include <QInputDialog>
#include <QMessageBox>
#include <QProgressBar>
#include <QPushButton>
#include <QSlider>


class SkizzWindow : public QWidget
{
	Q_OBJECT

	// Widgets
	QProgressBar* m_displayNumber;
	QSlider*      m_sliderNumber;
	QPushButton*  m_buttonReset;
	QPushButton*  m_buttonDialog;
	QPushButton*  m_buttonInput;
	QPushButton*  m_buttonFont;

	// Layouts
	QGridLayout*  m_layoutGlobal;

public:
	explicit SkizzWindow(QWidget *parent = 0);
	SkizzWindow(int width, int height, QWidget* parent = 0);

public slots:
	void showInfobox();
	void showInputbox();
	void showFontbox();
};

#endif // SKIZZWINDOW_H
