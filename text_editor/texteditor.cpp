#include "texteditor.h"
#include <QVBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QAction>

textEditor::textEditor(QWidget* parent)
    :QWidget(parent)
{
    menu = new QMenuBar();
    QMenu* command_menu = new QMenu();
    menu->addMenu(command_menu);

    QAction* action_open = new QAction("Open");
    connect(action_open, &QAction::triggered, this, &textEditor::open_file);
    menu->addAction(action_open);

    QAction* action_save = new QAction("Save");
    connect(action_save, &QAction::triggered, this, &textEditor::save_file);
    menu->addAction(action_save);

    QAction* action_exit = new QAction("Exit");
    connect(action_exit, &QAction::triggered, this, &textEditor::exit_app);
    menu->addAction(action_exit);

    menu->setStyleSheet(" background-color : gray; color : black");

    QVBoxLayout* lay = new QVBoxLayout;
    lay->addWidget(menu);

    editing_area = new QTextEdit;

    lay->addWidget(editing_area);

    setLayout(lay);
}


void textEditor::open_file()
{
    QString file_name = QFileDialog::getOpenFileName(nullptr, QObject::tr("Open file"), QDir::homePath(), QObject::tr("All files(*)"));
    if(!file_name.isEmpty()) {
        QFile file(file_name);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::warning(nullptr, QObject::tr("Error"), QObject::tr("Could not open file"));
            return;
        }
        QTextStream in(&file);
        editing_area->setText(in.readAll());
        file.close();
    } else {
        QMessageBox::warning(nullptr, QObject::tr("Warning"), QObject::tr("You did not select any file"));
    }
}

void textEditor::save_file()
{
    QString file_name = QFileDialog::getSaveFileName(nullptr, QObject::tr("Save file"), QDir::homePath(), QObject::tr("All files(*)"));
    if(!file_name.isEmpty()) {
        QFile file(file_name);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(nullptr, QObject::tr("Error"), QObject::tr("Could not write to file"));
            return;
        }
        QTextStream out(&file);
        out << editing_area->toPlainText();
        file.close();
        editing_area->clear();
        QMessageBox::information(nullptr, QObject::tr("File saved"), QObject::tr("You saved file: ") + file_name);
    } else {
        QMessageBox::warning(nullptr, QObject::tr("Warning"), QObject::tr("You did not specify a file name"));
    }
}


void textEditor::exit_app()
{
    this->close();
}


textEditor::~textEditor()
{
    delete menu;
    delete editing_area;
}
