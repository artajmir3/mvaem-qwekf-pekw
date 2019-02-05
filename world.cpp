#include "world.h"
#include <iostream>
#include <string>
using namespace std;

World::World() :
    players()
{
    window = new QWidget();

    window->show();

//    this->players = new vector<Player*>();

    this->active_player = this->askUsername();

    this->askSize();

    if(this->width < 10){
        Cell::width = 500 / this->width;
        Cell::height = 500/this->width;
    }

    window->hide();
    window->resize(this->width*Cell::width, this->height*Cell::height + 150);
    this->map = new MyMap(active_player, window, this->width, this->height/*, nullptr*/);
    connect(this->map, SIGNAL(end()), this, SLOT(resetMap()));
    window->show();
}

void World::askSize(){

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

}

Player* World::askUsername(){

    QDialog *dialog = new QDialog(window);
    QFormLayout *form = new QFormLayout(dialog);
    form->addRow(new QLabel("khoshamadid. dada usernamet chie?"));

    QList<QLineEdit *> fields;
    QLineEdit *lineEdit1 = new QLineEdit(dialog);
    QString label1 = QString("username");
    form->addRow(label1, lineEdit1);
    fields << lineEdit1;


    QDialogButtonBox buttonBox(QDialogButtonBox::Ok, Qt::Horizontal, dialog);
    form->addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));

    if (dialog->exec() == QDialog::Accepted) {
        Player* player = new Player(lineEdit1->text().toStdString(), "");
        this->players.push_back(player);
        return player;
    }

}


void World::tellInfo(){

    QDialog *dialog = new QDialog(window);
    QFormLayout *form = new QFormLayout(dialog);
    form->addRow(new QLabel(QString::fromStdString(this->active_player->get_username())));

    QList<QLineEdit *> fields;
    QString label1 = QString("num of win");
    QString label2 = QString::fromStdString(to_string(this->active_player->getWin()));
    form->addRow(new QLabel(label1));
    form->addRow(new QLabel(label2));
//    fields << lineEdit1;


    QDialogButtonBox buttonBox(QDialogButtonBox::Ok, Qt::Horizontal, dialog);
    form->addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));

    if (dialog->exec() == QDialog::Accepted) {
    }

}


void World::resetMap(){
    this->tellInfo();
    this->map->clear();
    delete this->map;
    window->hide();
    delete window;
    window = new QWidget();
    window->resize(this->width*Cell::width, this->height*Cell::height + 150);
    this->map = new MyMap(active_player, window, this->width, this->height/*, nullptr*/);
    connect(this->map, SIGNAL(end()), this, SLOT(resetMap()));
    window->show();
}
