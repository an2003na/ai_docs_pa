//#include "mainwindow.h"
#include "clockinterface.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    clockInterface t;
    t.show();
    return a.exec();
}
