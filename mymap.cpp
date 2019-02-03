#include "mymap.h"
#include <stdlib.h>
#include <time.h>
#include "emptycell.h"
#include "minecell.h"
#include <iostream>
#include <unistd.h>
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

    for (int i = 0; i < this->width; i++){
        for (int j = 0; j < this->height; j++){
            int r = rand() %10;
            if(r < 8){
                cells[i][j] = new EmptyCell(window, i, j);
            }else{
                cells[i][j] = new MineCell(window, i, j);
            }
            QObject::connect(cells[i][j], SIGNAL(clicked()), this, SLOT(checkWin()));
        }
    }

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
                cout<<"Looooser"<<endl;
                emit end();
                return;
            }
        }
    }
    if (flag) {
        cout<<"wiiiiiiin"<<endl;
        QDialog *w = new QDialog();
        QMovie* movie = new QMovie("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\gif\\win.gif");
        QLabel* label = new QLabel(w);
        label->setMovie(movie);
        movie->start();
        w->resize(350, 600);
        w->show();
        QObject::connect(w, SIGNAL(finished(int)), this, SLOT(runEnd()));
//        Sleep(10000);
//        w->hide();
//        delete w;
//        emit end();
    }
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
