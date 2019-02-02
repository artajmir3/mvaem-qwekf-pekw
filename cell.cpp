#include "cell.h"

#include <iostream>
using namespace std;

Cell::Cell()
{

}

Cell::~Cell(){

}

int Cell::width = 50;
int Cell::height = 50;

Cell::Cell(QWidget *window, int x, int y, QString filename){
    this->is_clicked = false;
    this->is_flag = false;
    this->is_suspecious = false;

    this->window = window;
    this->x = x;
    this->y = y;
//    this->image = new QImage(filename);
//    this->label = new QLabel(window);
//    this->label->setPixmap(QPixmap::fromImage(*image));


    this->label = new QPushButton(window);
    this->label->setIcon(QIcon(filename));
    this->label->setIconSize(QSize(Cell::width, Cell::height));
    this->label->setFlat(true);

    this->label->setGeometry(this->x * Cell::width, this->y * Cell::height, Cell::width, Cell::height);

    QObject::connect(this->label, SIGNAL(clicked()), this, SLOT(left_click()));
}

void Cell::change_picture(QString filename){
//    this->image->load(filename);
//    this->label->setPixmap(QPixmap::fromImage(*image));


    this->label->setIcon(QIcon(filename));
}

void Cell::left_click(){
    if(this->is_block){
        return;
    }
    if(this->is_clicked){
        return;
    }
    this->is_clicked = true;
    this->change_picture("C:\\Users\\ASUS\\Desktop\\Untitled33.png");
}

void Cell::right_click(){
    cout<<"ok"<<endl;
}

void Cell::click(QMouseEvent *event){
    if(event->button() == Qt::RightButton){
        this->right_click();
    }
    else{
        this->left_click();
    }
}
