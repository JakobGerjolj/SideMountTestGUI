#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    Report *report = new Report;
    m_report=report;
    m_processBootLoader= new QProcess;
    m_processSideMount = new QProcess;
    openSerialPort();
    ui->setupUi(this);
    QDateTime temp=QDateTime::currentDateTime();
    ui->dateTime->setText(temp.toString("dd.MM.yyyy hh:mm"));
    QStringList boys ={"Jakob Gerjolj","Anže Štravs","Jaka Dejak", "Nejc Česen"};
    ui->comboBox->addItems(boys);
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readData);
    storage::addPinData("pin4V_SW");
    storage::addPinData("pin3_3V_SW");
    storage::addPinData("pin5V_SW");
    storage::addPinData("pin12V");
    storage::addPinData("pin3_3V");
    storage::addPinData("pin4V");
    storage::addLedData("LED1");
    storage::addLedData("LED2");
    storage::addLedData("LED3");
    storage::addLedData("LED4");
    storage::addLedData("LED5");
    storage::addLedData("LED6");
    storage::addLedData("LED7");
    storage::addLedData("LED8");
    storage::addLedData("LED9");
    storage::addButtonData("BUTTON1");
    storage::addButtonData("BUTTON2");
    storage::setHALDesc("");
    storage::setZERODesc("");
    storage::setNFCDesc("");
    ui->nfc_textEdit->setVisible(false);
    ui->hal_textEdit->setVisible(false);
    ui->zero_textEdit->setVisible(false);
    ui->nfc_check_frame->setEnabled(false);
    ui->hal_check_frame->setEnabled(false);
    ui->zero_check_frame->setEnabled(false);
    ui->led_check_frame->setEnabled(false);
    ui->can_frame->setEnabled(false);
    ui->pushButton_14->setEnabled(false);

    m_timer=new QTimer;
    connect(m_timer, &QTimer::timeout, this, &MainWindow::emitConstantSignal);
    m_timer->start(1000);
    connect(this, &MainWindow::constantSignal, this, &MainWindow::handleConstantSignal);


}

