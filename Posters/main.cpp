#include "posters.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Posters w;
	w.show();
	return a.exec();
}
