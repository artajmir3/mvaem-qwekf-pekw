#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class MyButton : public QPushButton
{
 Q_OBJECT

public:
    MyButton(QWidget *parent = Q_NULLPTR);

private slots:
    void mousePressEvent(QMouseEvent *e);

signals:
    void rightClicked();
};

#endif // MYBUTTON_H
