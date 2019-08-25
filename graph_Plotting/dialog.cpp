#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QVector<double> x(100),y(100);

    for(int i=0;i<100;i++)
    {
        x[i]=i+1;
       y[i]=x[i]*x[i];
    }

    ui->customPlot->xAxis->setRange(0,101);
    ui->customPlot->yAxis->setRange(0,10000);
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x,y);
}

Dialog::~Dialog()
{
    delete ui;
}
