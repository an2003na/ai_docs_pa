#ifndef CLOCKINTERFACE_H
#define CLOCKINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QTimer>

class clockInterface : public QWidget
{
public:
    clockInterface(QWidget* parent = nullptr);
    ~clockInterface();

private slots:
    void update_display();

private:
    QLabel* title;
    QLabel* current_time_label;

    QTimer* timer;

};

#endif // CLOCKINTERFACE_H
