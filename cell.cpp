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


    this->label = new MyButton(window);
    this->label->setIcon(QIcon(filename));
    this->label->setIconSize(QSize(Cell::width, Cell::height));
    this->label->setFlat(true);

    this->label->setGeometry(this->x * Cell::width, this->y * Cell::height, Cell::width, Cell::height);

    QObject::connect(this->label, SIGNAL(clicked()), this, SLOT(left_click()));
    QObject::connect(this->label, SIGNAL(rightClicked()), this, SLOT(right_click()));
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
    if(this->is_mine){
        cout<<"shit!"<<endl;
        return;
    }
    this->is_clicked = true;
    string str = "";
    str.append("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\");
    str.append(to_string(this->get_number()));
    str.append(".png");
    this->change_picture(QString::fromStdString(str));
    if(this->get_number() == 0){
        vector<Cell*> neighs = this->getNotNullNeighbours();
        for(int i = 0;i < neighs.size();i++){
            neighs[i]->left_click();
        }
    }
}

void Cell::right_click(){
    if(this->is_block){
        return;
    }
    if(this->is_clicked){
        return;
    }
    if(this->is_suspecious){
        this->is_suspecious = false;
        this->change_picture("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\empty.jpg");
    }else if(this->is_flag){
        this->is_flag = false;
        this->is_suspecious = true;
        this->change_picture("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\sus.png");
    }else{
        this->is_flag = true;
        this->change_picture("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\flag.jpg");
    }
}

void Cell::setNeighbours(Cell *up, Cell *down, Cell *right, Cell *left){
    this->up = up;
    this->down = down;
    this->left = left;
    this->right = right;
}

Cell* Cell::getLeft(){
    return this->left;
}

Cell* Cell::getRight(){
    return this->right;
}

Cell* Cell::getUp(){
    return this->up;
}

Cell* Cell::getDown(){
    return this->down;
}

Cell* Cell::getUpLeft(){
    if(this->getUp() == nullptr){
        return nullptr;
    }
    return this->getUp()->getLeft();
}

Cell* Cell::getUpRight(){
    if(this->getUp() == nullptr){
        return nullptr;
    }
    return this->getUp()->getRight();
}

Cell* Cell::getDownLeft(){
    if(this->getDown() == nullptr){
        return nullptr;
    }
    return this->getDown()->getLeft();
}

Cell* Cell::getDownRight(){
    if(this->getDown() == nullptr){
        return nullptr;
    }
    return this->getDown()->getRight();
}

vector<Cell*> Cell::getNotNullNeighbours(){
    vector<Cell*> res;
    if(this->getDown() != nullptr){
        res.push_back(this->getDown());
    }
    if(this->getUp() != nullptr){
        res.push_back(this->getUp());
    }
    if(this->getRight() != nullptr){
        res.push_back(this->getRight());
    }
    if(this->getLeft() != nullptr){
        res.push_back(this->getLeft());
    }
    if(this->getUpLeft() != nullptr){
        res.push_back(this->getUpLeft());
    }
    if(this->getUpRight() != nullptr){
        res.push_back(this->getUpRight());
    }
    if(this->getDownLeft() != nullptr){
        res.push_back(this->getDownLeft());
    }
    if(this->getDownRight() != nullptr){
        res.push_back(this->getDownRight());
    }
    return res;
}

int Cell::get_number(){
    int res = 0;
    vector<Cell*> neighs = this->getNotNullNeighbours();
    for(int i = 0;i < neighs.size();i++){
        if(neighs[i]->getIsMine()){
            res++;
        }
    }
    return res;
}

bool Cell::getIsMine(){
    return this->is_mine;
}
