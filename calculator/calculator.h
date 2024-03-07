#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QString>

class Calculator : public QWidget
{
    Q_OBJECT
public:
    Calculator(QWidget* parent = nullptr);
    void set_buttons();
    void set_connections();
    void get_number1();
    void get_number2();
    ~Calculator();

private slots:
    void update_output_line();
    void equal();
    void choose_operation();
    void clear_calculator();

private:
    QLineEdit* output_line;
    QString op = "";
    int num1 = 0;
    int num2 = 0;

    QPushButton* button_clear;
    QPushButton* button_1;
    QPushButton* button_2;
    QPushButton* button_3;
    QPushButton* button_4;
    QPushButton* button_5;
    QPushButton* button_6;
    QPushButton* button_7;
    QPushButton* button_8;
    QPushButton* button_9;
    QPushButton* button_0;
    QPushButton* button_add;
    QPushButton* button_subtract;
    QPushButton* button_multiply;
    QPushButton* button_divide;
    QPushButton* button_equal;
};

#endif // CALCULATOR_H
