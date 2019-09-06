#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

class SerialPort : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString data1 READ getdata1 WRITE setdata1 NOTIFY data1Changed)

public:
    explicit SerialPort(QObject *parent = nullptr);

    QString getdata1() const;
    void setdata1(QString serialdata);

signals:
    void data1Changed();

public slots:
    void readserialdata();

private:
    QSerialPort *arduino;
    QString m_data1;
    QSerialPortInfo portInfo;
    void openDefault();

};

#endif // SERIALPORT_H
