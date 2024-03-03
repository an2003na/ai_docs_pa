#include "drawwidget.h"

drawWidget::drawWidget(QWidget *parent) : QWidget(parent), currentShape(Shape::None) {
    shapeComboBox = new QComboBox(this);
    shapeComboBox->addItem("None");
    shapeComboBox->addItem("Line");
    shapeComboBox->addItem("Rectangle");
    connect(shapeComboBox, QOverload<int>::of(&QComboBox::activated), this, &drawWidget::shapeSelected);
}

void drawWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); // Optional: smooth edges

    // Draw previously stored shapes
    for (const auto &line : lines)
        painter.drawLine(line);
    for (const auto &rect : rectangles)
        painter.drawRect(rect);

    // Draw the current shape being drawn (if any)
    if (currentShape != Shape::None)
        drawShape(painter, startPoint, endPoint, currentShape);
}

void drawWidget::mousePressEvent(QMouseEvent *event) {
    startPoint = event->pos();
    endPoint = event->pos();
    update(); // Trigger repaint to draw the shape being drawn
}

void drawWidget::mouseMoveEvent(QMouseEvent *event) {
    endPoint = event->pos();
    update(); // Trigger repaint to update the shape being drawn
}

void drawWidget::mouseReleaseEvent(QMouseEvent *event) {
    if (currentShape == Shape::Line)
        lines.append(QLine(startPoint, endPoint));
    else if (currentShape == Shape::Rectangle)
        rectangles.append(QRect(startPoint, endPoint));

    startPoint = QPoint();
    endPoint = QPoint();
    update(); // Trigger repaint to draw the final shape
}

void drawWidget::drawShape(QPainter &painter, const QPoint &start, const QPoint &end, Shape shape) {
    if (shape == Shape::Line)
        painter.drawLine(start, end);
    else if (shape == Shape::Rectangle)
        painter.drawRect(QRect(start, end));
}

void drawWidget::shapeSelected(int index) {
    currentShape = static_cast<Shape>(index);
}
