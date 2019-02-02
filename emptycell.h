#ifndef EMPTYCELL_H
#define EMPTYCELL_H

#include "nonblockcell.h"

class EmptyCell : NonBlockCell
{
public:
    EmptyCell();
    EmptyCell(QWidget *window, int x, int y);
    int get_number();
};

#endif // EMPTYCELL_H
