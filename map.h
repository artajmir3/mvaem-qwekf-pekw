#ifndef MAP_H
#define MAP_H

#include "cell.h"
#include "player.h"
#include <vector>
#include <QtWidgets>
using namespace std;

class Map
{
private:
    int width;
    int height;
    vector<vector<Cell*>> cells;
    QWidget *window;
    Player *active_player;
public:
    Map(Player *active_player, QWidget *window, int width, int height/*, vector<vector<bool>> layout*/);
    int getWidth();
    int getHeight();
    vector<vector<Cell*>> getCells();
    Cell* getCell(int x, int y);
};

#endif // MAP_H
