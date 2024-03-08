#ifndef IMAGEVIEWER_HPP
#define IMAGEVIEWER_HPP

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>
#include <QFileDialog>
#include <QAction>
#include <QToolBar>
#include <QMessageBox>

class imageViewer : public QWidget
{
    Q_OBJECT

public:
    imageViewer(QWidget* parent = nullptr);
    ~imageViewer();

private slots:
    void openImage();
    void zoomIn();
    void zoomOut();
    void rotateClockwise();

private:
    QLabel* imageLabel;
    qreal scaleFactor;
    qreal rotationAngle;

    void updateImage();
};

#endif // IMAGEVIEWER_HPP
