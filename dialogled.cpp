#include "dialogled.h"
#include "ui_dialogled.h"

DialogLED::DialogLED(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogLED)
{
    ui->setupUi(this);
}

DialogLED::~DialogLED()
{
    delete ui;
}

void DialogLED::on_led1_OK_clicked()
{
    ui->led1_OK->setStyleSheet("background-color: rgb(0,200,0)");
    ui->led1_NOK->setStyleSheet("");
    ui->led1_OK_label->setVisible(true);
    ui->led1_NOK_label->setVisible(false);

}


void DialogLED::on_led1_NOK_clicked()
{
    ui->led1_NOK->setStyleSheet("background-color: rgb(200,0,0)");
    ui->led1_OK->setStyleSheet("");
    ui->led1_NOK_label->setVisible(true);
    ui->led1_OK_label->setVisible(false);

}


void DialogLED::on_led2_OK_clicked()
{
    ui->led2_OK->setStyleSheet("background-color: rgb(0,200,0)");
    ui->led2_NOK->setStyleSheet("");
    ui->led2_OK_label->setVisible(true);
    ui->led2_NOK_label->setVisible(false);
}


void DialogLED::on_led2_NOK_clicked()
{
    ui->led2_NOK->setStyleSheet("background-color: rgb(200,0,0)");
    ui->led2_OK->setStyleSheet("");
    ui->led2_OK_label->setVisible(false);
    ui->led2_NOK_label->setVisible(true);
}


void DialogLED::on_led3_OK_clicked()
{
    ui->led3_OK->setStyleSheet("background-color: rgb(0,200,0)");
    ui->led3_NOK->setStyleSheet("");
    ui->led3_OK_label->setVisible(true);
    ui->led3_NOK_label->setVisible(false);

}


void DialogLED::on_led3_NOK_clicked()
{
    ui->led3_NOK->setStyleSheet("background-color: rgb(200,0,0)");
    ui->led3_OK->setStyleSheet("");
    ui->led3_OK_label->setVisible(false);
    ui->led3_NOK_label->setVisible(true);
}


void DialogLED::on_led4_OK_clicked()
{
    ui->led4_OK->setStyleSheet("background-color: rgb(0,200,0)");
    ui->led4_NOK->setStyleSheet("");
    ui->led4_OK_label->setVisible(true);
    ui->led4_NOK_label->setVisible(false);
}


void DialogLED::on_led4_NOK_clicked()
{
    ui->led4_NOK->setStyleSheet("background-color: rgb(200,0,0)");
    ui->led4_OK->setStyleSheet("");
    ui->led4_OK_label->setVisible(false);
    ui->led4_NOK_label->setVisible(true);
}


void DialogLED::on_led5_OK_clicked()
{
    ui->led5_OK->setStyleSheet("background-color: rgb(0,200,0)");
    ui->led5_NOK->setStyleSheet("");
    ui->led5_NOK_label->setVisible(false);
    ui->led5_OK_label->setVisible(true);
}


void DialogLED::on_led5_NOK_clicked()
{
    ui->led5_NOK->setStyleSheet("background-color: rgb(200,0,0)");
    ui->led5_OK->setStyleSheet("");
    ui->led5_NOK_label->setVisible(true);
    ui->led5_OK->setVisible(false);
}

