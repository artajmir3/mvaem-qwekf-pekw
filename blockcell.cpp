#include "blockcell.h"

BlockCell::BlockCell()
{

}

BlockCell::BlockCell(QWidget *window, int x, int y)
    : Cell(window, x, y, "C:\\Users\\ASUS\\Documents\\jgkldfgjerlg\\media\\images\\block.jpg"){
    this->is_block = true;
}
