#include "world.h"
#include <iostream>
using namespace std;

World::World()
{
    window = new QWidget();
    window->resize(500, 500);
    this->map = new MyMap(nullptr, window, 3, 3/*, nullptr*/);
    connect(this->map, SIGNAL(end()), this, SLOT(resetMap()));
    window->show();
}

void World::resetMap(){
    this->map->clear();
    delete this->map;
    window->hide();
    delete window;
    window = new QWidget();
    window->resize(500, 500);
    this->map = new MyMap(nullptr, window, 10, 10/*, nullptr*/);
    connect(this->map, SIGNAL(end()), this, SLOT(resetMap()));
    window->show();
}
