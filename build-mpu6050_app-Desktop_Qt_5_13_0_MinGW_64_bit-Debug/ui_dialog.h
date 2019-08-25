/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *accx;
    QLabel *accy;
    QLabel *accz;
    QLabel *gyrox;
    QLabel *gyroy;
    QLabel *gyroz;
    QCustomPlot *customPlot;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(740, 289);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 84, 261));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        layoutWidget1 = new QWidget(Dialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(100, 10, 121, 261));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        accx = new QLabel(layoutWidget1);
        accx->setObjectName(QString::fromUtf8("accx"));

        verticalLayout_2->addWidget(accx);

        accy = new QLabel(layoutWidget1);
        accy->setObjectName(QString::fromUtf8("accy"));

        verticalLayout_2->addWidget(accy);

        accz = new QLabel(layoutWidget1);
        accz->setObjectName(QString::fromUtf8("accz"));

        verticalLayout_2->addWidget(accz);

        gyrox = new QLabel(layoutWidget1);
        gyrox->setObjectName(QString::fromUtf8("gyrox"));

        verticalLayout_2->addWidget(gyrox);

        gyroy = new QLabel(layoutWidget1);
        gyroy->setObjectName(QString::fromUtf8("gyroy"));

        verticalLayout_2->addWidget(gyroy);

        gyroz = new QLabel(layoutWidget1);
        gyroz->setObjectName(QString::fromUtf8("gyroz"));

        verticalLayout_2->addWidget(gyroz);

        customPlot = new QCustomPlot(Dialog);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setGeometry(QRect(260, 10, 451, 261));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt; font-weight:600; color:#00007f;\">AccX:</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt; font-weight:600; color:#00007f;\">AccY:</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt; font-weight:600; color:#00007f;\">AccZ:</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt; font-weight:600; color:#00007f;\">GyroX:</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt; font-weight:600; color:#00007f;\">GyroY:</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt; font-weight:600; color:#00007f;\">GyroZ:</span></p></body></html>", nullptr));
        accx->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt; font-weight:600; color:#0000ff;\">0</span></p></body></html>", nullptr));
        accy->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt; font-weight:600; color:#0000ff;\">0</span></p></body></html>", nullptr));
        accz->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt; font-weight:600; color:#0000ff;\">0</span></p></body></html>", nullptr));
        gyrox->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt; font-weight:600; color:#0000ff;\">0</span></p></body></html>", nullptr));
        gyroy->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt; font-weight:600; color:#0000ff;\">0</span></p></body></html>", nullptr));
        gyroz->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt; font-weight:600; color:#0000ff;\">0</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
