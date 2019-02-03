#include "mybutton.h"

#include <QMouseEvent>

MyButton::MyButton(QWidget * parent) :
    QPushButton(parent)
{
}
void MyButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::RightButton)
        emit rightClicked();

    //this forwards the event to the QPushButton
    QPushButton::mousePressEvent(e);
}
