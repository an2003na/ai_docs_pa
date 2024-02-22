#ifndef CLICKCOUNTER_H
#define CLICKCOUNTER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class ClickCounter : public QWidget
{
    Q_OBJECT

public:
    ClickCounter(QWidget *parent = nullptr);
    ~ClickCounter();

public slots:
    void incrementCount();

private:
    int count = 0;
    QPushButton* button;
    QLabel* label;
};
#endif // CLICKCOUNTER_H
