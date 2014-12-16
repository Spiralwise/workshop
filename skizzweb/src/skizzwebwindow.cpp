#include "skizzwebwindow.h"

SkizzWebWindow::SkizzWebWindow(QWidget *parent) :
	QMainWindow(parent)
{
	// Initialization
	setWindowTitle("Skizzweb");
	setMinimumHeight(480);
	setMinimumWidth(640);
	setWindowIcon(QIcon(QCoreApplication::applicationDirPath() + "/res/web.png"));

	// Building
	pages = new QTabWidget(this);
	pages->addTab(new QWebView, "New tab");
	this->setCentralWidget(pages);
	buildActions();
	buildMenu();
	buildToolbar();
}


void SkizzWebWindow::buildActions()
{
	// General actions
	QString path = QCoreApplication::applicationDirPath() + "/res/";
	m_act_PreviousPage = new QAction(QIcon(path + "prec.png"), "&Previous page",  this);
	m_act_NextPage     = new QAction(QIcon(path + "suiv.png"), "&Next page",      this);
	m_act_StopPage     = new QAction(QIcon(path + "stop.png"), "&Stop loading",   this);
	m_act_RefreshPage  = new QAction(QIcon(path + "actu.png"), "&Refresh page",   this);
	m_act_HomePage     = new QAction(QIcon(path + "home.png"), "Go to &homepage", this);

	// File & about actions
	m_act_CreatePage   = new QAction("New &tab", this);
	m_act_DeletePage   = new QAction("C&lose tab", this);
	m_act_Quit         = new QAction("&Quit", this);
	m_act_About        = new QAction("&About Skizzweb", this);
	m_act_AboutQt      = new QAction("About &Qt", this);

	// Edit
	m_URL = new QLineEdit(this);
	m_URL->setPlaceholderText("Enter URL here...");

	// Signals & Slots
	connect(m_URL, SIGNAL(returnPressed()), this, SLOT(LoadURL()));
	connect(m_act_Quit, SIGNAL(triggered()), this, SLOT(close()));
}


void SkizzWebWindow::buildMenu()
{
	QMenu* menuFile     = menuBar()->addMenu("&File");
	QMenu* menuNavigate = menuBar()->addMenu("&Navigate");
	QMenu* menuAbout    = menuBar()->addMenu("&About");

	menuFile->addAction(m_act_CreatePage);
	menuFile->addAction(m_act_DeletePage);
	menuFile->addSeparator();
	menuFile->addAction(m_act_Quit);

	menuNavigate->addAction(m_act_PreviousPage);
	menuNavigate->addAction(m_act_NextPage);
	menuNavigate->addSeparator();
	menuNavigate->addAction(m_act_StopPage);
	menuNavigate->addAction(m_act_RefreshPage);
	menuNavigate->addAction(m_act_HomePage);

	menuAbout->addAction(m_act_About);
	menuAbout->addAction(m_act_AboutQt);
}


void SkizzWebWindow::buildToolbar()
{
	QToolBar* toolbar = addToolBar("Main Toolbar");
	toolbar->addAction(m_act_PreviousPage);
	toolbar->addAction(m_act_NextPage);
	toolbar->addAction(m_act_StopPage);
	toolbar->addWidget(m_URL);
	toolbar->addAction(m_act_RefreshPage);
	toolbar->addAction(m_act_HomePage);
}


/**** SLOTS ****/
void SkizzWebWindow::LoadURL()
{
	QWebView* page = (QWebView*)pages->currentWidget();
	page->load(QUrl(m_URL->text()));
}
