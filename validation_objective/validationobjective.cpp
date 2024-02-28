#include "validationobjective.h"
#include <QMessageBox>

ValidationObjective::ValidationObjective(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget* central_widget = new QWidget(this);
    setCentralWidget(central_widget);

    line_fname = new QLineEdit();
    line_lname = new QLineEdit();
    line_phone = new QLineEdit();
    line_city = new QLineEdit();

    button_submit = new QPushButton("Submit");

    layout = new QFormLayout();

    layout->addRow("First name: ", line_fname);
    layout->addRow("Last name: ", line_lname);
    layout->addRow("Phone number: ", line_phone);
    layout->addRow("City: ", line_city);
    layout->addWidget(button_submit);

    connect(button_submit, SIGNAL(clicked(bool)), this, SLOT(check_line()));
    central_widget->setLayout(layout);

}

void ValidationObjective::check_line()
{
    QList<QLineEdit*> line_edits = findChildren<QLineEdit*>();
    bool is_emp = false;
    for(QLineEdit* line_edit : line_edits) {
        if(line_edit->text().isEmpty()) {
            is_emp = true;
        }
    }

    if(is_emp) {
        QMessageBox::critical(this, "Error", "There are empty fields!!!");
    } else {
        QMessageBox::information(this, "Good", "All fields are completed.");
    }
}


ValidationObjective::~ValidationObjective()
{
}

