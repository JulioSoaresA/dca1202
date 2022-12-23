#ifndef SELECAOCOR_H
#define SELECAOCOR_H

#include <QWidget>

class SelecaoCor : public QWidget
{
    Q_OBJECT
private:
    int r, g, b, a;
public:
    explicit SelecaoCor(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:

public slots:
    void set_r(int _r);
    void set_g(int _g);
    void set_b(int _b);
    void set_a(int _a);
};

#endif // SELECAOCOR_H
