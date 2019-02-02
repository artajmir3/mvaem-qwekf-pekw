#ifndef MINECELL_H
#define MINECELL_H

#include "nonblockcell.h"

class MineCell : public NonBlockCell
{
public:
    MineCell();
    MineCell(QWidget *window, int x, int y);
};

#endif // MINECELL_H
