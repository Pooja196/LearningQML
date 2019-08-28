#ifndef DIALOG_H
#define DIALOG_H
#include<QQueue>
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    int data;
    QQueue<int> queue;

};

#endif // DIALOG_H
