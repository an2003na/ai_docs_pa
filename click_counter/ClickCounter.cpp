#include "clickcounter.h"

#include <QVBoxLayout>

ClickCounter::ClickCounter(QWidget *parent)
    : QWidget(parent)
{
    button = new QPushButton("Click button");
    label = new QLabel("Click count: 0");

    QVBoxLayout* v_lay = new QVBoxLayout;
    v_lay->addWidget(label);
    v_lay->addWidget(button);

    connect(button, SIGNAL(clicked(bool)), this, SLOT(incrementCount()));
    setLayout(v_lay);
    //delete v_lay;
}

void ClickCounter::incrementCount()
{
    count++;
    label->setText("Click count: " + QString::number(count));
}


ClickCounter::~ClickCounter()
{
    delete button;
    delete label;
}
