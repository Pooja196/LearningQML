#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtSerialPort>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void readSerial();

private:
    Ui::Dialog *ui;

    QSerialPort *arduino;
    static const quint16 arduino_nano_vendor_id=6790;
    static const quint16 arduino_nano_product_id=29987;

    QString arduino_port_name;
    bool arduino_is_available;

//    QByteArray serialData;
//    QString serialBuffer;

    QQueue<QString> serialdata;

    QStringList serialdata_split;
    QString serialdatastring;

    QTimer timer_plot;
};

#endif // DIALOG_H
