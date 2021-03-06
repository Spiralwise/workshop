#include "windowclass.h"
#include "windowgenerated.h"


WindowClass::WindowClass(QWidget *parent) :
	QWidget(parent)
{
	setWindowTitle("Create a new C++ class");
	setMinimumWidth(400);

	// Box definition
	QGroupBox* m_boxDefinition      = new QGroupBox("Class definition");
	QFormLayout* m_layoutDefinition = new QFormLayout();
		m_editClassName    = new QLineEdit();
		m_editClassParent  = new QLineEdit();
		m_editClassName->setPlaceholderText("Put class name here...");
		m_layoutDefinition->addRow("&Name", m_editClassName);
		m_layoutDefinition->addRow("&Parent class", m_editClassParent);
		m_boxDefinition->setLayout(m_layoutDefinition);

	// Box options
	QGroupBox* m_boxOptions      = new QGroupBox("Options");
	QVBoxLayout* m_layoutOptions = new QVBoxLayout();
		m_checkboxHeaderGuard        = new QCheckBox("Protected header from multiple inclusion");
		m_editHeaderGuardName        = new QLineEdit();
		m_checkboxDefaultConstructor = new QCheckBox("Create default constructor");
		m_checkboxDefaultDestructor  = new QCheckBox("Create default destructor");
		m_checkboxHeaderGuard->setChecked(true);
		m_editHeaderGuardName->setPlaceholderText("Header guard name");
		m_checkboxDefaultConstructor->setChecked(true);
		m_layoutOptions->addWidget(m_checkboxHeaderGuard);
		m_layoutOptions->addWidget(m_editHeaderGuardName);
		m_layoutOptions->addWidget(m_checkboxDefaultConstructor);
		m_layoutOptions->addWidget(m_checkboxDefaultDestructor);
		m_boxOptions->setLayout(m_layoutOptions);

	// Box comment
	m_boxComment    = new QGroupBox("Comments");
	m_boxComment->setCheckable(true);
	m_boxComment->setChecked(false);
	QFormLayout* m_layoutComment = new QFormLayout();
		m_editAuthor  = new QLineEdit();
		m_editDate    = new QDateEdit(QDate::currentDate());
		m_editComment = new QPlainTextEdit();
		m_editDate->setDisplayFormat("dd-MM-yyyy");
		m_layoutComment->addRow("&Author", m_editAuthor);
		m_layoutComment->addRow("&Date", m_editDate);
		m_layoutComment->addRow("D&escription", m_editComment);
		m_boxComment->setLayout(m_layoutComment);

	// Layout buttons
	QHBoxLayout* m_layoutButtons = new QHBoxLayout();
		m_buttonGenerate = new QPushButton("Generate!");
		m_buttonQuit     = new QPushButton("Quit");
		m_buttonGenerate->setFixedWidth(120);
		m_buttonQuit->setFixedWidth(80);
		m_layoutButtons->addWidget(m_buttonGenerate);
		m_layoutButtons->addWidget(m_buttonQuit);
		m_layoutButtons->setAlignment(Qt::AlignRight);

	// Layout global
	QVBoxLayout* m_layoutGlobal = new QVBoxLayout();
	m_layoutGlobal->addWidget(m_boxDefinition);
	m_layoutGlobal->addWidget(m_boxOptions);
	m_layoutGlobal->addWidget(m_boxComment);
	m_layoutGlobal->addLayout(m_layoutButtons);

	setLayout(m_layoutGlobal);

	// Events handling
	connect(m_editClassName, SIGNAL(textEdited(QString)), this, SLOT(updateHeaderGuardName(QString)));
	connect(m_buttonGenerate, SIGNAL(clicked()), this, SLOT(generateCode()));
	connect(m_buttonQuit, SIGNAL(clicked()), this, SLOT(close()));
}


void WindowClass::generateCode()
{
	QString header = "", source = "";
	QString className = m_editClassName->text();
	QString headerGuardName = m_editHeaderGuardName->text();


	// ---- Comments
	if (m_boxComment->isChecked())
	{
		QString author  = m_editAuthor->text();
		QString comment = m_editComment->toPlainText();

		header += "/*\n";
		if (!author.isEmpty())
			header += "Author : " + author + "\n";
		header += "Date : " + m_editDate->date().toString("ddd d MMM yyyy") + "\n";
		if (!comment.isEmpty())
			header += "\n" + comment + "\n";
		header += "*/\n\n";
	}

	// ---- Header
	if (m_checkboxHeaderGuard->isChecked())
	{
		header += "#ifndef " + headerGuardName + "\n";
		header += "#define " + headerGuardName + "\n\n";
	}
	source += "#include \"" + className.toLower() + ".h\"\n";

	// ---- Class definition
	header += "class " + className;
	if (!m_editClassParent->text().isEmpty())
		header += " : public " + m_editClassParent->text();
	header += "\n{\n\n";
	header += "public: \n";

	// ---- Methods
	if (m_checkboxDefaultConstructor->isChecked())
	{
		header += "\t" + className + "();\n";
		source += "\n\n" + className + "::" + className + "()\n{\n\t\n}\n";
	}
	if (m_checkboxDefaultDestructor->isChecked())
	{
		header += "\t~" + className + "();\n";
		source += "\n\n" + className + "::~" + className + "()\n{\n\t\n}\n";
	}

	header += "};\n";

	if (m_checkboxHeaderGuard->isChecked())
		header += "#endif // " + headerGuardName + "\n";

	WindowGenerated dialogGenerated (header, source, this);
	dialogGenerated.exec();
}


void WindowClass::updateHeaderGuardName(const QString& name)
{
	m_editHeaderGuardName->setText(name.toUpper() + "_H");
}
