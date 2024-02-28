#ifndef TODOLIST_H
#define TODOLIST_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>

class toDoList : public QWidget
{
    Q_OBJECT
public:
    toDoList(QWidget*);
    ~toDoList();

private slots:
    void add_task();
    void remove_task();

private:
    QLineEdit* input_line;
    QListWidget* task_list;
    QPushButton* add_button;
    QPushButton* remove_button;
};

#endif // TODOLIST_H
