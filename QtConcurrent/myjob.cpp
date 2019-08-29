#include "myjob.h"

MyJob::MyJob()
{
    mstop = false;
}

void MyJob::start(QString name)
{
    mstop = false;

    for(int i = 0; i < 999999; i++)
    {
        if(mstop) return;
        qDebug() << "From thread: " << i;
        emit on_number(name,i);
        QThread::currentThread() -> msleep(100);
    }
}

void MyJob::stop()
{
    mstop = true;
}
