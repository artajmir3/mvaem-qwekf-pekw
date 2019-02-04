#ifndef TIMERBOARD_H
#define TIMERBOARD_H

#include "scoreboard.h"
#include <QWidget>
#include <QTimer>

class TimerBoard : public ScoreBoard
{

private:
    QTimer *timer;

public:
    TimerBoard(QWidget *parent);
};

#endif // TIMERBOARD_H
