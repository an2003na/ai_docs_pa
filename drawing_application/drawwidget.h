#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>
#include <QVector>
#include <QPainter>
#include <QMouseEvent>
#include <QComboBox>

class drawWidget : public QWidget {
    Q_OBJECT
public:
    explicit drawWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    void shapeSelected(int index);

private:
    enum class Shape { None, Line, Rectangle };

    Shape currentShape;
    QPoint startPoint;
    QPoint endPoint;
    QVector<QLine> lines;
    QVector<QRect> rectangles;
    QComboBox *shapeComboBox;

    void drawShape(QPainter &painter, const QPoint &start, const QPoint &end, Shape shape);
};

#endif // DRAWWIDGET_H
