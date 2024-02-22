#include "clickcounter.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClickCounter w;
    w.setWindowTitle("Simple click counter");
    w.resize(400, 400);
    w.show();
    return a.exec();
}

