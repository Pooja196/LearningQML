#include "dialog.h"
#include "ui_dialog.h"
#include <QtSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include<QtWidgets>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    arduino_port_name="";
    arduino_is_available=false;
    arduino =new QSerialPort;

//    qDebug()<<"Number of available ports:"<<QSerialPortInfo::availablePorts().length();

//    foreach(const QSerialPortInfo &serialPortInfo,QSerialPortInfo::availablePorts())
//    {
//        qDebug()<<"Has Vendor ID:"<<serialPortInfo.hasVendorIdentifier();
//        if(serialPortInfo.hasVendorIdentifier())
//        {
//            qDebug()<<"Vendor ID:"<<serialPortInfo.vendorIdentifier();
//        }

//        //qDebug()<"Has Product ID:"<<serialPortInfo.hasProductIdentifier();
//        if(serialPortInfo.hasProductIdentifier())
//        {
//            qDebug()<<"Product ID:"<<serialPortInfo.productIdentifier();
//        }
//    }

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
        arduino->open(QSerialPort::WriteOnly);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
    }
    else
    {
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

void Dialog::on_Red_Slider_valueChanged(int value)
{
      ui->red_Led_Label->setText(QString("<span style=\" font-size:18pt; font-weight:600;\">%1</span>").arg(value));
      Dialog::updateRGB(QString("r%1").arg(value));
      qDebug()<<value;
}

void Dialog::on_Green_Slider_valueChanged(int value)
{
     ui->green_Led_Label->setText(QString("<span style=\" font-size:18pt; font-weight:600;\">%1</span>").arg(value));
     Dialog::updateRGB(QString("g%1").arg(value));
     qDebug()<<value;
}

void Dialog::on_Blue_Slider_valueChanged(int value)
{
      ui->blue_Led_Label->setText(QString("<span style=\" font-size:18pt; font-weight:600;\">%1</span>").arg(value));
      Dialog::updateRGB(QString("b%1").arg(value));
      qDebug()<<value;
}

void Dialog::updateRGB(QString command)
{
    if(arduino->isWritable())
    {
        arduino->write(command.toStdString().c_str());
    }
    else
    {
        qDebug()<<"Couldn't write to serial";
    }
}
