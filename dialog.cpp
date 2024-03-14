#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent, QString message)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->textEdit->setVisible(false);
    ui->textEdit_2->setVisible(false);
    this->setWindowTitle("What is wrong with the buttons");

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
   // qDebug() << ui->textEdit->toPlainText(); // how to get text

}


void Dialog::on_pushButton_clicked()
{
    ui->pushButton->setStyleSheet("background-color: rgb(0,200,0)");
    ui->pushButton_2->setStyleSheet("");
    ui->textEdit->setVisible(false);
    ui->butt1_NOK_label->setVisible(false);
    ui->butt1_OK_label->setVisible(true);
}


void Dialog::on_pushButton_2_clicked()
{
    ui->pushButton_2->setStyleSheet("background-color: rgb(200,0,0)");
    ui->pushButton->setStyleSheet("");
    ui->textEdit->setVisible(true);
    ui->butt1_OK_label->setVisible(false);
    ui->butt1_NOK_label->setVisible(true);
    ui->textEdit->setPlaceholderText("Describe the problem...");

}


void Dialog::on_pushButton_4_clicked()
{
    ui->pushButton_4->setStyleSheet("background-color: rgb(0,200,0)");
    ui->pushButton_3->setStyleSheet("");
    ui->textEdit_2->setVisible(false);
    ui->butt2_OK_label->setVisible(true);
    ui->butt2_NOK_label->setVisible(false);

}


void Dialog::on_pushButton_3_clicked()
{
    ui->pushButton_3->setStyleSheet("background-color: rgb(200,0,0)");
    ui->pushButton_4->setStyleSheet("");
    ui->textEdit_2->setVisible(true);
    ui->butt2_NOK_label->setVisible(true);
    ui->butt2_OK_label->setVisible(false);
    ui->textEdit_2->setPlaceholderText("Describe the problem...");



}

