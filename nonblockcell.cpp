#include "nonblockcell.h"
#include <iostream>
using namespace std;

NonBlockCell::NonBlockCell()
{

}

NonBlockCell::NonBlockCell(QWidget *window, int x, int y)
//    : Cell(window, x, y, "C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\empty.jpg"){
    : Cell(window, x, y, Cell::getEmpty()){
    this->is_block = false;
//    QObject::connect(label, &QPushButton::clicked, left_click);
//    this->change_picture("C:\\Users\\ASUS\\Desktop\\Untitled11.png");
}
