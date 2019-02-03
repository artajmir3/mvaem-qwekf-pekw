#ifndef WORLD_H
#define WORLD_H

#include <QtWidgets>
#include "mymap.h"

class World : public QObject
{
    Q_OBJECT
private:
    MyMap *map;
    QWidget *window;
public:
    World();
public slots:
    void resetMap();
};

#endif // WORLD_H
