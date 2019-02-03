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

Cell::Cell(QWidget *window, int x, int y, QIcon icon){
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
    this->label->setIcon(icon);
    this->label->setIconSize(QSize(Cell::width, Cell::height));
    this->label->setFlat(true);

    this->label->setGeometry(this->x * Cell::width, this->y * Cell::height, Cell::width, Cell::height);

    QObject::connect(this->label, SIGNAL(clicked()), this, SLOT(left_click()));
    QObject::connect(this->label, SIGNAL(rightClicked()), this, SLOT(right_click()));
}

void Cell::change_picture(QIcon icon){
//    this->image->load(filename);
//    this->label->setPixmap(QPixmap::fromImage(*image));


    this->label->setIcon(icon);
}

void Cell::left_click(){
    if(this->is_block){
        return;
    }
    if(this->is_clicked){
        return;
    }
    this->is_clicked = true;
    if(this->is_mine){
        emit clicked();
        return;
    }
    string str = "";
    str.append("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\");
    str.append(to_string(this->get_number()));
    str.append(".png");
//    this->change_picture(QString::fromStdString(str));
    this->change_picture(Cell::getNums()[this->get_number()]);
    if(this->get_number() == 0){
        vector<Cell*> neighs = this->getNotNullNeighbours();
        for(int i = 0;i < neighs.size();i++){
            neighs[i]->left_click();
        }
    }
    emit clicked();
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
//        this->change_picture("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\empty.jpg");
        this->change_picture(Cell::getEmpty());
    }else if(this->is_flag){
        this->is_flag = false;
        this->is_suspecious = true;
//        this->change_picture("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\sus.png");
        this->change_picture(Cell::getSus());
    }else{
        this->is_flag = true;
//        this->change_picture("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\flag.jpg");
        this->change_picture(Cell::getFlag());
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

bool Cell::getIsBlock(){
    return this->is_block;
}

bool Cell::getIsClicked(){
    return this->is_clicked;
}

void Cell::clear(){
    this->label->deleteLater();
}

void Cell::initiate(){

}



QIcon Cell::getBlock(){
    static QIcon block = QIcon("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\block.jpg");
    return block;
}
QIcon Cell::getEmpty(){
    static QIcon empty = QIcon("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\empty.jpg");
    return empty;
}
QIcon Cell::getFlag(){
    static QIcon flag = QIcon("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\flag.jpg");
    return flag;
}
QIcon Cell::getSus(){
    static QIcon sus = QIcon("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\sus.png");
    return sus;
}

QIcon* Cell::getNums(){
    static QIcon nums[9] = {QIcon("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\0.png"),
                           QIcon("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\1.png"),
                           QIcon("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\2.png"),
                           QIcon("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\3.png"),
                           QIcon("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\4.png"),
                           QIcon("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\5.png"),
                           QIcon("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\6.png"),
                           QIcon("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\7.png"),
                           QIcon("C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\8.png")};
    return nums;
}
