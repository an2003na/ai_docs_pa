#include "todolist.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>

toDoList::toDoList(QWidget* parent)
    :QWidget(parent)
{
    input_line = new QLineEdit();
    input_line->setStyleSheet("; color : blue");

    add_button = new QPushButton("Add");
    add_button->setStyleSheet("background-color : blue; color : white");

    QHBoxLayout* vert_layout = new QHBoxLayout;
    vert_layout->addWidget(input_line);
    connect(add_button, &QPushButton::clicked, this, &toDoList::add_task);
    vert_layout->addWidget(add_button);

    QVBoxLayout* main_layout = new QVBoxLayout;
    main_layout->addLayout(vert_layout);

    task_list = new QListWidget;

    remove_button = new QPushButton("Remove");
    remove_button->setStyleSheet("background-color : red; ");

    main_layout->addWidget(task_list);
    connect(remove_button, &QPushButton::clicked, this, &toDoList::remove_task);
    main_layout->addWidget(remove_button);

    setLayout(main_layout);
}


void toDoList::add_task() {
    QString task = input_line->text().trimmed();
    task_list->addItem(task);
    input_line->clear();
}


void toDoList::remove_task() {
    int row = task_list->currentRow();
    if(row >= 0) {
        delete task_list->takeItem(row);
    }
}


toDoList::~toDoList()
{
    delete input_line;
    delete task_list;
    delete add_button;
    delete remove_button;
}
