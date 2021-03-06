#ifndef WINDOWCLASS_H
#define WINDOWCLASS_H

#include <QtWidgets>


class WindowClass : public QWidget
{
	Q_OBJECT

	// Class definition
	QLineEdit*   m_editClassName;
	QLineEdit*   m_editClassParent;

	// Class options
	QCheckBox*   m_checkboxHeaderGuard;
	QLineEdit*   m_editHeaderGuardName;
	QCheckBox*   m_checkboxDefaultConstructor;
	QCheckBox*   m_checkboxDefaultDestructor;

	// Comments
	QGroupBox*   m_boxComment;
	QLineEdit*   m_editAuthor;
	QDateEdit*   m_editDate;
	QPlainTextEdit* m_editComment;

	// Buttons
	QPushButton* m_buttonGenerate;
	QPushButton* m_buttonQuit;

public:
	explicit WindowClass(QWidget *parent = 0);

signals:

private slots:
	void generateCode();
	void updateHeaderGuardName(const QString&);

};

#endif // WINDOWCLASS_H
