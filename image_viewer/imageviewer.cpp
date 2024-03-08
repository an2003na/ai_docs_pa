#include "imageViewer.h"

imageViewer::imageViewer(QWidget* parent)
    : QWidget(parent), scaleFactor(1.0), rotationAngle(0.0)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    imageLabel = new QLabel;
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    QToolBar* toolBar = new QToolBar;
    QAction* openAction = new QAction(tr("Open"));
    QAction* zoomInAction = new QAction(tr("Zoom In"));
    QAction* zoomOutAction = new QAction(tr("Zoom Out"));
    QAction* rotateAction = new QAction(tr("Rotate"));

    toolBar->addAction(openAction);
    toolBar->addAction(zoomInAction);
    toolBar->addAction(zoomOutAction);
    toolBar->addAction(rotateAction);

    layout->addWidget(toolBar);
    layout->addWidget(imageLabel);

    connect(openAction, &QAction::triggered, this, &imageViewer::openImage);
    connect(zoomInAction, &QAction::triggered, this, &imageViewer::zoomIn);
    connect(zoomOutAction, &QAction::triggered, this, &imageViewer::zoomOut);
    connect(rotateAction, &QAction::triggered, this, &imageViewer::rotateClockwise);

    setLayout(layout);
}


void imageViewer::openImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if (!fileName.isEmpty()) {
        QPixmap pixmap(fileName);
        if (pixmap.isNull()) {
            QMessageBox::warning(this, tr("Warning"), tr("Unable to open the file!"));
            return;
        }
        imageLabel->setPixmap(pixmap);
        scaleFactor = 1.0;
        rotationAngle = 0.0;
        resize(pixmap.width(), pixmap.height());
    }
}

void imageViewer::zoomIn()
{
    if (!imageLabel->pixmap()) {
        return;
    }
    scaleFactor *= 1.1;
    updateImage();
}

void imageViewer::zoomOut()
{
    if (!imageLabel->pixmap()) {
        return;
    }
    scaleFactor /= 1.1;
    updateImage();
}

void imageViewer::rotateClockwise()
{
    if (!imageLabel->pixmap()) {
        return;
    }
    rotationAngle += 90.0;
    updateImage();
}

void imageViewer::updateImage()
{
    if (!imageLabel->pixmap()) {
        return;
    }
    QPixmap originalPixmap = imageLabel->pixmap();
    QPixmap transformedPixmap = originalPixmap.transformed(QTransform().scale(scaleFactor, scaleFactor).rotate(rotationAngle));
    imageLabel->setPixmap(transformedPixmap);
    //    resize(transformedPixmap.size());
}

imageViewer::~imageViewer()
{
    delete imageLabel;
}
