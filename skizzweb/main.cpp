#include <QApplication>
#include "src/skizzwebwindow.h"


int main (int argc, char** argv)
{
	QApplication app(argc, argv);

	SkizzWebWindow window;
	window.show();

	return app.exec();
}
