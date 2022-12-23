#include "selecaocor.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>

SelecaoCor::SelecaoCor(QWidget *parent) : QWidget{parent}
{
    r = g = b = 0;
    a = 255;
}

void SelecaoCor::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    brush.setColor(QColor(r, g, b, a));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(0, 0, 0, 70));
    pen.setWidth(2);

    painter.setBrush(brush);
    painter.setPen(pen);

    QRectF rectangle(0,0,width(),height());
    painter.drawRoundedRect(rectangle, 10.0, 10.0);
}

void SelecaoCor::set_r(int _r) { r = _r; repaint(); }
void SelecaoCor::set_g(int _g) { g = _g; repaint(); }
void SelecaoCor::set_b(int _b) { b = _b; repaint(); }
void SelecaoCor::set_a(int _a) { a = _a; repaint(); }
