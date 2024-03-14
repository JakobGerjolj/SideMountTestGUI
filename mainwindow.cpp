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
    QStringList boys ={"Jakob Gerjolj","Anže Štravs","Jaka Dejak", "Nejc Česen"};
    ui->comboBox->addItems(boys);
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readData);
   // storage::





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
   // qDebug()<<data;
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

        ui->check_pins_frame->setVisible(false);
        ui->check_pins_frame_2->setVisible(true);

        ui->verticalLayout_2->setStretch(0,2);
        ui->verticalLayout_2->setStretch(1,2);
        ui->verticalLayout_2->setStretch(2,1);
        ui->verticalLayout_2->setStretch(3,1);
        ui->verticalLayout_2->setStretch(4,1);
        ui->verticalLayout_2->setStretch(5,1);
        ui->verticalLayout_2->setStretch(6,1);
        ui->verticalLayout_2->setStretch(7,1);
        ui->verticalLayout_2->setStretch(8,1);

        ui->label_pin4V_SW->setText(listOfValues.at(1));
        ui->label_pin3_3V_SW->setText(listOfValues.at(2));
        ui->label_pin5_SW->setText(listOfValues.at(3));
        ui->label_12V->setText(listOfValues.at(4));

        // ui->button_frame->setEnabled(false);
        // ui->can_frame->setEnabled(false);
        // ui->hal_frame->setEnabled(false);
        // ui->nfc_frame->setEnabled(false);
        // ui->t1_frame->setEnabled(false);
        // ui->t2_frame->setEnabled(false);
        // ui->zero_frame->setEnabled(false);

        ui->button_frame->setStyleSheet("");
        ui->can_frame->setStyleSheet("");
        ui->hal_frame->setStyleSheet("");
        ui->nfc_frame->setStyleSheet("");
        ui->t1_frame->setStyleSheet("");
        ui->t2_frame->setStyleSheet("");
        ui->zero_frame->setStyleSheet("");


        if(listOfValues.at(5)=="5.00"){
        ui->label_pin3_3V->setText("HIGH");
        }else  ui->label_pin3_3V->setText("LOW");
        if(listOfValues.at(6)=="5.00"){
            ui->label_pin4V->setText("HIGH");
        }else  ui->label_pin4V->setText("LOW");


        ui->check_pins_frame_2->setStyleSheet("background-color: rgb(200,0,0)");

    }else {

        // ui->button_frame->setEnabled(true);
        // ui->can_frame->setEnabled(true);
        // ui->hal_frame->setEnabled(true);
        // ui->nfc_frame->setEnabled(true);
        // ui->t1_frame->setEnabled(true);
        // ui->t2_frame->setEnabled(true);
        // ui->zero_frame->setEnabled(true);



        QLayout* existingLayout = ui->check_pins_frame->layout();

        ui->check_pins_frame->setVisible(true);
        ui->check_pins_frame_2->setVisible(false);
       // QVBoxLayout *labelsLayout2 = new QVBoxLayout(ui->check_pins_frame);
       // QLabel *label4 = new QLabel("PINS OK");
        //labelsLayout2->addWidget(label4);
        // if(!ui->check_pins_frame->layout()){
        //     ui->check_pins_frame->setLayout(labelsLayout2);

        // }

        ui->label_3->setText("PINS OK");

        ui->verticalLayout_2->setStretch(0,1);
        ui->verticalLayout_2->setStretch(1,1);
        ui->verticalLayout_2->setStretch(2,1);
        ui->verticalLayout_2->setStretch(3,1);
        ui->verticalLayout_2->setStretch(4,1);
        ui->verticalLayout_2->setStretch(5,1);
        ui->verticalLayout_2->setStretch(6,1);
        ui->verticalLayout_2->setStretch(7,1);
        ui->verticalLayout_2->setStretch(8,1);
        ui->check_pins_frame->setStyleSheet("background-color: rgb(0,200,0)");


        ui->button_frame->setStyleSheet("background-color: rgb(0,0,200)"); // ce beremo
        if(listOfValues.at(1)=='X'){
            ui->last_button_value->setText("X");
        }else if(listOfValues.at(1)=='3'){
            ui->last_button_value->setText("3");
        }else if(listOfValues.at(1)=='4'){
            ui->last_button_value->setText("4");
        }

        ui->button_counter_value->setText(listOfValues.at(2));




        ui->nfc_frame->setStyleSheet("background-color: rgb(0,0,200)");
        if(listOfValues.at(3)=="1"){ //NFC

            QTimer::singleShot(1500, this, [this](){
                ui->NFC_status->setText("DETECTED");
                ui->nfc_frame->setStyleSheet("background-color: rgb(0,200,0)");




            });



        }



        ui->hal_frame->setStyleSheet("background-color: rgb(0,0,200)");
        ui->hal_value->setText(listOfValues.at(4)); //HAL

        ui->zero_frame->setStyleSheet("background-color: rgb(0,0,200)");
        ui->zero_value->setText(listOfValues.at(5));//ZERO

        ui->t1_frame->setStyleSheet("background-color: rgb(0,0,200)");
        ui->t1_value->setText(listOfValues.at(6)); //T1

        ui->t2_frame->setStyleSheet("background-color: rgb(0,0,200)");
        ui->t2_value->setText(listOfValues.at(7)); //T2


    }
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

void MainWindow::onTriggerLED()
{
    qDebug()<<"Signal reached Main!";
    writeData("<LED>");

}

void MainWindow::writeData(const QByteArray &data1)
{

    const qint64 written = m_serial->write(data1);
    if (written == data1.size()) {
        qDebug()<<"Written well";
    } else {
        const QString error = tr("Failed to write all data to port %1.\n"
                                 "Error: %2").arg(m_serial->portName(),
                                       m_serial->errorString());
        qDebug()<<error;
    }

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
    DialogLED* myDialog = new DialogLED(this);
    myDialog->show();
    ui->led_check_frame->setStyleSheet("background-color: rgb(200,0,0)");
    connect(myDialog, &DialogLED::triggerLEDs, this, &MainWindow::onTriggerLED);

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


void MainWindow::on_LED_OK_2_clicked()
{
    ui->can_frame->setStyleSheet("background-color: rgb(0,200,0)");
}


void MainWindow::on_LED_NOK_2_clicked()
{
    ui->can_frame->setStyleSheet("background-color: rgb(200,0,0)");
}


void MainWindow::on_pushButton_13_clicked()
{
    QString testS="<LED>";
    writeData(testS.toUtf8());
}


void MainWindow::on_pushButton_15_clicked()
{
    QString testS="<CAN>";
    writeData(testS.toUtf8());
}


void MainWindow::on_pushButton_16_clicked()
{
    QString testS="<CANLED>";
    writeData(testS.toUtf8());

}

