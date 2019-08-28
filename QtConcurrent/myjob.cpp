#include "myjob.h"

myjob::myjob(QObject *parent) : QObject(parent)
{
    mstop=false;
}

void myjob::start(QString name)
{
    mstop=false;

    for(int i = 0; i<999999; i++)
    {
        if(mstop) return;
        qDebug() << "From thread: " <<i;
        emit on_number(name,i);
        QThread::currentThread() -> msleep(100);
    }
}

void myjob::stop()
{
    mstop=true;
}
