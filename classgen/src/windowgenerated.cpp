#include "windowgenerated.h"

WindowGenerated::WindowGenerated(const QString& header, const QString& source, QWidget *parent) :
	QDialog(parent)
{
	setWindowTitle("Generated code");
	setMinimumWidth(500);

	int minmumTextHeight = 300;
	QFont codeFont ("monospace", 9);

	m_layoutGlobal = new QVBoxLayout();
		QTabWidget* tabs = new QTabWidget();
			m_generatedHeader = new QTextEdit();
			m_generatedSource = new QTextEdit();
			m_buttonClose     = new QPushButton("Close");
			m_generatedHeader->setReadOnly(true);
			m_generatedHeader->setMinimumHeight(minmumTextHeight);
			m_generatedHeader->setFont(codeFont);
			m_generatedHeader->setText(header);
			m_generatedSource->setReadOnly(true);
			m_generatedSource->setMinimumHeight(minmumTextHeight);
			m_generatedSource->setFont(codeFont);
			m_generatedSource->setText(source);
			m_buttonClose->setFixedWidth(80);
			tabs->addTab(m_generatedHeader, "Header");
			tabs->addTab(m_generatedSource, "Source");

		m_layoutGlobal->addWidget(tabs);
		m_layoutGlobal->addWidget(m_buttonClose);

	setLayout(m_layoutGlobal);

	connect(m_buttonClose, SIGNAL(clicked()), this, SLOT(close()));
}
