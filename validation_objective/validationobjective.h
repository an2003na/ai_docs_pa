#ifndef VALIDATIONOBJECTIVE_H
#define VALIDATIONOBJECTIVE_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>

class ValidationObjective : public QMainWindow
{
    Q_OBJECT

public:
    ValidationObjective(QWidget *parent = nullptr);
    ~ValidationObjective();

private slots:
    void check_line();

private:
    QLineEdit* line_fname;
    QLineEdit* line_lname;
    QLineEdit* line_phone;
    QLineEdit* line_city;
    QPushButton* button_submit;
    QFormLayout* layout;
};
#endif // VALIDATIONOBJECTIVE_H
