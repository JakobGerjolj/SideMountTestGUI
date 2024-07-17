#include "report.h"

Report::Report() {}

void Report::createReport()
{

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

    int index=1;

    QFileInfo fileInfo(filename);
    temps=filename;
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
    qDebug()<<"Filename: "<<filename;
    qDebug()<<"Temps"<<filename;
    int indok=1;
    while(true){
        if(fileInfo.exists(temps)){
            qDebug()<<"it already exists dont overwrite it";
            qDebug()<<"Adding number to not delete";
            if(temps[temps.length() -7] != '('){
                temps.insert(temps.length() - 4, " (" + QString::number(indok) + ")");
            }else {
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
        stream<<"SN:"<<Serial<<">";
        stream<<DateTime<<">";
        stream<<Employee;
        stream<<"\n";
        stream<<"Device>"<<"Status>"<<"Description\n";
        if(pin4V_SW_isOK=="NOT OK"){
            stream<<"pin4V_SW>"<<pin4V_SW_isOK<<">"<<pin4V_SW_value<<"\n";}
        else {
            stream<<"pin4V_SW>"<<pin4V_SW_isOK<<">"<<pin4V_SW_value<<"\n";}
        if(pin3_3V_SW_isOK=="NOT OK"){
            stream<<"pin3_3V_SW>"<<pin3_3V_SW_isOK<<">"<<pin3_3V_SW_value<<"\n";}
        else {
            stream<<"pin3_3V_SW>"<<pin3_3V_SW_isOK<<">"<<pin3_3V_SW_value<<"\n";}
        if(pin5V_SW_isOK=="NOT OK"){
            stream<<"pin5V_SW>"<<pin5V_SW_isOK<<">"<<pin5_SW_value<<"\n";
        }else  {
            stream<<"pin5V_SW>"<<pin5V_SW_isOK<<">"<<pin5_SW_value<<"\n";
        }
        if(pin12V_isOK=="NOT OK"){
            stream<<"pin12V>"<<pin12V_isOK<<">"<<pin12V_value<<"\n";
        }else  stream<<"pin12V>"<<pin12V_isOK<<">"<<pin12V_value<<"\n";
        if(pin3_3V_isOK=="NOT OK"){
            stream<<"pin3_3V>"<<pin3_3V_isOK<<">"<<pin3_3V_value<<"\n";
        }else  {
            stream<<"pin3_3V>"<<pin3_3V_isOK<<">"<<pin3_3V_value<<"\n";
        }
        if(pin4V_isOK=="NOT OK"){
            stream<<"pin4V>"<<pin4V_isOK<<">"<<pin4V_value<<"\n";
        }else  {
            stream<<"pin4V>"<<pin4V_isOK<<">"<<pin4V_value<<"\n";
        }





        if(storage::getButtonData("Button1").first){
            stream<<"BUTTON1,2"<<">OK\n";
        }else {
            stream<<"BUTTON1,2"<<">NOT OK>"<<QString::fromStdString(storage::getButtonData("Button1").second)<<"\n";

        }

        if(storage::getButtonData("Button2").first){
            stream<<"BUTTON3,4"<<">OK\n";
        }else {
            stream<<"BUTTON3,4"<<">NOT OK>"<<QString::fromStdString(storage::getButtonData("Button2").second)<<"\n";
        }



        for(auto led=ledMapa.begin();led!=ledMapa.end(); ++led){

            if(led->second.first){
                stream<<QString::fromStdString(led->first)<<">OK\n";
            }else {
                stream<<QString::fromStdString(led->first)<<">NOT OK>"<<QString::fromStdString(led->second.second)<<"\n";

            }

        }

        if(storage::getNFCStatus()){
            stream<<"NFC>OK\n";
        }else {
            stream<<"NFC>NOT OK>"<<QString::fromStdString(storage::getNFCDesc())<<"\n";
        }

        if(storage::getHALStatus()){
            stream<<"HAL>OK\n";

        }else {
            stream<<"HAL>NOT OK>"<<QString::fromStdString(storage::getHALDesc())<<"\n";;

        }

        if(storage::getZEROStatus()){
            stream<<"ZERO>OK\n";

        }else {
            stream<<"ZERO>NOT OK>"<<QString::fromStdString(storage::getZERODesc())<<"\n";

        }

        if(storage::getTEMPStatus()){
            stream<<"TEMP>OK\n";

        }else {

            stream<<"TEMP>NOT OK>"<<QString::fromStdString(storage::getTEMPDesc())<<"\n";
        }

        if(storage::getCANRX_OK()){
            stream<<"CANRX>OK\n";

        }else{
            stream<<"CANRX>NOT OK\n";

        }

        if(storage::getCANTX_OK()){
            stream<<"CANTX>OK\n";

        }else{
            stream<<"CANTX>NOT OK\n";
        }



    }

    file.close();
    qDebug()<<"Done good !";
}
