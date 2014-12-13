#ifndef WINDOWGENERATED_H
#define WINDOWGENERATED_H

#include <QtWidgets>

class WindowGenerated : public QDialog
{
	Q_OBJECT

	QVBoxLayout* m_layoutGlobal;
	QTextEdit*   m_generatedCode;
	QPushButton* m_buttonClose;

public:
	explicit WindowGenerated(const QString& code, QWidget *parent = 0);

signals:

public slots:

};

#endif // WINDOWGENERATED_H
