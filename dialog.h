#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "storage.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr, QString message="Hello");
    ~Dialog();



private slots:
    void on_buttonBox_accepted();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    bool m_Button1_status;
    bool m_Button2_status;
    Ui::Dialog *ui;
};

#endif // DIALOG_H
