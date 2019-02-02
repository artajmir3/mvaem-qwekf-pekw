#include <QApplication>
#include <QLabel>
#include <QtWidgets>
#include <QTextEdit>

#include "cell.h"
#include "nonblockcell.h"
#include "emptycell.h"
#include "blockcell.h"

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    QWidget *window = new QWidget();
    window->resize(400, 400);

   QTextEdit *text = new QTextEdit(window);
//   QImage *image = new QImage("C:\\Users\\ASUS\\Desktop\\Untitled11.png");
//   QLabel *label = new QLabel(window);
//   label->setPixmap(QPixmap::fromImage(*image));
//   label->setGeometry(0, 0, 100, 100);
   BlockCell *my_cell = new BlockCell(window, 0, 0);
   EmptyCell *my_cell1 = new EmptyCell(window, 1, 0);

    window->show();
    return app.exec();
}
