#ifndef CELL_H
#define CELL_H

#include <QImage>
#include <QtWidgets>
#include <mybutton.h>
#include <vector>
using namespace std;

class Cell : public MyButton
{
    Q_OBJECT
protected:
    int x;
    int y;
//    QWidget *window;
//    QImage *image;
//    MyButton *label;
//    QLabel * label;
    void change_picture(QIcon icon);
    bool is_clicked;
    bool is_suspecious;
    bool is_flag;
    bool is_mine;
    bool is_block;
    Cell *left;
    Cell *right;
    Cell *up;
    Cell *down;
public:
//    Cell();
    Cell(QWidget *parent, int x, int y, QIcon icon);
//    virtual ~Cell();
    int getX();
    int getY();
    static int width;
    static int height;
    Cell* getLeft();
    Cell* getRight();
    Cell* getUp();
    Cell* getDown();
    Cell* getUpLeft();
    Cell* getUpRight();
    Cell* getDownLeft();
    Cell* getDownRight();
    void setNeighbours(Cell* up, Cell* down, Cell* right, Cell* left);
    vector<Cell*> getNotNullNeighbours();
    int get_number();
    bool getIsMine();
    bool getIsBlock();
    bool getIsClicked();
    void clear();
    static QIcon getBlock();
    static QIcon getEmpty();
    static QIcon getFlag();
    static QIcon getSus();
    static QIcon* getNums();
    static QIcon getMine1();
    static QIcon getMine();
    static void initiate();
    void reveal();
public slots:
    void left_click();
    void right_click();
//    void click(QMouseEvent *event);

signals:
    void check();
    void addFlag();
    void delFlag();
};

#endif // CELL_H
