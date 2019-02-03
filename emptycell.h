#ifndef EMPTYCELL_H
#define EMPTYCELL_H

#include "nonblockcell.h"

class EmptyCell : public NonBlockCell
{
public:
    EmptyCell();
    EmptyCell(QWidget *window, int x, int y);
};

#endif // EMPTYCELL_H
