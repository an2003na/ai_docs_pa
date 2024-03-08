//#include "mainwindow.h"
#include "imageviewer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    imageViewer v;
    v.show();
    return a.exec();
}
