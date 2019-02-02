#include "blockcell.h"

BlockCell::BlockCell()
{

}

BlockCell::BlockCell(QWidget *window, int x, int y)
    : Cell(window, x, y, "C:\\Users\\ASUS\\Desktop\\Untitled11.png"){
    this->is_block = true;
}
