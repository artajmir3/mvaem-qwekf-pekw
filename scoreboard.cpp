#include "scoreboard.h"

ScoreBoard::ScoreBoard(QWidget *parent) : QWidget(parent)
{

}

int ScoreBoard::digitWidth = 50;
int ScoreBoard::digitHeight = 90;

ScoreBoard::ScoreBoard(QWidget *parent, int number) : QWidget (parent){
    this->number = number;
    this->labels[0] = new QPushButton(this);
    this->labels[1] = new QPushButton(this);
    this->labels[2] = new QPushButton(this);
    this->labels[0]->setFlat(true);
    this->labels[1]->setFlat(true);
    this->labels[2]->setFlat(true);
    this->labels[0]->setGeometry(0, 0, ScoreBoard::digitWidth, ScoreBoard::digitHeight);
    this->labels[1]->setGeometry(ScoreBoard::digitWidth, 0, ScoreBoard::digitWidth, ScoreBoard::digitHeight);
    this->labels[2]->setGeometry(ScoreBoard::digitWidth * 2, 0, ScoreBoard::digitWidth, ScoreBoard::digitHeight);
    this->labels[0]->setIconSize(QSize(ScoreBoard::digitWidth, ScoreBoard::digitHeight));
    this->labels[1]->setIconSize(QSize(ScoreBoard::digitWidth, ScoreBoard::digitHeight));
    this->labels[2]->setIconSize(QSize(ScoreBoard::digitWidth, ScoreBoard::digitHeight));
    this->update();
}

void ScoreBoard::add(){
    this->number++;
    this->update();
}

void ScoreBoard::sub(){
    this->number--;
    this->update();
}

QIcon* ScoreBoard::getIcons(){
    static QIcon icons[11] = {QIcon("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\7Segment0.png"),
                             QIcon("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\7Segment1.png"),
                             QIcon("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\7Segment2.png"),
                             QIcon("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\7Segment3.png"),
                             QIcon("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\7Segment4.png"),
                             QIcon("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\7Segment5.png"),
                             QIcon("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\7Segment6.png"),
                             QIcon("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\7Segment7.png"),
                             QIcon("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\7Segment8.png"),
                             QIcon("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\7Segment9.png"),
                             QIcon("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\7Segment-.png"),
                            };
    return icons;
}

void ScoreBoard::update(){
    int num = this->number;
    if(num < 0){
        num = -num;
    }
    this->labels[2]->setIcon(ScoreBoard::getIcons()[num % 10]);
    this->labels[1]->setIcon(ScoreBoard::getIcons()[(num / 10) % 10]);
    this->labels[0]->setIcon(ScoreBoard::getIcons()[(num / 100) % 10]);
    if(this->number < 0){
        this->labels[0]->setIcon(ScoreBoard::getIcons()[10]);
    }
}
