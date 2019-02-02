#ifndef NONBLOCKCELL_H
#define NONBLOCKCELL_H

#include "cell.h"

class NonBlockCell: public Cell
{
protected:
public:
    NonBlockCell();
    NonBlockCell(QWidget *window, int x, int y);
};

#endif // NONBLOCKCELL_H
