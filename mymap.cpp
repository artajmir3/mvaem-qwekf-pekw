#include "mymap.h"
#include <stdlib.h>
#include <time.h>
#include "emptycell.h"
#include "minecell.h"
#include <iostream>
#include <unistd.h>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <scoreboard.h>
#include "timerboard.h"
using namespace std;

MyMap::MyMap(Player *active_player, QWidget *window, int width, int height/*, vector<vector<bool>> layout*/)
    :
    cells(width, vector<Cell*>(height, nullptr))
{

    srand(time(0));
    this->active_player = active_player;
    this->window = window;
    this->width = width;
    this->height = height;


    QWidget *mapWindow = new QWidget(window);
    mapWindow->setGeometry(0, 150, this->width*Cell::width, this->height*Cell::height);

    QLabel *header = new QLabel(window);
    header->setGeometry(0, 0, this->width*Cell::width, 150);
    QPixmap pic("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\simple.png");
    QPixmap scaled=pic.scaled ( this->width*Cell::width, 150, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    header->setPixmap(scaled);

    QLabel *smile = new QLabel(window);
    smile->setGeometry(this->width*Cell::width / 2 - 50, 25, 100, 100);
    QPixmap pic1("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\smile.jpg");
    QPixmap scaled1=pic1.scaled ( 100, 100, Qt::IgnoreAspectRatio, Qt::FastTransformation );
    smile->setPixmap(scaled1);

    int totMine = 0;

    for (int i = 0; i < this->width; i++){
        for (int j = 0; j < this->height; j++){
            int r = rand() %8;
            if(r < 6){
                cells[i][j] = new EmptyCell(mapWindow, i, j);
            }else{
                cells[i][j] = new MineCell(mapWindow, i, j);
                totMine++;
            }
            QObject::connect(cells[i][j], SIGNAL(clicked()), this, SLOT(checkWin()));
        }
    }

    ScoreBoard *flags = new ScoreBoard(window, totMine);
    flags->setGeometry(30, 30, 150, 90);

    TimerBoard *timer = new TimerBoard(window);
    timer->setGeometry(this->width*Cell::width - 150 - 30, 30, 150, 90);

    for (int i = 0; i < this->width; i++){
        for (int j = 0; j < this->height; j++){
            Cell *up = nullptr;
            Cell *down = nullptr;
            Cell *right = nullptr;
            Cell *left = nullptr;
            if(i > 0){
                left = this->cells[i - 1][j];
            }
            if(j > 0){
                up = this->cells[i][j - 1];
            }
            if(i < this->width - 1){
                right = this->cells[i + 1][j];
            }
            if(j < this->height - 1){
                down = this->cells[i][j + 1];
            }
            this->cells[i][j]->setNeighbours(up, down, right, left);
            QObject::connect(this->cells[i][j], SIGNAL(addFlag()), flags, SLOT(sub()));
            QObject::connect(this->cells[i][j], SIGNAL(delFlag()), flags, SLOT(add()));
        }
    }
}

void MyMap::checkWin(){
    bool flag = true;
    for (int i = 0; i < this->width; i++){
        for (int j = 0; j < this->height; j++){
            Cell* cell = this->cells[i][j];
            if(!cell->getIsBlock() && !cell->getIsMine() && !cell->getIsClicked()){
                flag = false;
            }
            if(cell->getIsMine() && cell->getIsClicked()){
                this->loose();
//                emit end();
                return;
            }
        }
    }
    if (flag) {
        this->win();
//        Sleep(10000);
//        w->hide();
//        delete w;
//        emit end();
    }
}

void MyMap::win(){
    QDialog *w = new QDialog();
    QMovie* movie = new QMovie("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\gif\\win.gif");
    QLabel* label = new QLabel(w);
    label->setMovie(movie);
    movie->start();
    w->resize(350, 600);
    w->show();
    QObject::connect(w, SIGNAL(finished(int)), this, SLOT(runEnd()));

}

void MyMap::loose(){
    for (int i = 0; i < this->width; i++){
        for (int j = 0; j < this->height; j++){
            this->cells[i][j]->reveal();
        }
    }
    QDialog *w = new QDialog();
    QVideoWidget *ww = new QVideoWidget(w);
    QMediaPlayer *player = new QMediaPlayer(ww);
    player->setMedia(QUrl::fromLocalFile("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\video\\Loser.mp4"));
    player->play();
    w->resize(1000, 500);
    ww->setGeometry(0, 0, 1000, 500);
    w->show();
    player->setVideoOutput(ww);
    QObject::connect(w, SIGNAL(finished(int)), this, SLOT(runEnd()));
}

void MyMap::runEnd(){
    emit end();
}

void MyMap::clear(){
    for (int i = 0; i < this->width; i++){
        for (int j = 0; j < this->height; j++){
//            this->cells[i][j]->clear();
            delete this->cells[i][j];
        }
    }
}
