#include <QApplication>
#include "src/skizzwindow.h"
#include "src/skizzmainwindow.h"
#include "src/skizzedited.h"


int main (int argc, char** argv)
{
	QApplication app (argc, argv);

	//SkizzWindow window;
	//SkizzMainWindow window;
	SkizzEdited window;
	window.show();

	return app.exec ();
}
