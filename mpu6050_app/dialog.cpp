#include "dialog.h"
#include "ui_dialog.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QtWidgets>
#include <QMessageBox>
#include<QFuture>
#include<QtConcurrent>
#include<QFutureSynchronizer>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    arduino_port_name = "";
    arduino_is_available = false;
    arduino = new QSerialPort(this);

    foreach(const QSerialPortInfo &serialPortInfo,QSerialPortInfo::availablePorts())
    {
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier())
        {
            if(serialPortInfo.vendorIdentifier() == arduino_nano_vendor_id)
            {
                if(serialPortInfo.productIdentifier() == arduino_nano_product_id)
                {
                    arduino_port_name = serialPortInfo.portName();
                    arduino_is_available = true;
                }
            }
        }
    }
    if(arduino_is_available)
    {
        //Open and configure the serialport
        arduino->setPortName(arduino_port_name);
        arduino->open(QSerialPort::ReadOnly);
        arduino->setBaudRate(QSerialPort::Baud115200);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);

        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setPen(QPen(Qt::red));
        ui->customPlot->graph(0)->setAntialiasedFill(false);
        ui->customPlot->graph(0)->setName("AccX");

        ui->customPlot->addGraph();
        ui->customPlot->graph(1)->setPen(QPen(Qt::blue));
        ui->customPlot->graph(1)->setAntialiasedFill(false);
        ui->customPlot->graph(1)->setName("AccY");


        ui->customPlot->addGraph();
        ui->customPlot->graph(2)->setPen(QPen(Qt::green));
        ui->customPlot->graph(2)->setAntialiasedFill(false);
        ui->customPlot->graph(2)->setName("AccZ");


        ui->customPlot->addGraph();
        ui->customPlot->graph(3)->setPen(QPen(Qt::yellow));
        ui->customPlot->graph(3)->setAntialiasedFill(false);
        ui->customPlot->graph(3)->setName("GyroX");


        ui->customPlot->addGraph();
        ui->customPlot->graph(4)->setPen(QPen(Qt::gray));
        ui->customPlot->graph(4)->setAntialiasedFill(false);
        ui->customPlot->graph(4)->setName("GyroY");


        ui->customPlot->addGraph();
        ui->customPlot->graph(5)->setPen(QPen(Qt::black));
        ui->customPlot->graph(5)->setAntialiasedFill(false);
        ui->customPlot->graph(5)->setName("GyroZ");



        QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
        timeTicker->setTimeFormat("%s");
        ui->customPlot->xAxis->setTicker(timeTicker);
        ui->customPlot->axisRect()->setupFullAxesBox();

        ui->customPlot->xAxis->setTickLabelFont(QFont(QFont().family(),8));
        ui->customPlot->yAxis->setTickLabelFont(QFont(QFont().family(),8));
        ui->customPlot->xAxis->setLabel("Time(s)");
        ui->customPlot->yAxis->setLabel("Accelerometer and Gyroscope");
        ui->customPlot->yAxis->setRange(-5000,5000);

        ui->customPlot->xAxis2->setVisible(true);
        ui->customPlot->yAxis2->setVisible(true);
        ui->customPlot->xAxis2->setTicks(false);
        ui->customPlot->yAxis2->setTicks(false);
        ui->customPlot->xAxis2->setTickLabels(false);
        ui->customPlot->yAxis2->setTickLabels(false);

        connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)),
                ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
        connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)),
                ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));

        QObject::connect(arduino, SIGNAL(readyRead()),
                         this, SLOT(readSerial()));

//       QObject::connect(arduino,SIGNAL(timeout()), this, SLOT(readSerial()));
//        timer_plot.start(0);
    }
    else
    {
        qDebug()<<"couldn't find arduino";
        QMessageBox::warning(this,"port error","Couldn't find the arduino");
    }
}

void Dialog::readSerial()
{
//    QStringList buffersplit = serialBuffer.split(",");

//    if(buffersplit.length() <= 1)
//    {
//        serialData = arduino->readAll();

//       QString serialdata_string = QString(serialData);

//       QStringList serialdata_split = serialdata_string.split(",");

//        qDebug()<<serialData;
//        serialBuffer += QString::fromStdString(serialData.toStdString());



        serialdata.enqueue(arduino->readAll());

        serialdatastring=serialdata.head();
        serialRecieveCount++;

        if(serialRecieveCount%1000 == 1) { qDebug()<< serialRecieveCount; }

        serialdata_split=serialdatastring.split(",");

        plotGraph();

      // QFuture future=QtConcurrent::run(plotGraph());

        ui->customPlot->replot();
        serialdata.dequeue();
        serialdata_split.clear();

//    }
//     else
//     {
//         serialBuffer = "";
//     }

}

void Dialog::plotGraph()
{
    static QTime time(QTime::currentTime());

    double key = time.elapsed()/10;
    static double lastPointKey = 0;

    if(key - lastPointKey > 0.002)
    {
        ui->accx->setText(QString("<span style=\" font-size:18pt; font-weight:600; color:#0000ff;\">%1</span>").arg(serialdata_split[0]));
        ui->accy->setText(QString("<span style=\" font-size:18pt; font-weight:600; color:#0000ff;\">%1</span>").arg(serialdata_split[1]));
        ui->accz->setText(QString("<span style=\" font-size:18pt; font-weight:600; color:#0000ff;\">%1</span>").arg(serialdata_split[2]));
        ui->gyrox->setText(QString("<span style=\" font-size:18pt; font-weight:600; color:#0000ff;\">%1</span>").arg(serialdata_split[3]));
        ui->gyroy->setText(QString("<span style=\" font-size:18pt; font-weight:600; color:#0000ff;\">%1</span>").arg(serialdata_split[4]));
        ui->gyroz->setText(QString("<span style=\" font-size:18pt; font-weight:600; color:#0000ff;\">%1</span>").arg(serialdata_split[5]));

        ui->customPlot->graph(0)->addData(key,serialdata_split[0].toDouble());
        ui->customPlot->graph(1)->addData(key,serialdata_split[1].toDouble());
        ui->customPlot->graph(2)->addData(key,serialdata_split[2].toDouble());
        ui->customPlot->graph(3)->addData(key,serialdata_split[3].toDouble());
        ui->customPlot->graph(4)->addData(key,serialdata_split[4].toDouble());
        ui->customPlot->graph(5)->addData(key,serialdata_split[5].toDouble());

        ui->customPlot->graph(0)->rescaleValueAxis(true);
        ui->customPlot->graph(1)->rescaleValueAxis(true);
        ui->customPlot->graph(2)->rescaleValueAxis(true);
        ui->customPlot->graph(3)->rescaleValueAxis(true);
        ui->customPlot->graph(4)->rescaleValueAxis(true);
        ui->customPlot->graph(5)->rescaleValueAxis(true);
        lastPointKey = key;
     }
    ui->customPlot->xAxis->setRange(key,100, Qt::AlignRight);
}


Dialog::~Dialog()
{
    if(arduino->isOpen())
    {
        arduino->close();
    }

    delete ui;
}
