#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked()
{
    Dialog* myDialog = new Dialog(this,"What is wrong with buttons: ");



    ui->frame_7->setStyleSheet("background-color: rgb(200,0,0)");

    myDialog->show();




}


void MainWindow::on_pushButton_3_clicked()
{



    ui->frame_7->setStyleSheet("background-color: rgb(0,200,0)");




}


void MainWindow::on_pushButton_5_clicked()
{



    ui->frame_8->setStyleSheet("background-color: rgb(0,200,0)");




}


void MainWindow::on_pushButton_6_clicked()
{

    ui->frame_8->setStyleSheet("background-color: rgb(200,0,0)");

}


void MainWindow::on_pushButton_7_clicked()
{

    ui->frame_9->setStyleSheet("background-color: rgb(0,200,0)");

}


void MainWindow::on_pushButton_8_clicked()
{
     ui->frame_9->setStyleSheet("background-color: rgb(200,0,0)");

}

