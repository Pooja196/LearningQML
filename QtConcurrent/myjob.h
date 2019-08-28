#ifndef MYJOB_H
#define MYJOB_H

#include <QObject>
#include<QDebug>
#include<QThread>


class myjob : public QObject
{
    Q_OBJECT
public:
    explicit myjob(QObject *parent = nullptr);

    void start(QString name);

signals:

    void on_number(QString name, int number);

public slots:

   void stop();

private:
   bool mstop;
};

#endif // MYJOB_H
