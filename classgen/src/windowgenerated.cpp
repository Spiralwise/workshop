#include "windowgenerated.h"

WindowGenerated::WindowGenerated(const QString& code, QWidget *parent) :
	QDialog(parent)
{
	setWindowTitle("Generated code");
	setMinimumWidth(500);

	m_layoutGlobal = new QVBoxLayout();
		m_generatedCode = new QTextEdit();
		m_buttonClose   = new QPushButton("Close");
		m_generatedCode->setReadOnly(true);
		m_generatedCode->setMinimumHeight(300);
		m_generatedCode->setText(code);
		m_layoutGlobal->addWidget(m_generatedCode);
		m_layoutGlobal->addWidget(m_buttonClose);

	setLayout(m_layoutGlobal);

	QObject::connect(m_buttonClose, SIGNAL(clicked()), this, SLOT(close()));
}
