#ifndef WINDOWCLASS_H
#define WINDOWCLASS_H

#include <QtWidgets>


class WindowClass : public QWidget
{
	Q_OBJECT

	QFormLayout* m_layoutDefinition;
	QLineEdit*   m_editClassName;
	QLineEdit*   m_editClassParent;

	QVBoxLayout* m_layoutOptions;
	QCheckBox*   m_checkboxProtectHeader;
	QCheckBox*   m_checkboxDefaultConstructor;
	QCheckBox*   m_checkboxDefaultDestructor;

	QFormLayout* m_layoutComment;
	QLineEdit*   m_editAuthor;
	QDateEdit*   m_editDate;
	QPlainTextEdit* m_editComment;

	QHBoxLayout* m_layoutButtons;
	QPushButton* m_buttonGenerate;
	QPushButton* m_buttonQuit;

	QGroupBox*   m_boxDefinition;
	QGroupBox*   m_boxOptions;
	QGroupBox*   m_boxComment;
	QVBoxLayout* m_layoutGlobal;

public:
	explicit WindowClass(QWidget *parent = 0);

signals:

public slots:
	void generateCode();

};

#endif // WINDOWCLASS_H
