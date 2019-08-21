#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QSerialPort>

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
    void on_Red_Slider_valueChanged(int value);

    void on_Green_Slider_valueChanged(int value);

    void on_Blue_Slider_valueChanged(int value);

    void updateRGB(QString command);

private:
    Ui::Dialog *ui;
    QSerialPort *arduino;
    static const quint16 arduino_nano_vendor_id=6790;
    static const quint16 arduino_nano_product_id=29987;

    QString arduino_port_name;
    bool arduino_is_available;

};

#endif // DIALOG_H
