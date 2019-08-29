#include "myjob.h"

MyJob::MyJob(QObject *parent) : QObject(parent)
{

}

void MyJob::start(QString name)
{
    mstop = false;

    for(int i = 0; i < 999999; i++)
    {
        if(mstop) return;
        qDebug() << " from thread : " << i;
        emit on_number(name,i);
        QThread::currentThread() -> msleep(10);
    }
}

void MyJob::stop()
{
    mstop = true;
}
