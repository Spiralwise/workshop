#include "skizzwindow.h"

SkizzWindow::SkizzWindow(QWidget *parent)
	: QWidget(parent)
{
	m_layoutGlobal  = new QGridLayout;

	m_displayNumber = new QProgressBar();
	m_sliderNumber  = new QSlider(Qt::Horizontal);
	m_layoutGlobal->addWidget(m_displayNumber, 0, 0, 1, 3);
	m_layoutGlobal->addWidget(m_sliderNumber, 1, 0, 1, 3);

	m_buttonReset  = new QPushButton("Reset");
	m_buttonDialog = new QPushButton("Cut rope");
	m_buttonInput  = new QPushButton("Partner");
	m_layoutGlobal->addWidget(m_buttonReset, 2, 0);
	m_layoutGlobal->addWidget(m_buttonDialog, 2, 1);
	m_layoutGlobal->addWidget(m_buttonInput, 2, 2);

	m_buttonFont = new QPushButton("Howdyho! Change thy font and be neat!", this);
	m_layoutGlobal->addWidget(m_buttonFont, 3, 0, 1, 3);

	this->setLayout(m_layoutGlobal);

	QObject::connect(m_sliderNumber, SIGNAL(valueChanged(int)), m_displayNumber, SLOT(setValue(int)));
	QObject::connect(m_buttonReset, SIGNAL(clicked()), m_displayNumber, SLOT(reset()));
	//QObject::connect(m_buttonReset, SIGNAL(clicked()), m_sliderNumber, SLOT(setValue(int)));
	QObject::connect(m_buttonDialog, SIGNAL(clicked()), this, SLOT(showInfobox()));
	QObject::connect(m_buttonInput, SIGNAL(clicked()), this, SLOT(showInputbox()));
	QObject::connect(m_buttonFont, SIGNAL(clicked()), this, SLOT(showFontbox()));
}


SkizzWindow::SkizzWindow(int width, int height, QWidget *parent) :
	SkizzWindow(parent)
{
	setFixedSize(width, height);
}


void SkizzWindow::showInfobox()
{
	int answer = QMessageBox::question(this, "What is that?", "Should we cut the rope now?", QMessageBox::Yes | QMessageBox::No);
	if (QMessageBox::Yes == answer)
		QMessageBox::critical(this, "How dare you !", "He was our best friend, you monster!");
	else if (QMessageBox::No == answer)
		QMessageBox::information(this, "Pfew!", "That was close.");
}


void SkizzWindow::showInputbox()
{
	bool ok;
	QString name = QInputDialog::getText(this, "What is the name of your partner?", "Partner's name", QLineEdit::Normal, "", &ok);
	if (ok)
	{
		if (!name.isEmpty())
			QMessageBox::information(this, "Partner", "Ok, I call " + name + " to tell him/her you are ready.");
		else
			QMessageBox::critical(this, "Partner", "Wow, how did you spell that again?");
	}
	else
		QMessageBox::warning(this, "Partner", "Okay! I get it! No partner.");
}


void SkizzWindow::showFontbox()
{
	bool ok;
	QFont selectedFont = QFontDialog::getFont(&ok, m_buttonFont->font(), this, "Choose thy font");
	if (ok)
		m_buttonFont->setFont(selectedFont);
}
