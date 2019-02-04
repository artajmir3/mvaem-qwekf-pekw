#include "world.h"
#include <iostream>
#include <string>
using namespace std;

World::World()
{
    window = new QWidget();

    window->show();

    QDialog *dialog = new QDialog(window);
    QFormLayout *form = new QFormLayout(dialog);
    form->addRow(new QLabel("chand dar chand?"));

    QList<QLineEdit *> fields;
    QLineEdit *lineEdit1 = new QLineEdit(dialog);
    QString label1 = QString("width");
    form->addRow(label1, lineEdit1);
    fields << lineEdit1;
    QLineEdit *lineEdit2 = new QLineEdit(dialog);
    QString label2 = QString("height");
    form->addRow(label2, lineEdit2);
    fields << lineEdit2;


    QDialogButtonBox buttonBox(QDialogButtonBox::Ok, Qt::Horizontal, dialog);
    form->addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));

    if (dialog->exec() == QDialog::Accepted) {
        this->width = lineEdit1->text().toInt();
        this->height = lineEdit2->text().toInt();
    }

    window->hide();
    window->resize(this->width*Cell::width, this->height*Cell::height + 150);
    this->map = new MyMap(nullptr, window, this->width, this->height/*, nullptr*/);
    connect(this->map, SIGNAL(end()), this, SLOT(resetMap()));
    window->show();
}

void World::resetMap(){
    this->map->clear();
    delete this->map;
    window->hide();
    delete window;
    window = new QWidget();
    window->resize(this->width*Cell::width, this->height*Cell::height + 150);
    this->map = new MyMap(nullptr, window, this->width, this->height/*, nullptr*/);
    connect(this->map, SIGNAL(end()), this, SLOT(resetMap()));
    window->show();
}
