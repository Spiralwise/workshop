#include <QApplication>
#include "src/skizzwindow.h"


int main (int argc, char** argv)
{
	QApplication app (argc, argv);

	SkizzWindow window(200,100);
	window.show();

	return app.exec ();
}
