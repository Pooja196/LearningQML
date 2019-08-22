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

    ui->TemplcdNumber->display("-------");

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
        QObject::connect(arduino,SIGNAL(readyRead()),this,SLOT(readSerial()));
    }
    else
    {
        qDebug()<<"couldn't find arduino";
        QMessageBox::warning(this,"port error","Couldn't find the arduino");
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

void Dialog::readSerial()
{
    //qDebug()<<"serialport works";
      //qDebug()<<serialBuffer;

      QStringList buffersplit = serialBuffer.split(",");
      if(buffersplit.length()<3)
      {
          serialData=arduino->readAll();
          serialBuffer += QString::fromStdString(serialData.toStdString());
      }
      else
      {
          qDebug()<<buffersplit;
          Dialog::updatelcd(buffersplit[1]);
          serialBuffer="";
      }

}

void Dialog::updatelcd(QString sensor_reading)
{
    ui->TemplcdNumber->display(sensor_reading);
}
