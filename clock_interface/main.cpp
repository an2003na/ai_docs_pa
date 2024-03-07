//#include "mainwindow.h"
#include "clockinterface.h"

#include <QApplication>
#include <QPalette>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    clockInterface t;
    t.resize(100, 150);
    t.show();
    return a.exec();
}
