#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QtWidgets>
#include <QMessageBox>
#include <QtConcurrent>
#include <QThread>
#include <QThreadPool>


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

    QQueue<QString> serialdata;

    QStringList serialdata_split;
    QString serialdatastring;

    int serialRecieveCount = 0;

    void receiveSerialData();

    void plotGraph();
};

#endif // DIALOG_H
