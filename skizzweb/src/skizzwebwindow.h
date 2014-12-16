#ifndef SKIZZWEBWINDOW_H
#define SKIZZWEBWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtWebKitWidgets>


class SkizzWebWindow : public QMainWindow
{
	Q_OBJECT

	// Web pages
	QTabWidget* pages;

	// Actions
	QAction* m_act_PreviousPage;
	QAction* m_act_NextPage;
	QAction* m_act_StopPage;
	QAction* m_act_RefreshPage;
	QAction* m_act_HomePage;
	QLineEdit* m_URL;

	QAction* m_act_CreatePage;
	QAction* m_act_DeletePage;
	QAction* m_act_Quit;
	QAction* m_act_About;
	QAction* m_act_AboutQt;

	void buildActions();
	void buildMenu();
	void buildToolbar();
	void buildStatusbar();

public:
	explicit SkizzWebWindow(QWidget *parent = 0);

signals:

public slots:
	void LoadURL ();

};

#endif // SKIZZWEBWINDOW_H
