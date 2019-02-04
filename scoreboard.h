#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class ScoreBoard : public QWidget
{
    Q_OBJECT
private:
    int number;
    QPushButton *labels[3];
public:
    explicit ScoreBoard(QWidget *parent = nullptr);
    ScoreBoard(QWidget *parent, int number);
    void update();
    static QIcon* getIcons();
    static int digitWidth;
    static int digitHeight;
signals:

public slots:
    void add();
    void sub();
};

#endif // SCOREBOARD_H
