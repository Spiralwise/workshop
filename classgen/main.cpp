#include <QApplication>
#include "src/windowclass.h"

int main (int argc, char** argv)
{
	QApplication app (argc, argv);

	WindowClass window;
	window.show();

	return app.exec();
}
