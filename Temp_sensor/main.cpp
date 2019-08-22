#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.setFixedSize(400,88);
    w.setWindowTitle("Temperature Sensor");
    w.show();

    return a.exec();
}
