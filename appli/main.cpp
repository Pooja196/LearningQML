#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "serialdataread.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<SerialDataRead>("serialreadfrom",1,0,"SerialDataRead");

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
            qDebug() << "Name : " << info.portName();
            qDebug() << "Description : " << info.description();
            qDebug() << "Manufacturer: " << info.manufacturer();

            // Example use QSerialPort
            QSerialPort arduino;

            arduino.setPortName("COM3");
                    arduino.open(QIODevice::ReadWrite);
                    arduino.setBaudRate(QSerialPort::Baud9600);
                    arduino.setDataBits(QSerialPort::Data8);
                    arduino.setParity(QSerialPort::NoParity);
                    arduino.setStopBits(QSerialPort::OneStop);
                    arduino.setFlowControl(QSerialPort::NoFlowControl);




            qDebug() << arduino.readLine();
            arduino.setPort(info);

            if (arduino.open(QIODevice::ReadWrite))
                arduino.close();
     }

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
