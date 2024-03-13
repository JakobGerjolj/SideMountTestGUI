#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    openSerialPort();
    ui->setupUi(this);
    QDateTime currentDateTime = QDateTime::currentDateTime();
    ui->dateTimeEdit->setDateTime(currentDateTime);
    //ui->buttons_check_frame->setEnabled(false); How to grey out
    QStringList boys ={"Jakob Gerjolj","Anže Štravs","Jaka Dejak", "Nejc Česen"};
    ui->comboBox->addItems(boys);
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readData);




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

    QString str = QString::fromUtf8(data);
    str.replace("\r\n","");

    if(!str.isEmpty()){
    if(str[0]=='<' && str[str.size() - 1] == '>'){
        buffer=str;
        isFullBuffer=true;
    }else if(str[0]=='<' &&  str[str.size() - 1] != '>'){
        buffer=str;
        isFullBuffer=false;

    }else if(str[0]!='<' && str[str.size()-1] == '>'){
        buffer.append(str);
        isFullBuffer=true;
    }
    }
    if(isFullBuffer){
    qDebug()<<buffer;
    }

    //Parsing here myb move it later
    if(isFullBuffer){
        QString temp=buffer;
    temp.replace("<","");
    temp.replace(">","");
    QStringList listOfValues =temp.split(",");

    if(listOfValues.at(0)=="0"){

        // QLayout* existingLayout = ui->check_pins_frame->layout();

        ui->check_pins_frame->setVisible(false);
        ui->check_pins_frame_2->setVisible(true);

        // if (existingLayout && stateOfCan!=1 && false) {
        //     QLayoutItem* child;
        //     while ((child = existingLayout->takeAt(0)) != nullptr) {
        //         delete child->widget();
        //         delete child;
        //     }

        //     ui->check_pins_frame->setLayout(nullptr);
        //     stateOfCan=0;
        // }


       // ui->check_pins_frame

      // ui->check_pins_frame->resize(411,150);

       QVBoxLayout *labelsLayout1 = new QVBoxLayout(ui->check_pins_frame);

       QLabel *label1 = new QLabel("Label 1");
       QLabel *label2 = new QLabel("Label 2");
       QLabel *label3 = new QLabel("Label 3");

       labelsLayout1->addWidget(label1);
       labelsLayout1->addWidget(label2);
       labelsLayout1->addWidget(label3);

      // if(stateOfCan==2){
       ui->check_pins_frame->setLayout(labelsLayout1);
             stateOfCan=1;
     //  }

             //need to display values add later

        ui->verticalLayout_2->setStretch(0,4);
        ui->verticalLayout_2->setStretch(1,4);
        ui->verticalLayout_2->setStretch(2,1);
        ui->verticalLayout_2->setStretch(3,1);
        ui->verticalLayout_2->setStretch(4,1);
        ui->verticalLayout_2->setStretch(5,1);
        ui->verticalLayout_2->setStretch(6,1);
        ui->verticalLayout_2->setStretch(7,1);


        ui->check_pins_frame_2->setStyleSheet("background-color: rgb(200,0,0)");

    }else {
        QLayout* existingLayout = ui->check_pins_frame->layout();

        ui->check_pins_frame->setVisible(true);
        ui->check_pins_frame_2->setVisible(false);

        if (existingLayout && stateOfCan!=2 && false) {
            // Remove all child widgets from the layout and delete them
            QLayoutItem* child;
            while ((child = existingLayout->takeAt(0)) != nullptr) {
                delete child->widget();
                delete child;
            }

            ui->check_pins_frame->setLayout(nullptr);
            stateOfCan=0;
        }


        QVBoxLayout *labelsLayout2 = new QVBoxLayout(ui->check_pins_frame);
        QLabel *label4 = new QLabel("PINS OK");
        labelsLayout2->addWidget(label4);
        if(stateOfCan==0){
            ui->check_pins_frame->setLayout(labelsLayout2);
            stateOfCan=2;
        }


        ui->verticalLayout_2->setStretch(0,1);
        ui->verticalLayout_2->setStretch(1,1);
        ui->verticalLayout_2->setStretch(2,1);
        ui->verticalLayout_2->setStretch(3,1);
        ui->verticalLayout_2->setStretch(4,1);
        ui->verticalLayout_2->setStretch(5,1);
        ui->verticalLayout_2->setStretch(6,1);
        ui->verticalLayout_2->setStretch(7,1);
        ui->check_pins_frame->setStyleSheet("background-color: rgb(0,200,0)");
       // ui->check_pins_frame->resize(411,71);

        ui->button_frame->setStyleSheet("background-color: rgb(0,108,179)"); // ce beremo
        if(listOfValues.at(1)=='X'){
            ui->last_button_value->setText("X");
        }else if(listOfValues.at(1)=='3'){
            ui->last_button_value->setText("3");
        }else if(listOfValues.at(1)=='4'){
            ui->last_button_value->setText("4");
        }

        ui->button_counter_value->setText(listOfValues.at(2));

       // listOfValues.at(3) // NFC

        if(listOfValues.at(3)=="1"){
            ui->NFC_status->setText("DETECTED");
            ui->nfc_frame->setStyleSheet("background-color: rgb(0,200,0)");
        }

        //listOfValues.at(4) // HAL

         ui->button_frame->setStyleSheet("background-color: rgb(0,108,179)");
        ui->hal_value->setText(listOfValues.at(4));

    }

    qDebug()<<listOfValues.at(1);
    qDebug()<<stateOfCan;

    }

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

