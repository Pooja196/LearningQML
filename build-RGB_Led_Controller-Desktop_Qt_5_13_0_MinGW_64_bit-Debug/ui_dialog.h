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
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *Red_Label;
    QLabel *Green_Label;
    QLabel *Blue_Label;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QSlider *Red_Slider;
    QSlider *Green_Slider;
    QSlider *Blue_Slider;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *red_Led_Label;
    QLabel *green_Led_Label;
    QLabel *blue_Led_Label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(522, 179);
        verticalLayoutWidget = new QWidget(Dialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 131, 161));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Red_Label = new QLabel(verticalLayoutWidget);
        Red_Label->setObjectName(QString::fromUtf8("Red_Label"));

        verticalLayout->addWidget(Red_Label);

        Green_Label = new QLabel(verticalLayoutWidget);
        Green_Label->setObjectName(QString::fromUtf8("Green_Label"));

        verticalLayout->addWidget(Green_Label);

        Blue_Label = new QLabel(verticalLayoutWidget);
        Blue_Label->setObjectName(QString::fromUtf8("Blue_Label"));

        verticalLayout->addWidget(Blue_Label);

        verticalLayoutWidget_2 = new QWidget(Dialog);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(160, 10, 281, 161));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Red_Slider = new QSlider(verticalLayoutWidget_2);
        Red_Slider->setObjectName(QString::fromUtf8("Red_Slider"));
        Red_Slider->setMaximum(255);
        Red_Slider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(Red_Slider);

        Green_Slider = new QSlider(verticalLayoutWidget_2);
        Green_Slider->setObjectName(QString::fromUtf8("Green_Slider"));
        Green_Slider->setMaximum(255);
        Green_Slider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(Green_Slider);

        Blue_Slider = new QSlider(verticalLayoutWidget_2);
        Blue_Slider->setObjectName(QString::fromUtf8("Blue_Slider"));
        Blue_Slider->setMaximum(255);
        Blue_Slider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(Blue_Slider);

        verticalLayoutWidget_3 = new QWidget(Dialog);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(450, 10, 61, 161));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        red_Led_Label = new QLabel(verticalLayoutWidget_3);
        red_Led_Label->setObjectName(QString::fromUtf8("red_Led_Label"));

        verticalLayout_3->addWidget(red_Led_Label);

        green_Led_Label = new QLabel(verticalLayoutWidget_3);
        green_Led_Label->setObjectName(QString::fromUtf8("green_Led_Label"));

        verticalLayout_3->addWidget(green_Led_Label);

        blue_Led_Label = new QLabel(verticalLayoutWidget_3);
        blue_Led_Label->setObjectName(QString::fromUtf8("blue_Led_Label"));

        verticalLayout_3->addWidget(blue_Led_Label);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        Red_Label->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt; font-weight:600; color:#ff0000;\">Red Led</span></p></body></html>", nullptr));
        Green_Label->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt; font-weight:600; color:#00aa00;\">Green Led</span></p></body></html>", nullptr));
        Blue_Label->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p align=\"right\"><span style=\" font-size:18pt; font-weight:600; color:#0000ff;\">Blue Led</span></p></body></html>", nullptr));
        red_Led_Label->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600;\">0</span></p></body></html>", nullptr));
        green_Led_Label->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600;\">0</span></p></body></html>", nullptr));
        blue_Led_Label->setText(QCoreApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600;\">0</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
