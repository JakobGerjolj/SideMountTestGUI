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

    QColor greenColor(255,0,0);
    QPalette palette;
    palette.setColor(QPalette::WindowText, greenColor);

    ui->frame_7->setStyleSheet("background-color: rgb(200,0,0)");

    myDialog->show();




}


void MainWindow::on_pushButton_3_clicked()
{

    QColor greenColor(0,255,0);
    QPalette palette;
    palette.setColor(QPalette::WindowText, greenColor);

    ui->frame_7->setStyleSheet("background-color: rgb(0,200,0)");




}

