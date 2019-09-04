#include "serialdataread.h"

SerialDataRead::SerialDataRead(QObject *parent) : QObject(parent)
{

}

void SerialDataRead::setSerialData(QString serialdatastring)
{

    serialdata_split = serialdatastring.split(",");
    m_data1 = serialdata_split[0];
    m_data2 = serialdata_split[1];
    m_data3 = serialdata_split[2];
    m_data4 = serialdata_split[3];
    m_data5 = serialdata_split[4];
    m_data6 = serialdata_split[5];

    serialdata.dequeue();

    serialdata_split.clear();

    emit data1Changed();
    emit data2Changed();
    emit data3Changed();
    emit data4Changed();
    emit data5Changed();
    emit data6Changed();

}

QString SerialDataRead::receiveSerialData()
{
      serialdatastring = serialdata.head();

      return serialdatastring;
}
