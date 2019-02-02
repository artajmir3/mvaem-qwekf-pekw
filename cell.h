#ifndef CELL_H
#define CELL_H

#include <QImage>
#include <QtWidgets>

class Cell : public QObject
{
    Q_OBJECT
protected:
    int x;
    int y;
    QWidget *window;
    QImage *image;
    QPushButton *label;
//    QLabel * label;
    void change_picture(QString filename);
    bool is_clicked;
    bool is_suspecious;
    bool is_flag;
    bool is_block;
    bool is_mine;
public:
    Cell();
    Cell(QWidget *window, int x, int y, QString filename);
    virtual ~Cell();
    int getX();
    int getY();
    static int width;
    static int height;
public slots:
    void left_click();
    void right_click();
    void click(QMouseEvent *event);
};

#endif // CELL_H
