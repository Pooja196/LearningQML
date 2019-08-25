#include "dialog.h"
#include "ui_dialog.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include<QtWidgets>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    arduino_port_name="";
    arduino_is_available=false;
    arduino =new QSerialPort(this);

    foreach(const QSerialPortInfo &serialPortInfo,QSerialPortInfo::availablePorts())
    {
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier())
        {
            if(serialPortInfo.vendorIdentifier()==arduino_nano_vendor_id)
            {
                if(serialPortInfo.productIdentifier()==arduino_nano_product_id)
                {
                    arduino_port_name=serialPortInfo.portName();
                    arduino_is_available=true;
                }

            }
        }
    }
    if(arduino_is_available)
    {
        //Open and configure the serialport
        arduino->setPortName(arduino_port_name);
        arduino->open(QSerialPort::ReadOnly);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
    }
    else
    {
        qDebug()<<"couldn't find arduino";
        QMessageBox::warning(this,"port error","Couldn't find the arduino");
    }
}

void Dialog::readSerial()
{
    QStringList buffersplit = serialBuffer.split(",");

    if(buffersplit.length()<=1)
    {
        serialData = arduino->readAll();

       QString serialdata_string = QString(serialData);

       QStringList serialdata_split = serialdata_string.split(",");

        qDebug()<<serialData;
        serialBuffer += QString::fromStdString(serialData.toStdString());

        ui->accx->setText(QString("<span style=\" font-size:18pt; font-weight:600; color:#0000ff;\">%1</span>").arg(serialdata_split[0]));
        ui->accy->setText(QString("<span style=\" font-size:18pt; font-weight:600; color:#0000ff;\">%1</span>").arg(serialdata_split[1]));
        ui->accz->setText(QString("<span style=\" font-size:18pt; font-weight:600; color:#0000ff;\">%1</span>").arg(serialdata_split[2]));
        ui->gyrox->setText(QString("<span style=\" font-size:18pt; font-weight:600; color:#0000ff;\">%1</span>").arg(serialdata_split[3]));
        ui->gyroy->setText(QString("<span style=\" font-size:18pt; font-weight:600; color:#0000ff;\">%1</span>").arg(serialdata_split[4]));
        ui->gyroz->setText(QString("<span style=\" font-size:18pt; font-weight:600; color:#0000ff;\">%1</span>").arg(serialdata_split[5]));
    }

    else
    {
        serialBuffer="";
    }

}

Dialog::~Dialog()
{
    if(arduino->isOpen())
    {
        arduino->close();
    }

    delete ui;
}
