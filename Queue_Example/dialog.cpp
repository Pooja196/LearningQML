#include "dialog.h"
#include "ui_dialog.h"
#include<QQueue>
#include<QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QList<int> list = {1,2,3,4,5,6,7,8,9,10 };

    for(int i = 0 ; i < 10 ; i++)
    {
        queue.enqueue(list[i]);
        data = queue.dequeue();
        qDebug()<<data;
        ui->text_label->setNum(data);
        list.removeAt(i);
        list.append(0);
    }
//    data=queue.dequeue();
//    qDebug()<<data;
   // list.clear();
    qDebug()<<list[2];

    for(int i = 0 ; i < list.size() ; i++)
    {
        qDebug()<<list[i];
    }
}

Dialog::~Dialog()
{
    delete ui;
}
