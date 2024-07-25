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
    QStringList boys ={ "Matej Koranter","Nejc Česen","Jaka Dejak","Jakob Gerjolj","Anže Štravs"};
    ui->comboBox->addItems(boys);
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readData);
    //Filling lookup table
    lookupTable.insert(-40, 188.5);
    lookupTable.insert(-39, 178.6);
    lookupTable.insert(-38, 169.2);
    lookupTable.insert(-37, 160.4);
    lookupTable.insert(-36, 152.1);
    lookupTable.insert(-35, 144.3);
    lookupTable.insert(-34, 136.9);
    lookupTable.insert(-33, 130);
    lookupTable.insert(-32, 123.4);
    lookupTable.insert(-31, 117.2);
    lookupTable.insert(-30, 111.3);
    lookupTable.insert(-29, 105.8);
    lookupTable.insert(-28, 100.6);
    lookupTable.insert(-27, 95.64);
    lookupTable.insert(-26, 90.97);
    lookupTable.insert(-25, 86.56);
    lookupTable.insert(-24, 82.38);
    lookupTable.insert(-23, 78.43);
    lookupTable.insert(-22, 74.69);
    lookupTable.insert(-21, 71.14);
    lookupTable.insert(-20, 67.79);
    lookupTable.insert(-19, 64.61);
    lookupTable.insert(-18, 61.6);
    lookupTable.insert(-17, 58.74);
    lookupTable.insert(-16, 56.03);
    lookupTable.insert(-15, 53.46);
    lookupTable.insert(-14, 51.03);
    lookupTable.insert(-13, 48.71);
    lookupTable.insert(-12, 46.52);
    lookupTable.insert(-11, 44.43);
    lookupTable.insert(-10, 42.45);
    lookupTable.insert(-9, 40.57);
    lookupTable.insert(-8, 38.78);
    lookupTable.insert(-7, 37.08);
    lookupTable.insert(-6, 35.46);
    lookupTable.insert(-5, 33.93);
    lookupTable.insert(-4, 32.46);
    lookupTable.insert(-3, 31.07);
    lookupTable.insert(-2, 29.75);
    lookupTable.insert(-1, 28.49);
    lookupTable.insert(0, 27.28);
    lookupTable.insert(1, 26.14);
    lookupTable.insert(2, 25.05);
    lookupTable.insert(3, 24.01);
    lookupTable.insert(4, 23.02);
    lookupTable.insert(5, 22.07);
    lookupTable.insert(6, 21.17);
    lookupTable.insert(7, 20.31);
    lookupTable.insert(8, 19.49);
    lookupTable.insert(9, 18.71);
    lookupTable.insert(10, 17.96);
    lookupTable.insert(11, 17.25);
    lookupTable.insert(12, 16.57);
    lookupTable.insert(13, 15.91);
    lookupTable.insert(14, 15.29);
    lookupTable.insert(15, 14.7);
    lookupTable.insert(16, 14.13);
    lookupTable.insert(17, 13.59);
    lookupTable.insert(18, 13.07);
    lookupTable.insert(19, 12.57);
    lookupTable.insert(20, 12.09);
    lookupTable.insert(21, 11.64);
    lookupTable.insert(22, 11.2);
    lookupTable.insert(23, 10.78);
    lookupTable.insert(24, 10.38);
    lookupTable.insert(25, 10);
    lookupTable.insert(26, 9.633);
    lookupTable.insert(27, 9.282);
    lookupTable.insert(28, 8.945);
    lookupTable.insert(29, 8.622);
    lookupTable.insert(30, 8.312);
    lookupTable.insert(31, 8.015);
    lookupTable.insert(32, 7.73);
    lookupTable.insert(33, 7.456);
    lookupTable.insert(34, 7.194);
    lookupTable.insert(35, 6.942);
    lookupTable.insert(36, 6.7);
    lookupTable.insert(37, 6.468);
    lookupTable.insert(38, 6.245);
    lookupTable.insert(39, 6.031);
    lookupTable.insert(40, 5.826);
    lookupTable.insert(41, 5.628);
    lookupTable.insert(42, 5.438);
    lookupTable.insert(43, 5.255);
    lookupTable.insert(44, 5.08);
    lookupTable.insert(45, 4.911);
    lookupTable.insert(46, 4.749);
    lookupTable.insert(47, 4.592);
    lookupTable.insert(48, 4.442);
    lookupTable.insert(49, 4.297);
    lookupTable.insert(50, 4.158);
    lookupTable.insert(51, 4.024);
    lookupTable.insert(52, 3.895);
    lookupTable.insert(53, 3.771);
    lookupTable.insert(54, 3.651);
    lookupTable.insert(55, 3.536);
    lookupTable.insert(56, 3.425);
    lookupTable.insert(57, 3.318);
    lookupTable.insert(58, 3.215);
    lookupTable.insert(59, 3.115);
    lookupTable.insert(60, 3.019);
    lookupTable.insert(61, 2.927);
    lookupTable.insert(62, 2.837);
    lookupTable.insert(63, 2.751);
    lookupTable.insert(64, 2.668);
    lookupTable.insert(65, 2.588);
    lookupTable.insert(66, 2.511);
    lookupTable.insert(67, 2.436);
    lookupTable.insert(68, 2.364);
    lookupTable.insert(69, 2.295);
    lookupTable.insert(70, 2.227);
    lookupTable.insert(71, 2.163);
    lookupTable.insert(72, 2.1);
    lookupTable.insert(73, 2.039);
    lookupTable.insert(74, 1.981);
    lookupTable.insert(75, 1.924);
    lookupTable.insert(76, 1.869);
    lookupTable.insert(77, 1.817);
    lookupTable.insert(78, 1.765);
    lookupTable.insert(79, 1.716);
    lookupTable.insert(80, 1.668);
    lookupTable.insert(81, 1.622);
    lookupTable.insert(82, 1.577);
    lookupTable.insert(83, 1.534);
    lookupTable.insert(84, 1.492);
    lookupTable.insert(85, 1.451);
    lookupTable.insert(86, 1.412);
    lookupTable.insert(87, 1.374);
    lookupTable.insert(88, 1.337);
    lookupTable.insert(89, 1.302);
    lookupTable.insert(90, 1.267);
    lookupTable.insert(91, 1.234);
    lookupTable.insert(92, 1.201);
    lookupTable.insert(93, 1.17);
    lookupTable.insert(94, 1.139);
    lookupTable.insert(95, 1.11);
    lookupTable.insert(96, 1.081);
    lookupTable.insert(97, 1.054);
    lookupTable.insert(98, 1.027);
    lookupTable.insert(99, 1.001);
    lookupTable.insert(100, 0.975);
    lookupTable.insert(101, 0.951);
    lookupTable.insert(102, 0.927);
    lookupTable.insert(103, 0.904);
    lookupTable.insert(104, 0.881);
    lookupTable.insert(105, 0.86);
    lookupTable.insert(106, 0.838);
    lookupTable.insert(107, 0.818);
    lookupTable.insert(108, 0.798);
    lookupTable.insert(109, 0.779);
    lookupTable.insert(110, 0.76);
    lookupTable.insert(111, 0.742);
    lookupTable.insert(112, 0.724);
    lookupTable.insert(113, 0.707);
    lookupTable.insert(114, 0.69);
    lookupTable.insert(115, 0.674);
    lookupTable.insert(116, 0.658);
    lookupTable.insert(117, 0.643);
    lookupTable.insert(118, 0.628);
    lookupTable.insert(119, 0.613);
    lookupTable.insert(120, 0.599);
    lookupTable.insert(121, 0.585);
    lookupTable.insert(122, 0.572);
    lookupTable.insert(123, 0.559);
    lookupTable.insert(124, 0.546);
    lookupTable.insert(125, 0.534);





    storage::addPinData("pin4V_SW");
    storage::addPinData("pin3_3V_SW");
    storage::addPinData("pin5V_SW");
    storage::addPinData("pin12V");
    storage::addPinData("pin3_3V");
    storage::addPinData("pin4V");
    storage::addLedData("LED1");
    storage::addLedData("LED2");
    storage::addLedData("LED3");
    storage::addLedData("LED5");
    storage::addLedData("LED6");
    storage::addLedData("LED7");
    storage::addLedData("LED8");
    storage::addLedData("LED9");
    storage::addLedData("LED10");
    storage::addButtonData("BUTTON1");
    storage::addButtonData("BUTTON2");
    storage::setHALDesc("");
    storage::setZERODesc("");
    storage::setNFCDesc("");
    storage::setCANRX_OK(false);
    storage::setCANTX_OK(false);
    ui->nfc_textEdit->setVisible(false);
    ui->hal_textEdit->setVisible(false);
    ui->zero_textEdit_2->setVisible(true);
    ui->zero_textEdit->setVisible(false);
    ui->nfc_check_frame->setEnabled(false);
    ui->hal_check_frame->setEnabled(false);
    ui->zero_check_frame->setEnabled(false);
    ui->zero_check_frame_2->setEnabled(false);
    ui->led_check_frame->setEnabled(false);
    ui->can_frame->setEnabled(false);
    ui->pushButton_14->setEnabled(false);
    ui-> pushButton_3 -> setEnabled(false);
    ui->label_3->setStyleSheet("background-color: rgb(200,200,0)");

    ui -> zero_textEdit_2 -> setVisible(false);

    ui->Serial_line->setStyleSheet("background-color: rgb(219,114,114)");
    m_timer=new QTimer;
    connect(m_timer, &QTimer::timeout, this, &MainWindow::emitConstantSignal);
    m_timer->start(1000);
    connect(this, &MainWindow::constantSignal, this, &MainWindow::handleConstantSignal);


}

