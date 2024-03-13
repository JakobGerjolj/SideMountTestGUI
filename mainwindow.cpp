#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    QDateTime currentDateTime = QDateTime::currentDateTime();
    ui->dateTimeEdit->setDateTime(currentDateTime);
    //ui->buttons_check_frame->setEnabled(false); How to grey out
    QStringList boys ={"Jakob Gerjolj","Anže Štravs","Jaka Dejak", "Nejc Česen"};
    ui->comboBox->addItems(boys);


}

void MainWindow::openSerialPort(){

    m_serial = new QSerialPort;
    m_serial->setPortName("/dev/ttyACM0");
    m_serial->setBaudRate(115200);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);
    if (!(m_serial->open(QIODevice::ReadWrite))) {
        qDebug() << "Serial Open error" << "\n";
    } else {
        qDebug() << "Serial port Open" << "\n";
    }

}

void MainWindow::readData(){

    const QByteArray data = m_serial->readAll();
    qDebug()<<data;


}

void MainWindow::closeSerialPort(){

    if (m_serial->isOpen())
        m_serial->close();
    qDebug() << "Disconnected"<< "\n";

}

MainWindow::~MainWindow()
{
    closeSerialPort();
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

