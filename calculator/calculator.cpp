#include "calculator.h"

#include <QGridLayout>
#include <QMessageBox>

Calculator::Calculator(QWidget* parent)
    : QWidget(parent)
{
    set_buttons();
    set_connections();

}

void Calculator::set_buttons()
{
    QGridLayout* button_layout = new QGridLayout(this);

    output_line = new QLineEdit;
    button_layout->addWidget(output_line, 0, 0, 1, 2);

    button_clear = new QPushButton("Clear");
    button_clear->setStyleSheet("background-color : red");
    button_layout->addWidget(button_clear, 0, 2);

    button_7 = new QPushButton("7");
    button_7->setStyleSheet("background-color : gray");
    button_layout->addWidget(button_7, 1, 0);
    button_8 = new QPushButton("8");
    button_8->setStyleSheet("background-color : gray");
    button_layout->addWidget(button_8, 1, 1);
    button_9 = new QPushButton("9");
    button_9->setStyleSheet("background-color : gray");
    button_layout->addWidget(button_9, 1, 2);

    button_4 = new QPushButton("4");
    button_4->setStyleSheet("background-color : gray");
    button_layout->addWidget(button_4, 2, 0);
    button_5 = new QPushButton("5");
    button_5->setStyleSheet("background-color : gray");
    button_layout->addWidget(button_5, 2, 1);
    button_6 = new QPushButton("6");
    button_6->setStyleSheet("background-color : gray");
    button_layout->addWidget(button_6, 2, 2);

    button_1 = new QPushButton("1");
    button_1->setStyleSheet("background-color : gray");
    button_layout->addWidget(button_1, 3, 0);
    button_2 = new QPushButton("2");
    button_2->setStyleSheet("background-color : gray");
    button_layout->addWidget(button_2, 3, 1);
    button_3 = new QPushButton("3");
    button_3->setStyleSheet("background-color : gray");
    button_layout->addWidget(button_3, 3, 2);

    button_0 = new QPushButton("0");
    button_0->setStyleSheet("background-color : gray");
    button_layout->addWidget(button_0, 4, 0);
    button_multiply = new QPushButton("*");
    button_multiply->setStyleSheet("background-color : yellow");
    button_layout->addWidget(button_multiply, 4, 1);
    button_add = new QPushButton("+");
    button_add->setStyleSheet("background-color : yellow");
    button_layout->addWidget(button_add, 4, 2);

    button_divide = new QPushButton("/");
    button_divide->setStyleSheet("background-color : yellow");
    button_layout->addWidget(button_divide, 5, 0);
    button_subtract = new QPushButton("-");
    button_subtract->setStyleSheet("background-color : yellow");
    button_layout->addWidget(button_subtract, 5, 1);
    button_equal = new QPushButton("=");
    button_equal->setStyleSheet("background-color : green");
    button_layout->addWidget(button_equal, 5, 2);

    setLayout(button_layout);
}


void Calculator::set_connections()
{
    connect(button_1, &QPushButton::clicked, this, &Calculator::update_output_line);
    connect(button_2, &QPushButton::clicked, this, &Calculator::update_output_line);
    connect(button_3, &QPushButton::clicked, this, &Calculator::update_output_line);
    connect(button_4, &QPushButton::clicked, this, &Calculator::update_output_line);
    connect(button_5, &QPushButton::clicked, this, &Calculator::update_output_line);
    connect(button_6, &QPushButton::clicked, this, &Calculator::update_output_line);
    connect(button_7, &QPushButton::clicked, this, &Calculator::update_output_line);
    connect(button_8, &QPushButton::clicked, this, &Calculator::update_output_line);
    connect(button_9, &QPushButton::clicked, this, &Calculator::update_output_line);
    connect(button_0, &QPushButton::clicked, this, &Calculator::update_output_line);

    connect(button_add, &QPushButton::clicked, this, &Calculator::choose_operation);
    connect(button_subtract, &QPushButton::clicked, this, &Calculator::choose_operation);
    connect(button_multiply, &QPushButton::clicked, this, &Calculator::choose_operation);
    connect(button_divide, &QPushButton::clicked, this, &Calculator::choose_operation);

    connect(button_equal, &QPushButton::clicked, this, &Calculator::equal);

    connect(button_clear, &QPushButton::clicked, this, &Calculator::clear_calculator);
}


void Calculator::update_output_line()
{
    QPushButton* clicked_button = qobject_cast<QPushButton*>(sender());
    if(clicked_button) {
        QString button_text = clicked_button->text();
        output_line->setText(output_line->text() + button_text);
    }
}

void Calculator::get_number1()
{
    QString str1 = output_line->text();
    num1 = str1.toInt();
    output_line->clear();
}

void Calculator::get_number2()
{
    QString str1 = output_line->text();
    num2 = str1.toInt();
    output_line->clear();
}

void Calculator::equal()
{
    get_number2();
    int result = 0;
    if ("+" == op) {
        result = num1 + num2;
    } else if ("-" == op) {
        result = num1 - num2;
    } else if ("*" == op) {
        result = num1 * num2;
    } else if ("/" == op) {
        if (num2 == 0) {
            QMessageBox::warning(this, "Warning", "Can't divide by zero!");
            return;
        }
        result = num1 / num2;
    }
    output_line->setText(QString::number(result));
}

void Calculator::choose_operation()
{
    get_number1();
    QPushButton* op_button = qobject_cast<QPushButton*>(sender());
    if (op_button) {
        QString str_op = op_button->text();
        if ("+" == str_op) {
            op = "+";
        } else if ("-" == str_op) {
            op = "-";
        } else if ("*" == str_op) {
            op = "*";
        } else if ("/" == str_op) {
            op = "/";
        }
    }
}

void Calculator::clear_calculator()
{
    output_line->clear();
    num1 = 0;
    num2 = 0;
    op = "";
}

Calculator::~Calculator()
{
    delete button_1;
    delete button_2;
    delete button_3;
    delete button_4;
    delete button_5;
    delete button_6;
    delete button_7;
    delete button_8;
    delete button_9;
    delete button_0;
    delete button_add;
    delete button_subtract;
    delete button_multiply;
    delete button_divide;
    delete button_equal;
    delete output_line;
}
