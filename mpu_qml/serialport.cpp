#include "serialport.h"

SerialPort::SerialPort(QObject *parent) : QObject(parent)
{
    arduino_port_name = "";
    arduino_is_available = false;
    arduino = new QSerialPort(this);

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier())
        {
            if(serialPortInfo.vendorIdentifier() == arduino_nano_vendor_id)
            {
                if(serialPortInfo.productIdentifier() == arduino_nano_product_id)
                {
                    arduino_port_name = serialPortInfo.portName();
                    qDebug() << arduino_port_name;
                    arduino_is_available = true;
                }
            }
        }
    }

    if(arduino_is_available)
    {
        arduino->setPortName(arduino_port_name);
        arduino->open(QSerialPort::ReadOnly);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        QObject::connect(arduino, SIGNAL(readyRead()), this , SLOT(readserialdata()));
    }
}

void SerialPort::readserialdata()
{
        data = arduino->readLine();

        m_dataString = data.split(",");

        if(m_dataString.length()>=6)
        {
            m_data1 = m_dataString[0];
            m_data2 = m_dataString[1];
            m_data3 = m_dataString[2];
            m_data4 = m_dataString[3];
            m_data5 = m_dataString[4];
            m_data6 = m_dataString[5];

            emit data1Changed();
            emit data2Changed();
            emit data3Changed();
            emit data4Changed();
            emit data5Changed();
            emit data6Changed();
        }
        m_dataString.clear();
}

QString SerialPort::getdata1()
{
    return m_data1;
}


QString SerialPort::getdata2()
{
    return m_data2;
}


QString SerialPort::getdata3()
{
    return m_data3;
}


QString SerialPort::getdata4()
{
    return m_data4;
}


QString SerialPort::getdata5()
{
    return m_data5;
}

QString SerialPort::getdata6()
{
    return m_data6;
}


