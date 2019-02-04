#include "timerboard.h"

TimerBoard::TimerBoard(QWidget *parent):
    ScoreBoard (parent, 0)
{
    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(add()));
    timer->start(1000);
}
