#include "serialport.h"

SerialPort::SerialPort(QObject *parent) : QObject(parent)
{
    arduino = new QSerialPort(this);
    connect(arduino, &QSerialPort::readyRead, this , &SerialPort::readserialdata);
    openDefault();
}

QString SerialPort::getdata1() const
{
    return m_data1;
}

void SerialPort::setdata1(QString serialdata)
{
    if(m_data1 == serialdata)
        return;
    m_data1 = serialdata;
    emit data1Changed();
}

void SerialPort::readserialdata()
{
    if(arduino->bytesAvailable())
    {
        QString data = arduino->readAll();
        setdata1(data);
    }
}

void SerialPort::openDefault()
{
    for(auto info: QSerialPortInfo::availablePorts())
    {
        qDebug() << info.portName() << info.description() << info.manufacturer();
        if(!info.isBusy() && (info.description().contains("Arduino") || info.manufacturer().contains("Arduino")))
        {
            portInfo = info;
            break;
        }
    }
    if(portInfo.isNull())
    {
        return;
    }

    arduino->setPortName(portInfo.portName());
    arduino->setBaudRate(QSerialPort::Baud9600);
    arduino->setDataBits(QSerialPort::Data8);
    arduino->setParity(QSerialPort::NoParity);
    arduino->setStopBits(QSerialPort::OneStop);
    arduino->setFlowControl(QSerialPort::NoFlowControl);

    if(arduino->open(QSerialPort::ReadOnly))
        qDebug() << "Connected to " << portInfo.manufacturer() << " on " << portInfo.portName();
    else {
        qCritical() << " Serial Port Error: " << arduino->errorString();
    }
}
