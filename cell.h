#ifndef CELL_H
#define CELL_H

#include <QImage>
#include <QtWidgets>
#include <mybutton.h>
#include <vector>
using namespace std;

class Cell : public QObject
{
    Q_OBJECT
protected:
    int x;
    int y;
    QWidget *window;
    QImage *image;
    MyButton *label;
//    QLabel * label;
    void change_picture(QString filename);
    bool is_clicked;
    bool is_suspecious;
    bool is_flag;
    bool is_block;
    bool is_mine;
    Cell *left;
    Cell *right;
    Cell *up;
    Cell *down;
public:
    Cell();
    Cell(QWidget *window, int x, int y, QString filename);
    virtual ~Cell();
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
public slots:
    void left_click();
    void right_click();
//    void click(QMouseEvent *event);
};

#endif // CELL_H
