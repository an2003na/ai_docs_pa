//#include "mainwindow.h"
#include "drawwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    drawWidget w;
    w.resize(400, 400);
    w.show();
    return a.exec();
}
