#ifndef SERIALDATAREAD_H
#define SERIALDATAREAD_H

#include <QObject>
#include <QSerialPort>
#include <QQueue>
#include <QSerialPortInfo>
#include <QDebug>

class SerialDataRead : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString data1 READ receiveSerialData WRITE setSerialData NOTIFY data1Changed)
    Q_PROPERTY(QString data2 READ receiveSerialData WRITE setSerialData NOTIFY data2Changed)
    Q_PROPERTY(QString data3 READ receiveSerialData WRITE setSerialData NOTIFY data3Changed)
    Q_PROPERTY(QString data4 READ receiveSerialData WRITE setSerialData NOTIFY data4Changed)
    Q_PROPERTY(QString data5 READ receiveSerialData WRITE setSerialData NOTIFY data5Changed)
    Q_PROPERTY(QString data6 READ receiveSerialData WRITE setSerialData NOTIFY data6Changed)


public:
    explicit SerialDataRead(QObject *parent = nullptr);

    void setSerialData(QString serialdatastring);

signals:
    void data1Changed();
    void data2Changed();
    void data3Changed();
    void data4Changed();
    void data5Changed();
    void data6Changed();

private slots:
    QString receiveSerialData();

private:

    QQueue<QString> serialdata;

    QStringList serialdata_split;
    QString serialdatastring;

    QString m_data1;
    QString m_data2;
    QString m_data3;
    QString m_data4;
    QString m_data5;
    QString m_data6;


};

#endif // SERIALDATAREAD_H
