#include "minecell.h"

MineCell::MineCell()
{

}

MineCell::MineCell(QWidget *window, int x, int y)
    : NonBlockCell (window, x, y){
    this->is_mine = true;
}
