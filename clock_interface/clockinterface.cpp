#include "clockinterface.h"
#include <QTime>
#include <QString>
#include <QVBoxLayout>


clockInterface::clockInterface(QWidget* parent)
    :QWidget(parent)
{
    QVBoxLayout* main_layout = new QVBoxLayout(this);

    title = new QLabel("Current time");
    title->setStyleSheet("background-color : gray");
    main_layout->addWidget(title);

    current_time_label = new QLabel;
    main_layout->addWidget(current_time_label);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&clockInterface::update_display));
    timer->start(1000);

    setLayout(main_layout);
}

void clockInterface::update_display()
{
    QString curr_time = QTime::currentTime().toString();
    current_time_label->setText(curr_time);
}

clockInterface::~clockInterface()
{
    delete current_time_label;
    delete timer;
}