void MainWindow::openSerialPort(){

    m_serial = new QSerialPort;
#if defined(Q_OS_LINUX)
    m_serial->setPortName(m_ArduinoPort); //added variable from settings
#endif
#if defined(Q_OS_WIN)
    m_serial->setPortName(m_ArduinoPort);
#endif
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

    //qDebug()<<str;

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
        }else if(!str.contains("<") && !str.contains(">")){
            buffer.append(str);
            isFullBuffer=false;

        }
    }
    if(isFullBuffer){
        // qDebug()<<"Full buffer: "<<str;
        // //Debug purpose

    }


    if(isFullBuffer){

        // qDebug()<<"--------------------BUFFER IS FULL!!!!!!!!!!!-----------";
        QString temp=buffer;
        // qDebug()<<buffer;
        temp.replace("<","");
        temp.replace(">","");
        QStringList listOfValues =temp.split(",");

        if(listOfValues.size()==21){
            if(listOfValues.at(0)=="0"){
                //ui->check_pins_frame->setVisible(false);
                ui->check_pins_frame_2->setVisible(true);
                ui->check_pins_frame_2->setStyleSheet("background-color: rgb(200,0,0)");
                // ui->verticalLayout_2->setStretch(0,3);
                // ui->verticalLayout_2->setStretch(1,3);
                // ui->verticalLayout_2->setStretch(2,1);
                // ui->verticalLayout_2->setStretch(3,1);
                // ui->verticalLayout_2->setStretch(4,1);
                // ui->verticalLayout_2->setStretch(5,1);
                // ui->verticalLayout_2->setStretch(6,1);
                // ui->verticalLayout_2->setStretch(7,1);
                // ui->verticalLayout_2->setStretch(8,1);
            }else{
                //ui->check_pins_frame->setVisible(false);
                ui->check_pins_frame_2->setVisible(true);
                ui->check_pins_frame_2->setStyleSheet("background-color: rgb(0,200,0)");
                //ui->label_3->setText("PINS OK");
                // ui->verticalLayout_2->setStretch(0,1);
                // ui->verticalLayout_2->setStretch(1,1);
                // ui->verticalLayout_2->setStretch(2,1);
                // ui->verticalLayout_2->setStretch(3,1);
                // ui->verticalLayout_2->setStretch(4,1);
                // ui->verticalLayout_2->setStretch(5,1);
                // ui->verticalLayout_2->setStretch(6,1);
                // ui->verticalLayout_2->setStretch(7,1);
                // ui->verticalLayout_2->setStretch(8,1);
                //ui->check_pins_frame->setStyleSheet("background-color: rgb(0,200,0)");

            }

            float temp4VSW;
            temp4VSW = listOfValues.at(1).left(4).toFloat();
            temp4VSW = temp4VSW;

            QString temp4VSWString;
            temp4VSWString = QString::number(temp4VSW);
            temp4VSWString += "V";



            ui->label_pin4V_SW->setText(temp4VSWString);

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
            storage::setPinData("pin4V_SW", temp_bool, temp4VSW); // MYB WORK

            //process value so that 12V value * 11 5V value * 2

            float temp3VSW;
            temp3VSW = listOfValues.at(2).left(4).toFloat();
            temp3VSW = temp3VSW;

            QString temp3VSWString;
            temp3VSWString = QString::number(temp3VSW);
            temp3VSWString += "V";


            ui->label_pin3_3V_SW->setText(temp3VSWString); //pin3V_SW
            if(listOfValues.at(8)=="0"){
                temp_bool=false;
                ui->isOK_label_33VSW->setStyleSheet("");
            }else {
                ui->isOK_label_33VSW->setStyleSheet("background-color: rgb(0,150,0)");
                temp_bool=true;
            }


            storage::setPinData("pin3_3V_SW", temp_bool, temp3VSW);

            float temp5V;
            temp5V = listOfValues.at(3).left(4).toFloat();
            temp5V = (temp5V*2);

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

            storage::setPinData("pin5V_SW", temp_bool, temp5V); //need to add arduino

            float temp12V;
            // qDebug()<<"RAW FROM LIST:"<<listOfValues.at(4);
            temp12V = listOfValues.at(4).left(4).toFloat();
            temp12V = temp12V * 10.9; //10 or 11 I dont know, should be 11 I think, but lets put 10 for now
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

            float temp3V;
            temp3V = listOfValues.at(5).left(4).toFloat();
            temp3V = temp3V;

            QString temp3VString;
            temp3VString = QString::number(temp3V);
            temp3VString += "V";


            if(listOfValues.at(11) == '1'){
                storage::setPinData("pin3_3V", true,  temp3V);
                ui->label_pin3_3V->setText(temp3VString);
                ui->isOK_labelpin33V->setStyleSheet("background-color: rgb(0,150,0)");
            }else{

                storage::setPinData("pin3_3V", false, temp3V);
                ui->label_pin3_3V->setText(temp3VString);
                ui->isOK_labelpin33V->setStyleSheet("");
            }


            float temp4V;
            temp4V = listOfValues.at(6).left(4).toFloat();
            temp4V = temp4V;

            QString temp4VString;
            temp4VString = QString::number(temp4V);
            temp4VString += "V";


            if(listOfValues.at(12)=='1'){
                storage::setPinData("pin4V", true, temp4V);
                ui->label_pin4V->setText(temp4VString);
                ui->isOK_label_4V->setStyleSheet("background-color: rgb(0,150,0)");
            }else {
                storage::setPinData("pin4V", false, temp4V);
                ui->label_pin4V->setText(temp4VString);
                ui->isOK_label_4V->setStyleSheet("");

            }
//            ui->check_pins_frame_2->setStyleSheet("background-color: rgb(200,0,0)");

#if defined(Q_OS_LINUX)
            ui->button_frame->setStyleSheet("background-color: rgb(0,0,200)");
#endif
#if defined(Q_OS_WIN)
            ui->button_frame->setStyleSheet("background-color: rgb(163,188,227)");
#endif

            //JUST A TX CHECK
            if(listOfValues.at(13)!= "X"){
                storage::setCANTX_OK(true);
            }

            ui->button_counter_value_2 -> setStyleSheet("");
            ui->button_counter_value_3 -> setStyleSheet("");
            ui->button_counter_value_4 -> setStyleSheet("");
            //ui->last_button_value->setText(listOfValues.at(13)); //BUTTON
            if(listOfValues.at(13) == "4"){
                ui->button_counter_value->setText(listOfValues.at(14));
            }
            if(listOfValues.at(13) == "3"){
                ui->button_counter_value_2->setText(listOfValues.at(14));
            }
            if(listOfValues.at(13) == "2"){
                ui->button_counter_value_3->setText(listOfValues.at(14));
            }
            if(listOfValues.at(13) == "1"){
                ui->button_counter_value_4 -> setText(listOfValues.at(14));
            }


#if defined(Q_OS_LINUX)
            ui->nfc_frame->setStyleSheet("background-color: rgb(0,0,200)");
#endif
#if defined(Q_OS_WIN)
            ui->nfc_frame->setStyleSheet("background-color: rgb(163,188,227)");
#endif

            if(listOfValues.at(15)=="1"){//NFC
                storage::setCANTX_OK(true);

                ui->NFC_status->setText("DETECTED");
                ui->nfc_frame->setStyleSheet("background-color: rgb(0,200,0)");


                if(ui->NFC_status->text()=="DETECTED"){
                    ui->nfc_frame->setStyleSheet("background-color: rgb(0,200,0)");
                    QTimer::singleShot(2000,this,[this]() {//Might be problems here
                        ui->NFC_status->setText("WAITING");
                        ui->nfc_frame->setStyleSheet(""); //This is prob fine
                        //Green stays for 2 secs then we do this
                    });
                }

            }


#if defined(Q_OS_LINUX)
            ui->hal_frame->setStyleSheet("background-color: rgb(0,0,200)");
#endif
#if defined(Q_OS_WIN)
            ui->hal_frame->setStyleSheet("background-color: rgb(163,188,227)");
#endif

            int inDegrees = (int)(((float)(listOfValues.at(16).toInt()) / 4095.0)*360);

            QString joined = QString::number(inDegrees) + "° (" + listOfValues.at(16) + ")";

            ui->hal_value->setText(joined); //HAL


            if(listOfValues.at(17)=="1"){
                ui->zero_frame->setStyleSheet("background-color: rgb(0,200,0)");
            }else {
#if defined(Q_OS_LINUX)
                ui->zero_frame->setStyleSheet("background-color: rgb(0,0,200)");
#endif
#if defined(Q_OS_WIN)
                ui->zero_frame->setStyleSheet("background-color: rgb(163,188,227)");
#endif

            }
            ui->zero_value->setText(listOfValues.at(17));//ZERO

#if defined(Q_OS_LINUX)
            ui->t1_frame->setStyleSheet("background-color: rgb(0,0,200)");
#endif
#if defined(Q_OS_WIN)
            ui->t1_frame->setStyleSheet("background-color: rgb(163,188,227)");
#endif \
    //Value that needs to be processed is listOfValues.at(18) \
    //and then write it into the values \
    //here we lookup the table
            int rawVolt = listOfValues.at(18).toInt();

            float Voltage = ((float)rawVolt/4095.0) * 3.0;

            qDebug() << "This is the supposed Voltage: " << Voltage;



            double result = ((10000*Voltage)/(3.3 - Voltage)) /1000.0;
            qDebug() << "This is the supposed resistance: " << result;

            int TempForT1 = findClosestTemp(result);
            qDebug()<<"This is the supposed Temp: "<< TempForT1;

            QString toDisplayT1 = QString::number(TempForT1) + "°C (" + listOfValues.at(18) + ")";
            storage::setPA2Value(toDisplayT1.toStdString());
            ui->t1_value->setText(toDisplayT1); //T1

#if defined(Q_OS_LINUX)
            ui->t2_frame->setStyleSheet("background-color: rgb(0,0,200)");
#endif
#if defined(Q_OS_WIN)
            //ui->t2_frame->setStyleSheet("background-color: rgb(163,188,227)");
#endif

            double result2 = ((10000*Voltage)/(3.3 - Voltage)) /1000.0;
            // qDebug() << "This is the supposed resistance: " << result;

            int TempForT2 = findClosestTemp(result);
            //  qDebug()<<"This is the supposed Temp: "<< TempForT1;

            QString toDisplayT2 = QString::number(TempForT2) + "°C (" + listOfValues.at(19) + ")";
            storage::setPA3Value(toDisplayT2.toStdString());
            ui->t2_value->setText(toDisplayT2); //T2

            if(listOfValues.at(20) == "1"){
                ui->can_frame->setStyleSheet("background-color: rgb(0,200,0)");//Set it to green until we press the report button
                storage::setCANRX_OK(true);
                storage::setCANTX_OK(true);//Restart porgram after changing board
                //or we make a button refresh board oziroma next board
                //How do we seperate tx and rx
            }else {
                //ui->can_frame->setStyleSheet("");

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
    ui->nfc_check_frame->setEnabled(true);

    // ui->buttons_check_frame->setStyleSheet("background-color: rgb(200,0,0)");
    qDebug()<<"Are they OK";

    ui->buttons_check_frame->setStyleSheet("background-color: rgb(200,0,0)");
    if(myDialog->exec() == QDialog::Accepted){ // not work yet
        if(storage::areAllButtonsOK()){
            qDebug()<<storage::areAllButtonsOK();
            ui->buttons_check_frame->setStyleSheet("background-color: rgb(200,0,0)");
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
    //storage::setLedData("LED4", true, "");
    storage::setLedData("LED5", true, "");
    storage::setLedData("LED6", true, "");
    storage::setLedData("LED7", true, "");
    storage::setLedData("LED8", true, "");
    storage::setLedData("LED9", true, "");
    storage::setLedData("LED10", true, "");
    ui->can_frame->setEnabled(true);
    ui->zero_check_frame_2->setEnabled(true);
    if(!(ui -> Serial_line -> text().isEmpty())){
        ui->pushButton_14->setEnabled(true);
    }else{
        ui->pushButton_14->setEnabled(false);
    }

    ui->led_check_frame->setStyleSheet("background-color: rgb(0,200,0)");
}


void MainWindow::on_LED_NOK_clicked()
{
    DialogLED* myDialog = new DialogLED(this);
    myDialog->show();
    ui->zero_check_frame_2->setEnabled(true);
    ui->can_frame->setEnabled(true);

    if(!(ui -> Serial_line -> text().isEmpty())){
        ui->pushButton_14->setEnabled(true);
    }else{
        ui->pushButton_14->setEnabled(false);
    }

    //  ui->led_check_frame->setStyleSheet("background-color: rgb(200,0,0)");
    connect(myDialog, &DialogLED::triggerLEDs, this, &MainWindow::onTriggerLED);

    if(myDialog->exec() == QDialog::Accepted){
        if(storage::areAllLEDsOK()){
            ui->led_check_frame->setStyleSheet("background-color: rgb(0,200,0)");
            ui->can_frame->setEnabled(true);
            ui->pushButton_14->setEnabled(true);
        }else {
            ui->led_check_frame->setStyleSheet("background-color: rgb(200,0,0)");

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

    qDebug()<<"Current path: "<<QDir::currentPath();

    // ui->NFC_status->setText("X");
    // ui->nfc_frame->setStyleSheet("background-color: rgb(0,0,200)");
    // ui->buttons_check_frame->setStyleSheet("");
    // ui->nfc_check_frame->setStyleSheet("");
    // ui->hal_check_frame->setStyleSheet("");
    // ui->zero_check_frame->setStyleSheet("");
    // ui->zero_check_frame_2->setStyleSheet("");
    // ui->led_check_frame->setStyleSheet("");
    // ui->can_frame->setStyleSheet("");
    // ui->nfc_check_frame->setEnabled(false);
    // ui->hal_check_frame->setEnabled(false);
    // ui->zero_check_frame->setEnabled(false);
    // ui->led_check_frame->setEnabled(false);
    // ui->can_frame->setEnabled(false);
    // ui->can_frame->setStyleSheet("");
    // ui->zero_check_frame_2->setEnabled(false);

    // ui->zero_textEdit_2->setVisible(false);




    // QMessageBox * msgBox = new QMessageBox(QMessageBox::information,"Report status","Report created",this);


    //QMessageBox::information(this, "Report status", "Report created!");

    storage::setNFCDesc(ui->nfc_textEdit->toPlainText().toStdString());
    storage::setHALDesc(ui->hal_textEdit->toPlainText().toStdString());
    storage::setZERODesc(ui->zero_textEdit->toPlainText().toStdString());
    storage::setTEMPDesc(ui->zero_textEdit_2->toPlainText().toStdString());
    storage::setSERIAL(ui->Serial_line->text().toStdString());
    // storage::setDateTime(ui->dateTimeEdit->dateTime());
    storage::setEmployee(ui->comboBox->currentText().toStdString());
    storage::setNFCStatus(m_NFC_status);
    storage::setHALStatus(m_HAL_status);
    storage::setZEROStatus(m_ZERO_status);
    storage::setTEMPStatus(m_TEMP_status);
    qDebug()<<"Attempting cleaner report";
    //m_report->createReport();

    QString Serial, DateTime, Employee, pin4V_SW_isOK, pin4V_SW_value, pin3_3V_SW_isOK, pin3_3V_SW_value, pin5V_SW_isOK, pin5_SW_value, pin12V_isOK,pin12V_value, pin3_3V_isOK, pin3_3V_value, pin4V_isOK, pin4V_value;

    LedDataMap ledMapa=storage::getLedMap();
    Serial = QString::fromStdString(storage::getSERIAL());
    DateTime = storage::getDateTime().toString("dd.MM.yyyy hh:mm");
    Employee = QString::fromStdString(storage::getEmployee());
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

//Writting to file
#if defined(Q_OS_LINUX)
    QString filepath = "/home/jakob/SideMountGUI/";
    QString filename = "/home/jakob/SideMountGUI/Side_Mount_test.";
#endif

#if defined(Q_OS_WIN)
    QString filepath = "C:\\Users\\Uporabnik\\Documents\\Reports";
    QString filename = "C:\\Users\\Uporabnik\\Documents\\Reports\\Side_Mount_test.";
#endif

    QString temps;
    filename.append(storage::getSERIAL());
    QString nameToOverwrite;
    int index=1;

    QFileInfo fileInfo(filename);
    temps=filename;
    // while(fileInfo.exists(temps)){
    //     //FIRST CHECK IS NOT HERE THIS IS NOT EVEN USED
    //     qDebug()<<"FILE ALREADY EXISTS!!"; //first Check is here
    //     //Here we popup and decide Do we overrite file, add another copy, or change serial name



    //     qDebug()<<"Dialog closed";

    //     qDebug()<<"This is the storage variable: "<< storage::getMultipleFileDialogStatus();
    //     //Here we open the dialog and then

    //     qDebug()<<"Appending";
    //     temps.append(" (");
    //     temps.append(QString::number(index));
    //     temps.append(")");
    //     index++;
    // }

    temps.append(".txt");
    filename=temps;
    nameToOverwrite = temps;
    qDebug()<<"Filename: "<<filename;
    qDebug()<<"Temps: "<<filename;
    int indok=1;
    while(true){
        if(fileInfo.exists(temps) && storage::getMultipleFileDialogStatus() != 1 && storage::getMultipleFileDialogStatus() != 2){
            qDebug()<<"it already exists dont overwrite it"; //File already exists, send an alert that says
            //File already exists, change serial number?, overwrite it?, make a copy with a number at the end?
            //we can still make file just not save it
            if(indok == 1){
                multipleFilesDialog* myDialog = new multipleFilesDialog(this, "Confirm save");
                //myDialog->show();

                myDialog->setWindowFlags( ( (myDialog->windowFlags() | Qt::CustomizeWindowHint)
                                          & ~Qt::WindowCloseButtonHint) );
                myDialog->exec();

                //connect(myDialog, &Dialog::rejected, this, [](){
                //    qDebug()<<"REJECTED!!!!!!!!!!!!!";

                //});


                qDebug()<<"This is the number of status multipleFiles: "<<storage::getMultipleFileDialogStatus();

                qDebug()<<"Actual temps: "<<temps;
            }
            //so if the variable is 1, we should just close the dialog and let them change the SN


            if(storage::getMultipleFileDialogStatus() == 3){
                qDebug()<<"Adding number to not delete";
                if(temps[temps.length() -7] != '('){
                    temps.insert(temps.length() - 4, " (" + QString::number(indok) + ")");
                }else {
                    temps.replace(temps.length() -6,1, QString::number(indok));
                }
            }
        }else {
            break;

        }
        indok++;

    }
    filename=temps;

    if(storage::getMultipleFileDialogStatus() == 3 || storage::getMultipleFileDialogStatus() == 2 || storage::getMultipleFileDialogStatus() == 0){
        //Here we cleanup if its 2 3 or 0
        ui->NFC_status->setText("X");
        ui->nfc_frame->setStyleSheet("background-color: rgb(0,0,200)");
        ui->buttons_check_frame->setStyleSheet("");
        ui->nfc_check_frame->setStyleSheet("");
        ui->hal_check_frame->setStyleSheet("");
        ui->zero_check_frame->setStyleSheet("");
        ui->zero_check_frame_2->setStyleSheet("");
        ui->led_check_frame->setStyleSheet("");
        ui->can_frame->setStyleSheet("");
        ui->nfc_check_frame->setEnabled(false);
        ui->hal_check_frame->setEnabled(false);
        ui->zero_check_frame->setEnabled(false);
        ui->led_check_frame->setEnabled(false);
        ui->can_frame->setEnabled(false);
        ui->can_frame->setStyleSheet("");
        ui -> pushButton_14 -> setEnabled(false);
        ui->zero_check_frame_2->setEnabled(false);
        ui -> pushButton_14 -> setEnabled(false);
        ui->zero_textEdit_2->setVisible(false);


        QString filenameChosen;
        if(storage::getMultipleFileDialogStatus() == 3 || storage::getMultipleFileDialogStatus() == 0){
            filenameChosen = filename;
        }else if (storage::getMultipleFileDialogStatus() == 2){
            filenameChosen = nameToOverwrite;
        }

        QFile file(filenameChosen);
        qDebug()<<"This is the filenameChosen: " << filenameChosen;
        if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream stream(&file);
            //stream<<"--------------------------------------------------------\n";
            stream<<"SN:"<<Serial<<";";
            stream<<DateTime<<";";
            stream<<Employee;
            stream<<"\n";
            stream<<"Device;"<<"Status;"<<"Description\n";
            if(pin4V_SW_isOK=="NOT OK"){
                stream<<"pin4V_SW;"<<pin4V_SW_isOK<<";"<<pin4V_SW_value<<"\n";}
            else {
                stream<<"pin4V_SW;"<<pin4V_SW_isOK<<";"<<pin4V_SW_value<<"\n";}
            if(pin3_3V_SW_isOK=="NOT OK"){
                stream<<"pin3_3V_SW;"<<pin3_3V_SW_isOK<<";"<<pin3_3V_SW_value<<"\n";}
            else {
                stream<<"pin3_3V_SW;"<<pin3_3V_SW_isOK<<";"<<pin3_3V_SW_value<<"\n";}
            if(pin5V_SW_isOK=="NOT OK"){
                stream<<"pin5V_SW;"<<pin5V_SW_isOK<<";"<<pin5_SW_value<<"\n";
            }else  {
                stream<<"pin5V_SW;"<<pin5V_SW_isOK<<";"<<pin5_SW_value<<"\n";
            }
            if(pin12V_isOK=="NOT OK"){
                stream<<"pin12V;"<<pin12V_isOK<<";"<<pin12V_value<<"\n";
            }else  stream<<"pin12V;"<<pin12V_isOK<<";"<<pin12V_value<<"\n";
            if(pin3_3V_isOK=="NOT OK"){
                stream<<"pin3_3V;"<<pin3_3V_isOK<<";"<<pin3_3V_value<<"\n";
            }else  {
                stream<<"pin3_3V;"<<pin3_3V_isOK<<";"<<pin3_3V_value<<"\n";
            }
            if(pin4V_isOK=="NOT OK"){
                stream<<"pin4V;"<<pin4V_isOK<<";"<<pin4V_value<<"\n";
            }else  {
                stream<<"pin4V;"<<pin4V_isOK<<";"<<pin4V_value<<"\n";
            }


            stream<<"PA2temp;"<<QString::fromStdString(storage::getPA2Value())<<"\n";
            stream<<"PA3temp;"<<QString::fromStdString(storage::getPA3Value())<<"\n";

            if(storage::getButtonData("Button1").first){
                stream<<"BUTTON1,2"<<";OK\n";
            }else {
                stream<<"BUTTON1,2"<<";NOT OK;"<<QString::fromStdString(storage::getButtonData("Button1").second)<<"\n";

            }

            if(storage::getButtonData("Button2").first){
                stream<<"BUTTON3,4"<<";OK\n";
            }else {
                stream<<"BUTTON3,4"<<";NOT OK;>"<<QString::fromStdString(storage::getButtonData("Button2").second)<<"\n";
            }



            for(auto led=ledMapa.begin();led!=ledMapa.end(); ++led){
                qDebug()<<QString::fromStdString(led->first);
                if(led->first != "LED10"){
                    if(led->second.first){
                        stream<<QString::fromStdString(led->first)<<";OK\n";
                    }else {
                        stream<<QString::fromStdString(led->first)<<";NOT OK;"<<QString::fromStdString(led->second.second)<<"\n";

                    }

                }

            }

            if(ledMapa["LED10"].first){
                stream<<"LED10"<<";OK\n";
            }else{
                stream<<"LED10"<<";NOT OK;"<<QString::fromStdString(ledMapa["LED10"].second)<<"\n";
            }

            if(storage::getNFCStatus()){
                stream<<"NFC;OK\n";
            }else {
                stream<<"NFC;NOT OK;"<<QString::fromStdString(storage::getNFCDesc())<<"\n";
            }

            if(storage::getHALStatus()){
                stream<<"HAL;OK\n";

            }else {
                stream<<"HAL;NOT OK;"<<QString::fromStdString(storage::getHALDesc())<<"\n";;

            }

            if(storage::getZEROStatus()){
                stream<<"ZERO;OK\n";

            }else {
                stream<<"ZERO;NOT OK;"<<QString::fromStdString(storage::getZERODesc())<<"\n";

            }

            if(storage::getTEMPStatus()){
                stream<<"TEMP;OK\n";

            }else {

                stream<<"TEMP;NOT OK;"<<QString::fromStdString(storage::getTEMPDesc())<<"\n";
            }

            if(storage::getCANRX_OK()){
                stream<<"CANRX;OK\n";

            }else{
                stream<<"CANRX;NOT OK\n";

            }

            if(storage::getCANTX_OK()){
                stream<<"CANTX;OK\n";

            }else{
                stream<<"CANTX;NOT OK\n";
            }



        }

        file.close(); // we dont even the anything if the option is change SN

        QMessageBox msgBox; //This should actually be down where we create the report
        msgBox.setText("Report created"); //not on center of app
        //msgBox.setGeometry(500,500,msgBox.width(), msgBox.height());
        msgBox.setModal(false);
        msgBox.exec();
        qDebug()<<"Done good !";
    }

    storage::setMultipleFilesDialogStatus(0);
}


void MainWindow::on_pushButton_clicked() //upload test FW
{
    m_processOutput="";
    QString outp;
#if defined(Q_OS_LINUX)
    QString firmwarePath ="/home/jakob/Documents/SIDEMOUNTJIG/Sidemount/Debug/Sidemount.bin";
    QString programmerPath="/mnt/98BC1F34BC1F0BFE/STMprogrammer/Installation/bin/STM32_Programmer.sh";
#endif
#if defined(Q_OS_WIN) //We might need to get these files from a server or something
    QString firmwarePath ="C:\\Users\\Uporabnik\\Documents\\SidemountJigSoftware\\Sidemount.bin"; //Need to fill this in
    QString programmerPath="C:\\Program Files\\STMicroelectronics\\STM32Cube\\STM32CubeProgrammer\\bin\\STM32_Programmer_CLI.exe";
#endif

    QStringList arguments;
    arguments << "-c" << "port=SWD";
    arguments << "-d" << firmwarePath << "0x08000000 ";;
    m_processSideMount->setProgram(programmerPath);
    m_processSideMount->setArguments(arguments);
    m_processSideMount->start();
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui -> status_label -> setStyleSheet("background-color: rgb(255,255,0)");
    ui -> status_label -> setText("Uploading sidemount firmware");

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
        ui -> status_label -> setStyleSheet("background-color: rgb(0,200,0)");
        ui->status_label->setText("Uploaded sidemount firmware");
        // m_processOutput = m_processSideMount->readAllStandardOutput();
        qDebug()<<"______START_OF_STRING___________";
        qDebug()<<m_processOutput;

        if(m_processOutput.contains("Error:")){
            qDebug()<<"Error detected this is the error:";
            QString error;
            error= m_processOutput.mid(m_processOutput.indexOf("Error:")+6,35); // sending error, try up to \n
            ui -> status_label -> setStyleSheet("background-color: rgb(200,0,0)");
            ui-> status_label->setText("Error in uploading: " + error); // do the same for bootloader
        }
        //outp=QString::fromUtf8(output);
        //qDebug()<<outp;

    });

}


void MainWindow::on_pushButton_2_clicked() //upload bootloader
{

#if defined(Q_OS_WIN)
    QString firmwarePath=m_BootloaderPath; //changed to variable
    QString programmerPath="C:\\Program Files\\STMicroelectronics\\STM32Cube\\STM32CubeProgrammer\\bin\\STM32_Programmer_CLI.exe";;
#endif

#if defined(Q_OS_LINUX)
    QString firmwarePath=m_BootloaderPath; //changed to variable
    QString programmerPath="/mnt/98BC1F34BC1F0BFE/STMprogrammer/Installation/bin/STM32_Programmer.sh";
#endif

    m_processOutput="";
    QProcess process;

    QStringList arguments;
    arguments << "-c" << "port=SWD";
    arguments << "-d" << firmwarePath << "0x08000000 ";
    m_processBootLoader->setProgram(programmerPath);
    m_processBootLoader->setArguments(arguments);
    m_processBootLoader->start();
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui -> status_label -> setStyleSheet("background-color: rgb(255,255,0)");
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
        ui -> status_label -> setStyleSheet("background-color: rgb(0,200,0)");
        if(m_processOutput.contains("Error:")){
            qDebug()<<"Error detected this is the error:";
            QString error;
            error= m_processOutput.mid(m_processOutput.indexOf("Error:")+6,35); // sending error, try up to \n
            ui-> status_label->setText("Error in uploading: " + error); // do the same for bootloader
            ui -> status_label -> setStyleSheet("background-color: rgb(200,0,0)");
        }else {


        }

    });

}


void MainWindow::on_settings_button_clicked()
{
    settingsDialog* settDialog = new settingsDialog(this);
    //closeSerialPort();
    if(settDialog->exec() == QDialog::Accepted){
        closeSerialPort();
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


void MainWindow::on_ZERO_OK_2_clicked()
{
    m_TEMP_status = true;
    ui->zero_check_frame_2->setStyleSheet("background-color: rgb(0,200,0)");
    ui->zero_textEdit_2->setVisible(false);
    //ui->led_check_frame->setEnabled(true);
}


void MainWindow::on_ZERO_NOK_2_clicked()
{
    m_TEMP_status = false;
    ui->zero_check_frame_2->setStyleSheet("background-color: rgb(200,0,0)");



    ui->zero_textEdit_2->setVisible(true);
}

int MainWindow::findClosestTemp(double target)
{

    int closestKey = 0;
    double minDiff = std::numeric_limits<double>::max();

    // Iterate through the map
    for (auto it = lookupTable.begin(); it != lookupTable.end(); ++it) {
        // Calculate the difference between the target and current value
        double diff = std::abs(it.value() - target);

        // Update closest key if we found a closer value
        if (diff < minDiff) {
            minDiff = diff;
            closestKey = it.key();
        }
    }

    // Return the key corresponding to the closest value
    return closestKey;

}



void MainWindow::on_Serial_line_editingFinished()
{
    qDebug()<<"Editing finished";
}


void MainWindow::on_Serial_line_textEdited(const QString &arg1)
{
    m_currentSN = arg1;
    qDebug()<<m_currentSN;
    if(m_currentSN.isEmpty()){
        ui->pushButton_14->setEnabled(false);
        ui->label_3->setVisible(true);
    }else {
        if(ui -> zero_check_frame -> isEnabled()){ //Only if Report is ready to be reported
            ui->pushButton_14->setEnabled(true);
        }
        ui->label_3->setVisible(false);
    }
}


void MainWindow::on_Serial_line_textChanged(const QString &arg1)
{

}


void MainWindow::on_pushButton_4_clicked()
{

    ui->NFC_status->setText("X");
    ui->nfc_frame->setStyleSheet("background-color: rgb(0,0,200)");
    ui->buttons_check_frame->setStyleSheet("");
    ui->nfc_check_frame->setStyleSheet("");
    ui->hal_check_frame->setStyleSheet("");
    ui->zero_check_frame->setStyleSheet("");
    ui->zero_check_frame_2->setStyleSheet("");
    ui->led_check_frame->setStyleSheet("");
    ui->can_frame->setStyleSheet("");
    ui->nfc_check_frame->setEnabled(false);
    ui->hal_check_frame->setEnabled(false);
    ui->zero_check_frame->setEnabled(false);
    ui->led_check_frame->setEnabled(false);
    ui->can_frame->setEnabled(false);
    ui->can_frame->setStyleSheet("");
    ui->zero_check_frame_2->setEnabled(false);
    ui -> pushButton_14 -> setEnabled(false);
    ui->zero_textEdit_2->setVisible(false);

}

