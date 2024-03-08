#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QWidget>
#include <QLabel>
#include <QToolBar>
#include <QPixmap>

class imageViewer : public QWidget
{
public:
    imageViewer(QWidget* p = nullptr);

    ~imageViewer();
private slots:
    void open_image();
    void zoomin_image();
    void zoomout_image();
    void rotate_image();

private:
    QLabel* image;
    QToolBar* operations;
    qreal scale_factor = 1.0;
    qreal rotation_angle = 0.0;
};

#endif // IMAGEVIEWER_H
