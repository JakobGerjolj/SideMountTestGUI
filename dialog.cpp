#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent, QString message)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->label->setText(message);

}

Dialog::~Dialog()
{
    delete ui;
}
