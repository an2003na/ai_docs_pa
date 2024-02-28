//#include "mainwindow.h"
#include "todolist.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    toDoList w(nullptr);
    w.setWindowTitle("ToDo List");
    w.show();
    return a.exec();
}