void MainWindow::openSerialPort(){

    m_serial = new QSerialPort;
    m_serial->setPortName(m_ArduinoPort); //added variable from settings
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

   // qDebug()<<str;
    str.replace("\r\n","");

    if(!str.isEmpty()){
        if(str[0]=='<' && str[str.size() - 1] == '>'){
            buffer=str;
            isFullBuffer=true;
        }else if(str[0]=='<' &&  str[str.size() - 1] != '>'){
            buffer=str;
            isFullBuffer=false;

        }else if(str[0]!='<' && str[str.size() - 1] == '>'){
            buffer.append(str);
            isFullBuffer=true;
        }
    }
    if(isFullBuffer){

        //Debug purpose

    }


    if(isFullBuffer){
        QString temp=buffer;
       // qDebug()<<buffer;
        temp.replace("<","");
        temp.replace(">","");
        QStringList listOfValues =temp.split(",");

        if(listOfValues.size()==21){
            if(listOfValues.at(0)=="0"){
                ui->check_pins_frame->setVisible(false);
                ui->check_pins_frame_2->setVisible(true);
                ui->verticalLayout_2->setStretch(0,3);
                ui->verticalLayout_2->setStretch(1,3);
                ui->verticalLayout_2->setStretch(2,1);
                ui->verticalLayout_2->setStretch(3,1);
                ui->verticalLayout_2->setStretch(4,1);
                ui->verticalLayout_2->setStretch(5,1);
                ui->verticalLayout_2->setStretch(6,1);
                ui->verticalLayout_2->setStretch(7,1);
                ui->verticalLayout_2->setStretch(8,1);
            }else{
                ui->check_pins_frame->setVisible(true);
                ui->check_pins_frame_2->setVisible(false);
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

            }


            ui->label_pin4V_SW->setText(listOfValues.at(1));

            bool temp_bool;
            // qDebug()<<"REAL VALUE FROM ARDUINO:";
            // qDebug()<<listOfValues.at(1);

            //Need to format so 5.00V goes into 5.00 float
            if(listOfValues.at(7)=="0"){
                temp_bool=false;
                ui->isOK_label_4VSW->setStyleSheet("");
            }else {
                temp_bool=true;
                ui->isOK_label_4VSW->setStyleSheet("background-color: rgb(0,150,0)");
            }
            float temp=(listOfValues.at(1).left(4)).toFloat();
            // qDebug()<<"LEFT STRING";
            // qDebug()<<temp;
            storage::setPinData("pin4V_SW", temp_bool, (listOfValues.at(1).left(4)).toFloat()); // MYB WORK

            //process value so that 12V value * 11 5V value * 2


            ui->label_pin3_3V_SW->setText(listOfValues.at(2)); //pin3V_SW
            if(listOfValues.at(8)=="0"){
                temp_bool=false;
                ui->isOK_label_33VSW->setStyleSheet("");
            }else {
                ui->isOK_label_33VSW->setStyleSheet("background-color: rgb(0,150,0)");
                temp_bool=true;
            }


            storage::setPinData("pin3_3V_SW", temp_bool, listOfValues.at(2).left(4).toFloat());

            float temp5V;
            temp5V = listOfValues.at(3).left(4).toFloat();
            temp5V = temp5V*2;

            QString temp5VString;
            temp5VString = QString::number(temp5V);
            temp5VString += "V";

            ui->label_pin5_SW->setText(temp5VString);
            if(listOfValues.at(9)=='0'){
                temp_bool=false;
                ui->isOK_label_5VSW->setStyleSheet("");
            }else {
                ui->isOK_label_5VSW->setStyleSheet("background-color: rgb(0,150,0)");
                temp_bool=true;}

            storage::setPinData("pin5V_SW", temp_bool, listOfValues.at(2).left(4).toFloat()); //need to add arduino

            float temp12V;
            // qDebug()<<"RAW FROM LIST:"<<listOfValues.at(4);
            temp12V = listOfValues.at(4).left(4).toFloat();
            temp12V = temp12V * 11;
            // qDebug()<<"Float value of 12V: "<<temp12V;
            QString temp12VString;
            temp12VString = QString::number(temp12V);
            temp12VString += "V";
            // qDebug()<<"String Value of 12V: "<<temp12VString;
            ui->label_12V->setText(temp12VString);
            if(listOfValues.at(10)=='0'){
                temp_bool=false;
                ui->isOK_label12V->setStyleSheet("");
            }else {
                ui->isOK_label12V->setStyleSheet("background-color: rgb(0,150,0)");
                temp_bool=true;}

            storage::setPinData("pin12V", temp_bool, temp12V);
            if(listOfValues.at(5)=="5.00V"){
                storage::setPinData("pin3_3V", true, 5.00);
                ui->label_pin3_3V->setText("HIGH");
                ui->isOK_labelpin33V->setStyleSheet("background-color: rgb(0,150,0)");
            }else  {
                storage::setPinData("pin3_3V", false, 0.00);
                ui->label_pin3_3V->setText("LOW");
                ui->isOK_labelpin33V->setStyleSheet("");

            }
            if(listOfValues.at(6)=="5.00V"){
                storage::setPinData("pin4V", true, 5.00);
                ui->label_pin4V->setText("HIGH");
                ui->isOK_label_4V->setStyleSheet("background-color: rgb(0,150,0)");
            }else {
                storage::setPinData("pin4V", false, 0.00);
                ui->label_pin4V->setText("LOW");
                ui->isOK_label_4V->setStyleSheet("");

            }
            ui->check_pins_frame_2->setStyleSheet("background-color: rgb(200,0,0)");
            ui->button_frame->setStyleSheet("background-color: rgb(0,0,200)");
            ui->last_button_value->setText(listOfValues.at(13));
            ui->button_counter_value->setText(listOfValues.at(14));

            ui->nfc_frame->setStyleSheet("background-color: rgb(0,0,200)");
            if(listOfValues.at(15)=="1"){ //NFC
                QTimer::singleShot(1, this, [this](){
                    ui->NFC_status->setText("DETECTED");
                    ui->nfc_frame->setStyleSheet("background-color: rgb(0,200,0)");
                });
            }
            if(ui->NFC_status->text()=="DETECTED"){
                ui->nfc_frame->setStyleSheet("background-color: rgb(0,200,0)");
            }
            ui->hal_frame->setStyleSheet("background-color: rgb(0,0,200)");
            ui->hal_value->setText(listOfValues.at(16)); //HAL


            if(listOfValues.at(17)=="1"){
                ui->zero_frame->setStyleSheet("background-color: rgb(0,200,0)");
            }else {
                ui->zero_frame->setStyleSheet("background-color: rgb(0,0,200)");

            }
            ui->zero_value->setText(listOfValues.at(17));//ZERO

            ui->t1_frame->setStyleSheet("background-color: rgb(0,0,200)");
            ui->t1_value->setText(listOfValues.at(18)); //T1

            ui->t2_frame->setStyleSheet("background-color: rgb(0,0,200)");
            ui->t2_value->setText(listOfValues.at(19)); //T2

            if(listOfValues.at(20) == "1"){
                ui->can_frame->setStyleSheet("background-color: rgb(0,200,0)");

            }

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

void MainWindow::handleConstantSignal()
{
    QDateTime temp=QDateTime::currentDateTime();
    storage::setDateTime(temp);
    ui->dateTime->setText(temp.toString("dd.MM.yyyy hh:mm"));

}

void MainWindow::emitConstantSignal()
{
    emit constantSignal();

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
    storage::setButtonData("Button1", true, "");
    storage::setButtonData("Button2", true, "");
    ui->nfc_check_frame->setEnabled(true);

    ui->buttons_check_frame->setStyleSheet("background-color: rgb(0,200,0)");
}


void MainWindow::on_Buttons_NOK_clicked()
{

    Dialog* myDialog = new Dialog(this,"What is wrong with buttons: ");
    myDialog->show();
   // ui->buttons_check_frame->setStyleSheet("background-color: rgb(200,0,0)");
    qDebug()<<"Are they OK";


    if(myDialog->exec() == QDialog::Accepted){ // not work yet
        if(storage::areAllButtonsOK()){
            qDebug()<<storage::areAllButtonsOK();
            ui->buttons_check_frame->setStyleSheet("background-color: rgb(0,200,0)");
            ui->nfc_check_frame->setEnabled(true);
        }

    }


}


void MainWindow::on_NFC_OK_clicked()
{
    m_NFC_status=true;
    ui->hal_check_frame->setEnabled(true);
    ui->nfc_check_frame->setStyleSheet("background-color: rgb(0,200,0)");
    ui->nfc_textEdit->setVisible(false);

}


void MainWindow::on_NFC_NOK_clicked()
{
    m_NFC_status=false;
    ui->nfc_check_frame->setStyleSheet("background-color: rgb(200,0,0)");
    ui->nfc_textEdit->setVisible(true);
    ui->nfc_textEdit->setPlaceholderText("Describe the NFC problem...");
    ui->hal_check_frame->setEnabled(true);

}


void MainWindow::on_HAL_OK_clicked()
{
    m_HAL_status=true;
    ui->hal_check_frame->setStyleSheet("background-color: rgb(0,200,0)");
    ui->hal_textEdit->setVisible(false);
    ui->zero_check_frame->setEnabled(true);

}


void MainWindow::on_HAL_NOK_clicked()
{
    m_HAL_status=false;
    ui->hal_check_frame->setStyleSheet("background-color: rgb(200,0,0)");
    ui->hal_textEdit->setVisible(true);
    ui->hal_textEdit->setPlaceholderText("Describe the HAL problem...");
    ui->zero_check_frame->setEnabled(true);

}


void MainWindow::on_ZERO_OK_clicked()
{
    m_ZERO_status=true;
    ui->zero_check_frame->setStyleSheet("background-color: rgb(0,200,0)");
    ui->zero_textEdit->setVisible(false);
    ui->led_check_frame->setEnabled(true);
}


void MainWindow::on_ZERO_NOK_clicked()
{
    m_ZERO_status=false;
    ui->zero_check_frame->setStyleSheet("background-color: rgb(200,0,0)");
    ui->zero_textEdit->setVisible(true);
    ui->zero_textEdit->setPlaceholderText("Describe the ZERO problem...");
    ui->led_check_frame->setEnabled(true);
}


void MainWindow::on_LED_OK_clicked()
{
    storage::setLedData("LED1", true, "");
    storage::setLedData("LED2", true, "");
    storage::setLedData("LED3", true, "");
    storage::setLedData("LED4", true, "");
    storage::setLedData("LED5", true, "");
    storage::setLedData("LED6", true, "");
    storage::setLedData("LED7", true, "");
    storage::setLedData("LED8", true, "");
    storage::setLedData("LED9", true, "");
    ui->can_frame->setEnabled(true);
    ui->pushButton_14->setEnabled(true);
    ui->led_check_frame->setStyleSheet("background-color: rgb(0,200,0)");
}


void MainWindow::on_LED_NOK_clicked()
{
    DialogLED* myDialog = new DialogLED(this);
    myDialog->show();
  //  ui->led_check_frame->setStyleSheet("background-color: rgb(200,0,0)");
    connect(myDialog, &DialogLED::triggerLEDs, this, &MainWindow::onTriggerLED);

    if(myDialog->exec() == QDialog::Accepted){
        if(storage::areAllLEDsOK()){
            ui->led_check_frame->setStyleSheet("background-color: rgb(0,200,0)");
            ui->can_frame->setEnabled(true);
            ui->pushButton_14->setEnabled(true);
        }

    }

}



void MainWindow::on_pushButton_3_clicked()
{

    QDateTime currentDateTime = QDateTime::currentDateTime();
    // ui->dateTimeEdit->setDateTime(currentDateTime);

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
    QString testS="<LED>";
    writeData(testS.toUtf8());
}


void MainWindow::on_pushButton_16_clicked()
{
    QString testS="<LED>";
    writeData(testS.toUtf8());     // process.setArguments(arguments);

}


void MainWindow::on_pushButton_14_clicked() // REPORT BUTTON
{

    ui->NFC_status->setText("X");
    ui->nfc_frame->setStyleSheet("background-color: rgb(0,0,200)");
    ui->buttons_check_frame->setStyleSheet("");
    ui->nfc_check_frame->setStyleSheet("");
    ui->hal_check_frame->setStyleSheet("");
    ui->zero_check_frame->setStyleSheet("");
    ui->led_check_frame->setStyleSheet("");
    ui->can_frame->setStyleSheet("");
    ui->nfc_check_frame->setEnabled(false);
    ui->hal_check_frame->setEnabled(false);
    ui->zero_check_frame->setEnabled(false);
    ui->led_check_frame->setEnabled(false);
    ui->can_frame->setEnabled(false);
    QMessageBox msgBox;
    msgBox.setText("Report created");
    msgBox.exec();
    storage::setNFCDesc(ui->nfc_textEdit->toPlainText().toStdString());
    storage::setHALDesc(ui->hal_textEdit->toPlainText().toStdString());
    storage::setZERODesc(ui->zero_textEdit->toPlainText().toStdString());
    storage::setSERIAL(ui->Serial_line->text().toStdString());
    // storage::setDateTime(ui->dateTimeEdit->dateTime());
    storage::setEmployee(ui->comboBox->currentText().toStdString());
    storage::setNFCStatus(m_NFC_status);
    storage::setHALStatus(m_HAL_status);
    storage::setZEROStatus(m_ZERO_status);
    qDebug()<<"Attempting cleaner report";
    m_report->createReport();

}


void MainWindow::on_pushButton_clicked() //upload test FW
{
    m_processOutput="";
    QString outp;
    QString firmwarePath ="/home/jakob/Documents/SIDEMOUNTJIG/Sidemount/Debug/Sidemount.bin";
    QString programmerPath="/mnt/98BC1F34BC1F0BFE/STMprogrammer/Installation/bin/STM32_Programmer.sh";
    QStringList arguments;
    arguments << "-c" << "port=SWD";
    arguments << "-d" << firmwarePath << "0x08000000 ";;
    m_processSideMount->setProgram(programmerPath);
    m_processSideMount->setArguments(arguments);
    m_processSideMount->start();
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->status_label->setText("Uploading sidemount firmware");

    QObject::connect(m_processSideMount, &QProcess::readyReadStandardOutput, [&]() {
        QByteArray output = m_processSideMount->readAllStandardOutput();
        QStringList lines = QString(output).split("\n", Qt::SkipEmptyParts);
        // qDebug() << "Process output:" << QString(output); //output, also gives success state
        m_processOutput.append(output);
        //  outp=QString::fromUtf8(output);
    });


    connect(m_processSideMount, &QProcess::finished, this, [&](){
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->status_label->setText("Uploaded sidemount firmware");
        // m_processOutput = m_processSideMount->readAllStandardOutput();
        qDebug()<<"______START_OF_STRING___________";
        qDebug()<<m_processOutput;

        if(m_processOutput.contains("Error:")){
            qDebug()<<"Error detected this is the error:";
            QString error;
            error= m_processOutput.mid(m_processOutput.indexOf("Error:")+6,35); // sending error, try up to \n
            ui-> status_label->setText("Error in uploading: " + error); // do the same for bootloader
        }
        //outp=QString::fromUtf8(output);
        //qDebug()<<outp;

    });

}


void MainWindow::on_pushButton_2_clicked() //upload bootloader
{
    m_processOutput="";
    QProcess process;
    QString firmwarePath=m_BootloaderPath; //changed to variable
    QString programmerPath="/mnt/98BC1F34BC1F0BFE/STMprogrammer/Installation/bin/STM32_Programmer.sh";
    QStringList arguments;
    arguments << "-c" << "port=SWD";
    arguments << "-d" << firmwarePath << "0x08000000 ";
    m_processBootLoader->setProgram(programmerPath);
    m_processBootLoader->setArguments(arguments);
    m_processBootLoader->start();
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->status_label->setText("Uploading bootloader");


    QObject::connect(m_processBootLoader, &QProcess::readyReadStandardOutput, [&]() {
        QByteArray output = m_processSideMount->readAllStandardOutput();
        QStringList lines = QString(output).split("\n", Qt::SkipEmptyParts);
        // qDebug() << "Process output:" << QString(output); //output, also gives success state
        m_processOutput.append(output);
        //  outp=QString::fromUtf8(output);
    });


    connect(m_processBootLoader, &QProcess::finished, this, [&](){
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->status_label->setText("Uploaded bootloader");
        if(m_processOutput.contains("Error:")){
            qDebug()<<"Error detected this is the error:";
            QString error;
            error= m_processOutput.mid(m_processOutput.indexOf("Error:")+6,35); // sending error, try up to \n
            ui-> status_label->setText("Error in uploading: " + error); // do the same for bootloader
        }else {


        }

    });

}


void MainWindow::on_settings_button_clicked()
{
    settingsDialog* settDialog = new settingsDialog(this);
    closeSerialPort();
    if(settDialog->exec() == QDialog::Accepted){
        qDebug()<<"Accepted";
        qDebug()<<settDialog->getBotPath();
        qDebug()<<"Arduino port:"; // Getting settings
        qDebug()<<settDialog->getArduinoPort();
        m_ArduinoPort = settDialog->getArduinoPort();
        m_BootloaderPath = settDialog->getBotPath();
        openSerialPort();
        connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readData);
    }

}

void MainWindow::on_actionSettings_triggered()
{
    qDebug()<<"Pressed settings!";
}

void MainWindow::on_actionSettings_changed()
{
    qDebug()<<"Pressed settings!";
}

