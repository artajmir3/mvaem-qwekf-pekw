#ifndef BLOCKCELL_H
#define BLOCKCELL_H

#include "cell.h"

class BlockCell : public Cell
{
public:
    BlockCell();
    BlockCell(QWidget *window, int x, int y);
};

#endif // BLOCKCELL_H
