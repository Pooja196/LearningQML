#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

class SerialPort : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString data1 READ getdata1 NOTIFY data1Changed)
    Q_PROPERTY(QString data2 READ getdata2 NOTIFY data2Changed)
    Q_PROPERTY(QString data3 READ getdata3 NOTIFY data3Changed)
    Q_PROPERTY(QString data4 READ getdata4 NOTIFY data4Changed)
    Q_PROPERTY(QString data5 READ getdata5 NOTIFY data5Changed)
    Q_PROPERTY(QString data6 READ getdata6 NOTIFY data6Changed)

public:
    explicit SerialPort(QObject *parent = nullptr);

    QString getdata1();
    QString getdata2();
    QString getdata3();
    QString getdata4();
    QString getdata5();
    QString getdata6();

signals:
    void data1Changed();
    void data2Changed();
    void data3Changed();
    void data4Changed();
    void data5Changed();
    void data6Changed();

public slots:
    void readserialdata();

private:
    QSerialPort *arduino;

    static const quint16 arduino_nano_vendor_id = 6790;
    static const quint16 arduino_nano_product_id = 29987;

    QString arduino_port_name;
    bool arduino_is_available;

    QString m_data1,m_data2,m_data3,m_data4,m_data5,m_data6;
    QStringList m_dataString;

    QString data;

};

#endif // SERIALPORT_H
