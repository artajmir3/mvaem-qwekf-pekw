#ifndef MAP_H
#define MAP_H

#include "cell.h"
#include "player.h"

class Map
{
private:
    int width;
    int height;
    Player active_player;
public:
    Map(Player active_player);
};

#endif // MAP_H
