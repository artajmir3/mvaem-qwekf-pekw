#include "emptycell.h"

EmptyCell::EmptyCell()
{

}

EmptyCell::EmptyCell(QWidget *window, int x, int y)
    : NonBlockCell (window, x, y){
    this->is_mine = false;
}
