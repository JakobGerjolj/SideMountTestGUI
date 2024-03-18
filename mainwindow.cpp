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
        // qDebug()<<buffer;
    }

    //Parsing here myb move it later
    if(isFullBuffer){
        QString temp=buffer;
        temp.replace("<","");
        temp.replace(">","");
        QStringList listOfValues =temp.split(",");

        if(listOfValues.size()==20){
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

            ui->label_pin4V_SW->setText(listOfValues.at(1));//ADD MORE LABELS???

            bool temp_bool;


            if(listOfValues.at(7)=="0"){
                temp_bool=false;
            }else {
                temp_bool=true;
            }
            storage::setPinData("pin4V_SW", temp_bool, listOfValues.at(1).toFloat());
            // qDebug()<<"VARIABLE IN READATA";
            // qDebug()<<storage::getPinData("pin4V_SW");

            ui->label_pin3_3V_SW->setText(listOfValues.at(2));
            if(listOfValues.at(8)=="0"){
                temp_bool=false;
            }else {
                temp_bool=true;
            }
            storage::setPinData("pin3_3V_SW", temp_bool, listOfValues.at(2).toFloat());
            ui->label_pin5_SW->setText(listOfValues.at(3));
            if(listOfValues.at(9)=='0'){
                temp_bool=false;
            }else temp_bool=true;
            storage::setPinData("pin5V_SW", temp_bool, listOfValues.at(2).toFloat()); //need to add arduino
            ui->label_12V->setText(listOfValues.at(4));
            if(listOfValues.at(10)=='0'){
                temp_bool=false;
            }else temp_bool=true;
            storage::setPinData("pin12V", temp_bool, listOfValues.at(2).toFloat());

            // ui->button_frame->setStyleSheet("");
            // ui->can_frame->setStyleSheet("");
            // ui->hal_frame->setStyleSheet("");
            // ui->nfc_frame->setStyleSheet("");
            // ui->t1_frame->setStyleSheet("");
            // ui->t2_frame->setStyleSheet("");
            // ui->zero_frame->setStyleSheet("");


            if(listOfValues.at(5)=="5.00"){
                storage::setPinData("pin3_3V", true, 5.00);
                ui->label_pin3_3V->setText("HIGH");
            }else  {
                storage::setPinData("pin3_3V", false, 0.00);
                ui->label_pin3_3V->setText("LOW");
            }
            if(listOfValues.at(6)=="5.00"){
                storage::setPinData("pin4V", true, 5.00);
                ui->label_pin4V->setText("HIGH");
            }else {
                storage::setPinData("pin4V", false, 0.00);
                ui->label_pin4V->setText("LOW");

            }

            // qDebug()<<storage::getPinData("pin4V");
            ui->check_pins_frame_2->setStyleSheet("background-color: rgb(200,0,0)");



            // storage::setPinData("pin4V_SW",true,5.0); ?????????????????????????
            // storage::setPinData("pin3_3V_SW",true,5.0);
            // storage::setPinData("pin5V_SW",true,5.0);
            // storage::setPinData("pin12V",true,5.0);
            // storage::setPinData("pin3_3V",true,5.0);
            // storage::setPinData("pin4V",true,5.0);




            ui->button_frame->setStyleSheet("background-color: rgb(0,0,200)"); // skos
            // if(listOfValues.at(1)=='X'){
            //     ui->last_button_value->setText("X");
            // }else if(listOfValues.at(1)=='3'){
            //     ui->last_button_value->setText("3");//?? do it in one line
            // }else if(listOfValues.at(1)=='4'){
            //     ui->last_button_value->setText("4");
            // }

            ui->last_button_value->setText(listOfValues.at(13));
            ui->button_counter_value->setText(listOfValues.at(14));

            ui->nfc_frame->setStyleSheet("background-color: rgb(0,0,200)");
            if(listOfValues.at(15)=="1"){ //NFC
                QTimer::singleShot(1500, this, [this](){
                    ui->NFC_status->setText("DETECTED");
                    ui->nfc_frame->setStyleSheet("background-color: rgb(0,200,0)");

                });



            }



            ui->hal_frame->setStyleSheet("background-color: rgb(0,0,200)");
            ui->hal_value->setText(listOfValues.at(16)); //HAL

            ui->zero_frame->setStyleSheet("background-color: rgb(0,0,200)");
            ui->zero_value->setText(listOfValues.at(17));//ZERO

            ui->t1_frame->setStyleSheet("background-color: rgb(0,0,200)");
            ui->t1_value->setText(listOfValues.at(18)); //T1

            ui->t2_frame->setStyleSheet("background-color: rgb(0,0,200)");
            ui->t2_value->setText(listOfValues.at(19)); //T2


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
    storage::setButtonData("Button1", true, "");
    storage::setButtonData("Button2", true, "");


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
    m_NFC_status=true;
    ui->nfc_check_frame->setStyleSheet("background-color: rgb(0,200,0)");

}


void MainWindow::on_NFC_NOK_clicked()
{
    m_NFC_status=false;
    ui->nfc_check_frame->setStyleSheet("background-color: rgb(200,0,0)");

}


void MainWindow::on_HAL_OK_clicked()
{
    m_HAL_status=true;
    ui->hal_check_frame->setStyleSheet("background-color: rgb(0,200,0)");

}


void MainWindow::on_HAL_NOK_clicked()
{
    m_HAL_status=false;
    ui->hal_check_frame->setStyleSheet("background-color: rgb(200,0,0)");

}


void MainWindow::on_ZERO_OK_clicked()
{
    m_ZERO_status=true;
    ui->zero_check_frame->setStyleSheet("background-color: rgb(0,200,0)");
}


void MainWindow::on_ZERO_NOK_clicked()
{
    m_ZERO_status=false;
    ui->zero_check_frame->setStyleSheet("background-color: rgb(200,0,0)");
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


void MainWindow::on_pushButton_14_clicked() // REPORT BUTTON
{

    // qDebug()<<"------------------------------------------------";
    // qDebug()<<"SERIAL";
    storage::setSERIAL(ui->Serial_line->text().toStdString());
    // qDebug()<<storage::getSERIAL();
    // qDebug()<<"DATE TIME";
    storage::setDateTime(ui->dateTimeEdit->dateTime());
    // qDebug()<<storage::getDateTime();
    // qDebug()<<"EMPLOYEE";
    storage::setEmployee(ui->comboBox->currentText().toStdString());
    // qDebug()<<storage::getEmployee();
    // qDebug()<<"PINS";
    // qDebug()<<storage::getPinData("pin4V_SW");
    // qDebug()<<storage::getPinData("pin3_3V_SW");
    // qDebug()<<storage::getPinData("pin5V_SW");
    // qDebug()<<storage::getPinData("pin12V");
    // qDebug()<<storage::getPinData("pin3_3V");
    // qDebug()<<storage::getPinData("pin4V");


    // qDebug()<<"BUTTONS:";
    // qDebug()<<storage::getButtonData("Button1");
    // qDebug()<<storage::getButtonData("Button2");
    // qDebug()<<"NFC";
    storage::setNFCStatus(m_NFC_status);
    // qDebug()<<storage::getNFCStatus();
    // qDebug()<<"HAL";
    storage::setHALStatus(m_HAL_status);
    // qDebug()<<storage::getHALStatus();
    // qDebug()<<"ZERO";
    storage::setZEROStatus(m_ZERO_status);
    // qDebug()<<storage::getZEROStatus();
    // qDebug()<<"LEDS";
    // qDebug() << storage::getLedData("LED1");
    // qDebug() << storage::getLedData("LED2");
    // qDebug() << storage::getLedData("LED3");
    // qDebug() << storage::getLedData("LED4");
    // qDebug() << storage::getLedData("LED5");
    // qDebug() << storage::getLedData("LED6");
    // qDebug() << storage::getLedData("LED7");
    // qDebug() << storage::getLedData("LED8");
    // qDebug() << storage::getLedData("LED9");
    // qDebug() << "---------------------------------------";


    QString Serial, DateTime, Employee, pin4V_SW_isOK, pin4V_SW_value, pin3_3V_SW_isOK, pin3_3V_SW_value, pin5V_SW_isOK, pin5_SW_value, pin12V_isOK,pin12V_value, pin3_3V_isOK, pin3_3V_value, pin4V_isOK, pin4V_value;

    LedDataMap ledMapa=storage::getLedMap();

    Serial = QString::fromStdString(storage::getSERIAL());
    DateTime = storage::getDateTime().toString();
    Employee = QString::fromStdString(storage::getEmployee());
    // qDebug()<<"PIN1";
    // qDebug()<<storage::getPinData("pin4V_SW");
    if(storage::getPinData("pin4V_SW").first){
        pin4V_SW_isOK= "OK";
    }else {
        pin4V_SW_isOK= "NOT OK";
    }
    pin4V_SW_value= QString::number(storage::getPinData("pin4V_SW").second);
    if(storage::getPinData("pin3_3V_SW").first){
        pin3_3V_SW_isOK= "OK";
    }else {
        pin3_3V_SW_isOK= "NOT OK";
    }
    pin3_3V_SW_value= QString::number(storage::getPinData("pin3_3V_SW").second);
    if(storage::getPinData("pin5V_SW").first){
        pin5V_SW_isOK= "OK";
    }else {
        pin5V_SW_isOK= "NOT OK";
    }
    pin5_SW_value= QString::number(storage::getPinData("pin5V_SW").second);
    if(storage::getPinData("pin12V").first){
        pin12V_isOK="OK";
    }else {
        pin12V_isOK="NOT OK";
    }
    pin12V_value=QString::number(storage::getPinData("pin12V").second);
    if(storage::getPinData("pin3_3V").first){
        pin3_3V_isOK="OK";
    }else {
        pin3_3V_isOK="NOT OK";
    }
    pin3_3V_value=QString::number(storage::getPinData("pin3_3V").second);
    if(storage::getPinData("pin4V").first){
        pin4V_isOK="OK";
    }else {
        pin4V_isOK="NOT OK";
    }
    pin4V_value=QString::number(storage::getPinData("pin4V").second);
    // pin4V_SW_value=QString::number(storage::getPinData("pin4V").second);
    //Side mount test-SN


    //chekc if it already exists

    QString filepath = "/home/jakob/SideMountGUI/";
    QString filename = "/home/jakob/SideMountGUI/Side_Mount_test.";
    QString temps;
    filename.append(storage::getSERIAL());

    int index=1;

    QFileInfo fileInfo(filename);
    temps=filename;
    // temps.append(".txt");

    // while(fileInfo.exists()){
    //     filename.append(" ("+ QString::number(index) + ")");
    //     index++;
    // }

    while(fileInfo.exists(temps)){
        qDebug()<<"FILE ALREADY EXISTS!!";
        qDebug()<<"Appending";
        temps.append(" (");
        temps.append(QString::number(index));
        temps.append(")");
        index++;

    }
    temps.append(".txt");
    filename=temps;

    //filename.append(".txt");
    qDebug()<<"Filename: "<<filename;
    qDebug()<<"Temps"<<filename;
    int indok=1;
    while(true){
        if(fileInfo.exists(temps)){
            qDebug()<<"it already exists dont overwrite it";
            qDebug()<<"Adding number to not delete";
            if(temps[temps.length() -7] != '('){
                qDebug()<<"ADDING WRONG";
                temps.insert(temps.length() - 4, " (" + QString::number(indok) + ")");
            }else {
                qDebug()<<"ADDING RIGHT";
                temps.replace(temps.length() -6,1, QString::number(indok));
            }
        }else {
            break;

        }
        indok++;

    }
    filename=temps;


    QFile file(filename);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream stream(&file);
        stream<<"--------------------------------------------------------\n";
        stream<<Serial<<">";
        stream<<DateTime<<">";
        stream<<Employee;
        stream<<"\n";
        if(pin4V_SW_isOK=="NOT OK"){
            stream<<"pin4V_SW>"<<pin4V_SW_isOK<<">"<<pin4V_SW_value<<"\n";}
        else {
            stream<<"pin4V_SW>"<<pin4V_SW_isOK<<"\n";}
        if(pin3_3V_SW_isOK=="NOT OK"){
            stream<<"pin3_3V_SW>"<<pin3_3V_SW_isOK<<">"<<pin3_3V_SW_value<<"\n";}
        else {
            stream<<"pin3_3V_SW>"<<pin3_3V_SW_isOK<<"\n";}
        if(pin5V_SW_isOK=="NOT OK"){
            stream<<"pin5V_SW>"<<pin5V_SW_isOK<<">"<<pin5_SW_value<<"\n";
        }else  {
            stream<<"pin5V_SW>"<<pin5V_SW_isOK<<"\n";}
        if(pin12V_isOK=="NOT OK"){
            stream<<"pin12V>"<<pin12V_isOK<<">"<<pin12V_value<<"\n";
        }else  stream<<"pin12V>"<<pin12V_isOK<<"\n";
        if(pin3_3V_isOK=="NOT OK"){
            stream<<"pin3_3V>"<<pin3_3V_isOK<<">LOW"<<"\n";
        }else  stream<<"pin3_3V>"<<pin3_3V_isOK<<"\n";
        if(pin4V_isOK=="NOT OK"){
            stream<<"pin4V>"<<pin4V_isOK<<"LOW"<<"\n";
        }else  stream<<"pin4V>"<<pin4V_isOK<<"\n";



        for(auto led=ledMapa.begin();led!=ledMapa.end(); ++led){

            if(led->second.first){
                stream<<QString::fromStdString(led->first)<<">OK\n";
            }else {
                stream<<QString::fromStdString(led->first)<<">NOT OK: "<<QString::fromStdString(led->second.second)<<"\n";

            }

        }

        if(storage::getNFCStatus()){
            stream<<"NFC>OK\n";
        }else {
            stream<<"NFC>NOT OK\n";
        }

        if(storage::getHALStatus()){
            stream<<"HAL>OK\n";

        }else {
            stream<<"HAL>NOT OK\n";

        }

        if(storage::getZEROStatus()){
            stream<<"ZERO>OK\n";

        }else {
            stream<<"ZERO>NOT OK\n";

        }


    }

    file.close();
    qDebug()<<"Done good !";




}


void MainWindow::on_pushButton_clicked() // upload test FW
{

    QProcess process;

    QString firmwarePath ="/home/jakob/Documents/SIDEMOUNTJIG/Sidemount/Debug/Sidemount.elf";

    QString programmerPath="/mnt/98BC1F34BC1F0BFE/STMprogrammer/Installation/bin/STM32_Programmer.sh";

    // QString command = "/mnt/98BC1F34BC1F0BFE/STMprogrammer/Installation/bin/STM32_Programmer.sh";
    QStringList arguments;

    arguments << "-c" << "port=SWD";
    arguments << "-d" << firmwarePath;

    process.setProgram(programmerPath);
    process.setArguments(arguments);

   // process.start();
    QProcess::startDetached(programmerPath, arguments);
   // ui->pushButton->setEnabled(false);

    //process.start(command, arguments);

    //process.waitForFinished();

    // connect(&process, &QProcess::finished, this, [&](){
    //     ui->pushButton->setEnabled(true);
    //     qDebug() << "Failed to execute stm32Programmer";
    // });

    if(!process.waitForFinished()){
        qDebug() << "Failed to execute stm32Programmer";

    }


    //myb interact with UI a little bit
    // QByteArray output = process.readAllStandardOutput();

    // // Split the output into lines
    // QStringList lines = QString(output).split('\n', Qt::SkipEmptyParts);

    // // Print each line separately
    // qDebug() << "Output:";
    // for (const QString &line : lines) {
    //     qDebug().noquote() << line;
    // }



    int exitCode = process.exitCode();
    if(exitCode == 0){
        qDebug() << "Firmware good";

    }else {
        qDebug() << "Programmer not good" << exitCode;

    }


}


void MainWindow::on_pushButton_2_clicked()
{


    QProcess process;

    QString firmwarePath ="/home/jakob/Documents/BOOTLOADER/BootloaderCAN/Debug/BootloaderCAN.elf";

    QString programmerPath="/mnt/98BC1F34BC1F0BFE/STMprogrammer/Installation/bin/STM32_Programmer.sh";

    // QString command = "/mnt/98BC1F34BC1F0BFE/STMprogrammer/Installation/bin/STM32_Programmer.sh";
    QStringList arguments;

    arguments << "-c" << "port=SWD";
    arguments << "-d" << firmwarePath;

    process.setProgram(programmerPath);
    process.setArguments(arguments);

    process.start();

    //process.start(command, arguments);

    //process.waitForFinished();

    if(!process.waitForFinished()){
        qDebug() << "Failed to execute stm32Programmer";

    }


    //myb interact with UI a little bit
    // QByteArray output = process.readAllStandardOutput();

    // // Split the output into lines
    // QStringList lines = QString(output).split('\n', Qt::SkipEmptyParts);

    // // Print each line separately
    // qDebug() << "Output:";
    // for (const QString &line : lines) {
    //     qDebug().noquote() << line;
    // }



    int exitCode = process.exitCode();
    if(exitCode == 0){
        qDebug() << "Firmware good";

    }else {
        qDebug() << "Programmer not good" << exitCode;

    }

}

