#ifndef SKIZZWINDOW_H
#define SKIZZWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QFontDialog>
#include <QGridLayout>
#include <QFormLayout>
#include <QLineEdit>
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

	// Forms
	QLineEdit* m_editName;
	QLineEdit* m_editAnimal;
	QLineEdit* m_editAge;

	// Layouts
	QGridLayout*  m_layoutGlobal;
	QFormLayout*  m_layoutForm;

public:
	explicit SkizzWindow(QWidget *parent = 0);
	SkizzWindow(int width, int height, QWidget* parent = 0);

public slots:
	void showInfobox();
	void showInputbox();
	void showFontbox();
};

#endif // SKIZZWINDOW_H
