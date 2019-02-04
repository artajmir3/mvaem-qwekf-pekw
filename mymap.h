#ifndef MYMAP_H
#define MYMAP_H

#include <QtWidgets>
#include <cell.h>
#include <player.h>
#include <vector>
using namespace std;

class MyMap : public QObject
{
    Q_OBJECT
private:
    int width;
    int height;
    vector<vector<Cell*>> cells;
    QWidget *window;
    Player *active_player;
public:
    MyMap(Player *active_player, QWidget *window, int width, int height/*, vector<vector<bool>> layout*/);
    int getWidth();
    int getHeight();
    vector<vector<Cell*>> getCells();
    Cell* getCell(int x, int y);
    void loose();
    void win();
    void clear();
signals:
    void end();
public slots:
    void checkWin();
    void runEnd();
};

#endif // MYMAP_H
