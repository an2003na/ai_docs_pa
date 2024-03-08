#include "imageviewer.h"

#include <QVBoxLayout>
#include <QPixmap>
#include <QFileDialog>
#include <QMessageBox>
#include <QAction>
#include <QTransform>

imageViewer::imageViewer(QWidget* p)
    :QWidget(p)
{
    QVBoxLayout* main_layout = new QVBoxLayout;

    operations = new QToolBar;

    QAction* action_open = new QAction("Open");
    operations->addAction(action_open);

    QAction* action_zoomin = new QAction("Zoom In");
    operations->addAction(action_zoomin);

    QAction* action_zoomout = new QAction("Zoom out");
    operations->addAction(action_zoomout);

    QAction* action_rotate = new QAction("Rotate");
    operations->addAction(action_rotate);

    main_layout->addWidget(operations);
    image = new QLabel;
    connect(action_open, &QAction::triggered, this, &imageViewer::open_image);
    connect(action_zoomin, &QAction::triggered, this, &imageViewer::zoomin_image);
    connect(action_zoomout, &QAction::triggered, this, &imageViewer::zoomout_image);
    connect(action_rotate, &QAction::triggered, this, &imageViewer::rotate_image);

    main_layout->addWidget(image);

    setLayout(main_layout);
}

void imageViewer::open_image()
{
    QString image_path = QFileDialog::getOpenFileName(nullptr, "Open image", "", "Images (*.png *.jpg *.jpeg *.bmp *.gif)");

    if (!image_path.isEmpty()) {
        QPixmap new_pixmap(image_path);
        if (new_pixmap.isNull()) {
            QMessageBox::warning(nullptr, "Warning", "Unable to open the file!");
            return;
        }

        // Clear the existing image
        image->clear();

        // Set the new pixmap and reset scale_factor and rotation_angle
        image->setPixmap(new_pixmap);
    }
}

void imageViewer::zoomin_image()
{
    QPixmap current_pixmap = image->pixmap();
    if (!current_pixmap.isNull()) {
        qreal current_scale_factor = scale_factor;
        scale_factor *= 1.1;
        QPixmap scaled_pixmap = current_pixmap.scaled(current_pixmap.width() * scale_factor, current_pixmap.height() * scale_factor, Qt::KeepAspectRatio);
        image->setPixmap(scaled_pixmap);
        if (current_scale_factor != scale_factor) {
            rotation_angle = 0.0; // Reset rotation angle if scaling changes
        }
    }
}

void imageViewer::zoomout_image()
{
    QPixmap current_pixmap = image->pixmap();
    if (!current_pixmap.isNull()) {
        qreal current_scale_factor = scale_factor;
        scale_factor /= 1.1;
        QPixmap scaled_pixmap = current_pixmap.scaled(current_pixmap.width() * scale_factor, current_pixmap.height() * scale_factor, Qt::KeepAspectRatio);
        image->setPixmap(scaled_pixmap);
        if (current_scale_factor != scale_factor) {
            rotation_angle = 0.0; // Reset rotation angle if scaling changes
        }
    }
}

void imageViewer::rotate_image()
{
    QPixmap current_pixmap = image->pixmap();
    if (!current_pixmap.isNull()) {
        rotation_angle += 90;
        QTransform transform;
        transform.rotate(rotation_angle);
        QPixmap rotated_pixmap = current_pixmap.transformed(transform);
        image->setPixmap(rotated_pixmap);
        scale_factor = 1.0; // Reset scale factor after rotation
    }
}


/*
void imageViewer::open_image()
{
    QString image_path = QFileDialog::getOpenFileName(nullptr, "Open image",  "", "Images (*.png *.jpg *.jpeg *.bmp *.gif)");
  //  if(!image_path.isEmpty()) {
        QPixmap new_pixmap(image_path);
        if(new_pixmap.isNull()) {
            QMessageBox::warning(nullptr, "Warning", "Unable to open the file!");
            return;
        }
        image->setPixmap(new_pixmap);
        scale_factor = 1.0;
        rotation_angle = 0.0;
  //  }
}
*/
/*void imageViewer::open_image()
{
    QString image_path = QFileDialog::getOpenFileName(nullptr, "Open image",  "", "Images (*.png *.jpg *.jpeg *.bmp *.gif)");
    if(image_path.isEmpty()) {
        QMessageBox::warning(nullptr, "Warning", "There is no file selected!");
    }
    QPixmap new_pixmap(image_path);
    if(new_pixmap.isNull()) {
        QMessageBox::warning(nullptr, "Warning", "Unable to open the file!");
    }
    image->setPixmap(new_pixmap);
}

*/


/*

void imageViewer::zoomin_image()
{

}

void imageViewer::zoomout_image()
{

}

void imageViewer::rotate_image()
{

}

*/
/*
void imageViewer::zoomin_image()
{
    if (!pixmap.isNull()) {
        scale_factor *= 1.1;
        QPixmap scaled_pixmap = pixmap.scaled(pixmap.width() * scale_factor, pixmap.height() * scale_factor, Qt::KeepAspectRatio);
        image->setPixmap(scaled_pixmap);
    }
}

void imageViewer::zoomout_image()
{
    if (!pixmap.isNull()) {
        scale_factor /= 1.1;
        QPixmap scaled_pixmap = pixmap.scaled(pixmap.width() * scale_factor, pixmap.height() * scale_factor, Qt::KeepAspectRatio);
        image->setPixmap(scaled_pixmap);
    }
}

void imageViewer::rotate_image()
{
    if (!pixmap.isNull()) {
        rotation_angle += 90;
        QTransform transform;
        transform.rotate(rotation_angle);
        QPixmap rotated_pixmap = pixmap.transformed(transform);
        image->setPixmap(rotated_pixmap);
    }
}

*/
imageViewer::~imageViewer()
{
    delete image;
    delete operations;
}
