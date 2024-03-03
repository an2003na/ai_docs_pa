#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QTextEdit>
#include <QMenuBar>

class textEditor : public QWidget
{
    Q_OBJECT
public:
    textEditor(QWidget*);
    ~textEditor();

private slots:
    void open_file();
    void save_file();
    void exit_app();

private:
    QMenuBar* menu;
    QTextEdit* editing_area;
};

#endif // TEXTEDITOR_H
