#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    QDateTime currentDateTime = QDateTime::currentDateTime();
    ui->dateTimeEdit->setDateTime(currentDateTime);
    QStringList boys ={"Jakob Gerjolj","Anže Štravs","Jaka Dejak", "Nejc Česen"};
    ui->comboBox->addItems(boys);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Buttons_OK_clicked()
{

    ui->buttons_check_frame->setStyleSheet("background-color: rgb(0,200,0)");
}


void MainWindow::on_Buttons_NOK_clicked()
{

    Dialog* myDialog = new Dialog(this,"What is wrong with buttons: ");
    myDialog->show();
    ui->buttons_check_frame->setStyleSheet("background-color: rgb(200,0,0)");

}


void MainWindow::on_NFC_OK_clicked()
{

    ui->nfc_check_frame->setStyleSheet("background-color: rgb(0,200,0)");

}


void MainWindow::on_NFC_NOK_clicked()
{

    ui->nfc_check_frame->setStyleSheet("background-color: rgb(200,0,0)");

}


void MainWindow::on_HAL_OK_clicked()
{

    ui->hal_check_frame->setStyleSheet("background-color: rgb(0,200,0)");

}


void MainWindow::on_HAL_NOK_clicked()
{
    ui->hal_check_frame->setStyleSheet("background-color: rgb(200,0,0)");

}


void MainWindow::on_ZERO_OK_clicked()
{
    ui->zero_check_frame->setStyleSheet("background-color: rgb(0,200,0)");
}


void MainWindow::on_ZERO_NOK_clicked()
{
    ui->zero_check_frame->setStyleSheet("background-color: rgb(200,0,0)");
}


void MainWindow::on_LED_OK_clicked()
{
    ui->led_check_frame->setStyleSheet("background-color: rgb(0,200,0)");
}


void MainWindow::on_LED_NOK_clicked()
{
    Dialog* myDialog = new Dialog(this,"What is wrong with LEDs: ");
    myDialog->show();
    ui->led_check_frame->setStyleSheet("background-color: rgb(200,0,0)");

}




void MainWindow::on_dateTimeEdit_timeChanged(const QTime &time)
{

    QDateTime currentDateTime = QDateTime::currentDateTime();
    ui->dateTimeEdit->setDateTime(currentDateTime);
}


void MainWindow::on_pushButton_3_clicked()
{

    QDateTime currentDateTime = QDateTime::currentDateTime();
    ui->dateTimeEdit->setDateTime(currentDateTime);

}

