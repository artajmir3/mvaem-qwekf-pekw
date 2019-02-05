#ifndef WORLD_H
#define WORLD_H

#include <QtWidgets>
#include "mymap.h"
#include "player.h"
#include <vector>
using namespace std;

class World : public QObject
{
    Q_OBJECT
private:
    MyMap *map;
    QWidget *window;
    int width;
    int height;
    vector<Player*> players;
    Player* active_player;

public:
    World();
    void askSize();
    Player* askUsername();
    void tellInfo();
public slots:
    void resetMap();
};

#endif // WORLD_H
