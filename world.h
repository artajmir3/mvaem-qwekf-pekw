#ifndef WORLD_H
#define WORLD_H

#include "map.h"
#include "player.h"
#include "vector"
using namespace std;

class World
{
private:
    //Map map;
    vector<Player*> player;
public:
    World();
};

#endif // WORLD_H
